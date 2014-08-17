var gulp = require('gulp')
  , bower = require('gulp-bower')
  , browserify = require('gulp-browserify')
  , compass = require('gulp-compass')
  , csso = require('gulp-csso')
  , plumber = require('gulp-plumber')
  , rename = require('gulp-rename')
  , uglify = require('gulp-uglify');

gulp.task('bower', function () {
  return bower()
    .pipe(gulp.dest('./libraries/'));
});

gulp.task('browserify', ['bower'], function () {
  gulp.src('./js-src/the-ark.js')
    .pipe(plumber())
    .pipe(browserify())
    .pipe(gulp.dest('./js/'))
    .pipe(rename(function (path) { path.basename += '.min'; }))
    .pipe(uglify({ outSourceMap: true }))
    .pipe(gulp.dest('./js/'));
});

gulp.task('compass', ['bower'], function () {
  gulp.src('./sass/*.scss')
    .pipe(plumber())
    .pipe(compass({ environment: 'production' }))
    .pipe(gulp.dest('./css/'))
    .pipe(rename(function (path) { path.basename += '.min'; }))
    .pipe(csso())
    .pipe(gulp.dest('./css/'));
});

gulp.task('watch', function () {
  gulp.watch(['./js-src/*.js', './js-src/**/*.js'], ['browserify']);
  gulp.watch(['./sass/*.scss', './sass/**/*.scss'], ['compass']);
});

gulp.task('default', ['bower', 'browserify', 'compass']);
