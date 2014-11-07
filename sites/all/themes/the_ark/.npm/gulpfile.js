var gulp = require('gulp');

require('./.gulp/bower'); //  task(s):  bower
require('./.gulp/css');   //  task(s):  css, css-install
require('./.gulp/js');    //  task(s):  js, js-install

gulp.task('watch', function () {
  gulp.watch(['./bower.json'], ['bower']);
  gulp.watch(['./js-src/*.js', './js-src/**/*.js'], ['js']);
  gulp.watch(['./sass/*.scss', './sass/**/*.scss'], ['css']);
});

gulp.task('default', ['css', 'js']);
gulp.task('install', ['bower', 'css-install', 'js-install']);
