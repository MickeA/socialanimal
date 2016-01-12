// ///////////////////////////////
// Settings
// ///////////////////////////////
var sassFile = './scss/main.scss';
var filesToWatch = ['./scss/**/*.scss'];
var destFolder = './dist/css';
var browserSupport = ['last 2 versions', 'ie >= 9'];
var base64EncodeFileTypes = ['svg'];
var pathToEditor = '/Applications/Sublime\ Text.app/Contents/MacOS/Sublime\ Text';

// ///////////////////////////////
// Requirements
// ///////////////////////////////
var gulp = gulp || require('gulp');
var gutil = gutil || require('gulp-util');
var sass = require('gulp-sass');
var cssGlobbing = require('gulp-css-globbing');
var sourcemaps = require('gulp-sourcemaps');
var autoprefixer = require('gulp-autoprefixer');
var gulpif = require('gulp-if');
var argv = require('yargs').argv;
var size = require('gulp-size');
var cssMinify = require('gulp-minify-css');
var del = require('del');
var notifier = require('node-notifier');
var cssBase64 = require('gulp-base64');
var path = require('path');
var exec = require('child_process').exec;

Date.prototype.timeNow = function() {
  'use strict';
  return ((this.getHours() < 10) ? '0' : '') + this.getHours() + ':' + ((this.getMinutes() < 10) ? '0' : '' ) + this.getMinutes() + ':' + ((this.getSeconds() < 10) ? '0' : '') + this.getSeconds();
};

var browserSync;
exports.bs = function(bs) {
  'use strict';
  browserSync = bs;
};

// ///////////////////////////////
// Tasks
// * css-watch
// * css-clean
// * css-compile
// ///////////////////////////////
gulp.task('css-watch', function() {
  'use strict';
  gulp.watch(filesToWatch, ['css-compile']);
});

gulp.task('css-clean', function(cb) {
  'use strict';
  del([destFolder])
    .then(function(paths) {
      if (paths.length) {
        gutil.log(
          gutil.colors.yellow('Deleted CSS folder:\n'),
          gutil.colors.gray(paths.join('\n'))
        );
      } else {
        gutil.log(gutil.colors.yellow('No CSS folder to delete...'));
      }
      cb();
    });
});

gulp.task('css-compile', ['css-clean'], function() {
  'use strict';
  var errorInCompilation = false;
  var fileSize = size({
    showFiles: true
  });
  return gulp.src(sassFile)
    .pipe(sourcemaps.init())
      .pipe(cssGlobbing({
        extensions: ['.scss']
      }))
      .pipe(sass())
        .on('error', function(event) {
          var message = path.basename(event.file) + ' on line ' + event.line + ':' + event.column;
          errorInCompilation = true;

          notifier.notify({
            title: 'SCSS Error! @ ' + ((new Date()).timeNow()),
            message: message,
            icon: 'gulpfile.js/css/css-error.png'
          });

          gutil.log(gutil.colors.red('SCSS Error in ' + message));

          exec(pathToEditor + ' ' + event.file + ' --line ' + event.line);
          this.emit('end');
        })
      .pipe(autoprefixer({
        browsers: browserSupport,
        cascade: false
      }))
      .pipe(gulpif(argv.prod, cssMinify()))
      .pipe(gulpif(argv.prod, cssBase64({
        baseDir: destFolder,
        extensions: base64EncodeFileTypes
      })))
      .pipe(fileSize)
    .pipe(sourcemaps.write('./'))
    .pipe(gulp.dest( destFolder ))
    .pipe(browserSync.stream({match: '**/*.css'}))
    .on('error', gutil.log)
    .on('end', function() {
      if (!errorInCompilation) {
        notifier.notify({
          title: 'CSS Compiled @ ' + ((new Date()).timeNow()),
          message: fileSize.prettySize,
          icon: 'gulpfile.js/css/css.png'
        });

        gutil.log(gutil.colors.green('CSS Compiled.'));
      }
    });
});
