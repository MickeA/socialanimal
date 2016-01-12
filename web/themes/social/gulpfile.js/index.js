/////////////////////////////////
// Settings
/////////////////////////////////
var websiteUrl = 'socialanimal.dev';

/////////////////////////////////
// Requirements
/////////////////////////////////
var gulp = require('gulp');
var gutil = require('gulp-util');
var browserSync = require('browser-sync').create();

require('./js/js.js').bs(browserSync);;
require('./css/css.js').bs(browserSync);
//require('./svg/svg.js');

/////////////////////////////////
// Tasks
// * watch
// * clean
// * compile
// * default
/////////////////////////////////
gulp.task('watch', ['css-watch', 'js-compile']);
gulp.task('clean', ['js-clean', 'css-clean']);
gulp.task('compile', ['css-compile', 'js-compile']);

gulp.task('default', ['compile', 'watch'], function(){
  "use strict";

  browserSync.init({
    proxy: websiteUrl,
    open: false,
  });

  gutil.log(gutil.colors.green('Done compiling! Now watching...'));
});
