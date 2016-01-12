# Social Animal (Drupal 8 theme)

##Front end/design



##Javascript info


###Big thanks to [Jonathan](https://github.com/jonathangus) (a.k.a Dr. Bench press) for the doc below and gulpfile :fire:
![Excited](http://www.reactiongifs.com/r/zfb.gif)

##Table of contents

* [Theming tools](#Theming tools to install)
* [Frontend stack](#Frontend stack)


### Theming tools to install
You'll need [Node JS](http://nodejs.org/)(0.12.0).

#### Install right version of node
``nvm install 0.12.0``

#### Set nvm alias default to point to the newly downloaded version of node.
``nvm alias default 0.12.0``

#### To see what verison of npm that now is set to run you can check by:
``nvm current``

### After every ./build do the following 
#### Use Node to fetch all tools.
``npm install``

You might need to run:  
``npm install gulp-sass -g``  
``npm install gulp -g``

#### Command to use gulp.
``gulp compile``  
``gulp``

Browsersync available @ localhost:3000

<a name="Frontend stack"></a>
### Frontend stack
[Susy](https://github.com/ericam/susy)
[Breakpoint](https://github.com/at-import/breakpoint)
[Babel](https://babeljs.io/)
[Libsass](https://github.com/sass/libsass)
[Browsersync](http://www.browsersync.io/)

