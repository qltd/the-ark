var gulp = require('gulp')
  , browserify = require('browserify')
  , buffer = require('vinyl-buffer')
  , notify = require('gulp-notify')
  , plumber = require('gulp-plumber')
  , rename = require('gulp-rename')
  , source = require('vinyl-source-stream')
  , sourcemaps = require('gulp-sourcemaps')
  , uglify = require('gulp-uglify');

function bundle (bundler, name) {
  return bundler
    .bundle()
    .pipe(plumber())
    .pipe(source(name))
    .pipe(buffer())
    .pipe(gulp.dest('./js/'))
    .pipe(rename(function (path) { path.basename += '.min'; }))
    .pipe(sourcemaps.init({ loadMaps: true }))
      .pipe(uglify())
    .pipe(sourcemaps.write('./'))
    .pipe(gulp.dest('./js/'))
    .pipe(notify('JS was successfully compiled.'));
}

function js (name) {
  var bundler = browserify({
    entries: ['./js-src/' + name],
    debug: true
  });
  return bundle(bundler, name);
}

function jsMain () {
  return js('the-ark-admin.js');
}
function jsAll () {
  jsMain();
}

gulp.task('js', jsAll);
gulp.task('js-main', jsMain);
gulp.task('js-install', ['bower'], jsAll);
