
( )                   _     ( )
| |     _   _    ___ (_)   _| |
| |  _ ( ) ( ) /'___)| | /'_` |
| |_( )| (_) |( (___ | |( (_| |
(____/'`\___/'`\____)(_)`\__,_)

 - A new approach to theming -

   ### Vision ###

With Lucid we wanted to try out a new approach to Drupal theming. Instead of
going the classic route, and use an existing base theme with a custom theme
on top, we went ahead and merged the two. The point of Lucid is to work
as both your base theme and your actual custom theme.

One of Lucid's goals was to clean up markup and classes that we never use, as
well as turning the markup we leave in there into HTML5. It also comes
shipped with proper grid css which is prepared to work as an adaptive theme.

The current width break points are:
 < 960 px
 < 768 px
 < 480 px

  ### Usage ###

As said, Lucid should not be used as a base theme. Instead, look at Lucid as
the starting point of your custom theme. After installation, go nuts and remove
the bits that you don't like, and add your own favorite tricks for making your
theme awesome.

"But hey, then I can't update Lucid when a new release is avalible?"

Well, you can, but you shouldn't. We have thought about this and while an
upgrade path for modules is needed we believe that it's not really necessary
for themes.

  ### Panels & NodeStream ###

Lucid is specifically adjusted to work with sites built on panels and panels
everywhere. On top of that we are also adjusting it to work great with the
NodeStream (http://drupal.org/project/nodestream) installation profile.

  ### Credits ###

Maintainers:

mattiasj      http://drupal.org/user/358006
Snipon        http://drupal.org/user/439380
BJ___         http://drupal.org/user/365162
heyintern     http://drupal.org/user/1013344
fabsor	      http://drupal.org/user/255704

Inspiration from other projects:

http://drupal.org/project/adaptivetheme
http://drupal.org/project/basic
http://drupal.org/project/boron
http://drupal.org/project/zentropy
http://html5boilerplate.com/
http://necolas.github.com/normalize.css/
