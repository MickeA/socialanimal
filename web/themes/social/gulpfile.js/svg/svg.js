var gulp      = require('gulp'),
    q         = require('q'),
    path      = require('path'),
    fs        = require('fs'),
    Grunticon = require('grunticon-lib');

var filesToWatch = './images/svg/*.svg';

gulp.task('svg-compile', function () {
  var deferred = q.defer(),
      iconDir = './images/svg/',
      options = { 
        enhanceSVG: true,
        datasvgcss: "_icons-svg.scss",
        datapngcss: "_icons-png.not-in-use",
        urlpngcss: "_icons-fallback.not-in-use",
        cssprefix: '%icons-',
        pngpath: '../../dist/png',
      };

  var files = fs.readdirSync(iconDir).map(function (fileName) {
    return path.join(iconDir, fileName);
  });

  var grunticon = new Grunticon(files, './scss/icons/', options);

  grunticon.process(function () {
    deferred.resolve();
  });

  return deferred.promise;
});

gulp.task('svg-watch', function() {
  gulp.watch(filesToWatch, ['svg-compile', 'css-compile']);
});