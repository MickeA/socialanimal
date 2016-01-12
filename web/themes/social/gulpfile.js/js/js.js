// ///////////////////////////////
// Settings
// ///////////////////////////////
var sourceFile = './js/main.js';
var destFolder = './dist/js';
var outputFileName = 'main.js';

// ///////////////////////////////
// Requirements
// ///////////////////////////////
var gulp = gulp || require('gulp');
var gutil = gutil || require('gulp-util');
var sourcemaps = require('gulp-sourcemaps');
var uglify = require('gulp-uglify');
var size = require('gulp-size');
var del = require('del');
var notifier = require('node-notifier');
var concat = require('gulp-concat');
var gulpif = require('gulp-if');
var argv = require('yargs').argv;
var eslint = require('gulp-eslint');
var browserify = require('browserify');
var watchify = require('watchify');
var buffer = require('vinyl-buffer');
var source = require('vinyl-source-stream');
var babel = require('babelify');
var browserSync;

Date.prototype.timeNow = function() {
  'use strict';
  return ((this.getHours() < 10) ? '0' : '') + this.getHours() + ':' + ((this.getMinutes() < 10) ? '0' : '' ) + this.getMinutes() + ':' + ((this.getSeconds() < 10) ? '0' : '') + this.getSeconds();
};

exports.bs = function(bs) {
  'use strict';
  browserSync = bs;
};

// ///////////////////////////////
// Tasks
// * js-clean
// * js-compile
// ///////////////////////////////

var bundler = watchify(browserify({
  entries: sourceFile,
  debug: true,
  cache: {},
  packageCache: {},
  paths: ['./utils', './modules', './partials'],
  fullPaths: true,
  transform: babel
}));

// This is for stopping watchify when just compiling.
if (argv['_'].indexOf('compile') !== -1) {
  bundler.on('time', function(){
    "use strict";
    bundler.close();
  });
}

bundler.on('update', rebundle);

// For the time now
Date.prototype.timeNow = function () {
  return ((this.getHours() < 10)?"0":"") + this.getHours() +":"+ ((this.getMinutes() < 10)?"0":"") + this.getMinutes() +":"+ ((this.getSeconds() < 10)?"0":"") + this.getSeconds();
};

// Settings for gulp-size
var sizeSettings = {
  showFiles: true
};

function rebundle() {
  var s = size(sizeSettings);
  var errorInCompilation = false;

  return bundler.bundle()
    .on('error', function(err, a, d){
      var message = err.toString();
      errorInCompilation = true;

      notifier.notify({
        title: 'JS Error! @ ' + ((new Date()).timeNow()),
        message: message,
          icon: 'gulpfile.js/js-error.png'
      });

      gutil.log(gutil.colors.red('JS Error in ' + message));
      this.emit('end');
    })
    .pipe(source(outputFileName))
    .pipe(buffer())
    .pipe(sourcemaps.init({loadMaps: true}))
    .pipe(gulpif(argv.prod, uglify()))
    .pipe(sourcemaps.write('./'))
    .pipe(s)
    .pipe(gulp.dest(destFolder))
    .on('error', gutil.log)
    .on('end', function() {
      if(!errorInCompilation){
        notifier.notify({
          title: 'JS Compiled @ ' + ((new Date()).timeNow()),
          message: s.prettySize,
          icon: 'gulpfile.js/js.png'
        });

        gutil.log(gutil.colors.green('JS Compiled.'));
        browserSync.reload();
      }
    });
}

gulp.task('js-clean', function(cb) {
  'use strict';
  del([destFolder + '/**/*.js', destFolder + '/**/*.js.map'])
    .then(function(paths) {
      if (paths.length) {
        gutil.log(
          gutil.colors.yellow('Deleted JS files:\n'),
          gutil.colors.gray(paths.join('\n'))
        );
      } else {
        gutil.log(gutil.colors.yellow('No JS to delete...'));
      }
      cb();
    });
});

gulp.task('js-compile', rebundle);
