var gulp = require('gulp')
  , browserify = require('gulp-browserify')
  , compass = require('gulp-compass')
  , csso = require('gulp-csso')
  , plumber = require('gulp-plumber')
  , rename = require('gulp-rename')
  , uglify = require('gulp-uglify');


gulp.task('browserify', function () {
  gulp.src('./js-src/*.js')
    .pipe(plumber())
    .pipe(browserify())
    .pipe(gulp.dest('./js/'))
    .pipe(rename(function (path) { path.basename += '.min'; }))
    .pipe(uglify({ outSourceMap: true }))
    .pipe(gulp.dest('./js/'));
});

gulp.task('compass', function () {
  gulp.src('./sass/*.scss')
    .pipe(plumber())
    .pipe(compass({
      config_file: './config.rb',
      css: 'css',
      environment: 'production',
      sass: 'sass',
      sourcemap: true
    }))
    .pipe(gulp.dest('./css/'))
    .pipe(rename(function (path) { path.basename += '.min'; }))
    .pipe(csso())
    .pipe(gulp.dest('./css/'));
});

gulp.task('watch', function () {
  gulp.watch(['./js-src/*.js', './js-src/**/*.js'], ['browserify']);
  gulp.watch(['./sass/*.scss', './sass/**/*.scss'], ['compass']);
});

gulp.task('default', ['browserify', 'compass']);
