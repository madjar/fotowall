FotoWall
========

FotoWall is a creative tool that allows you to layout your photos or pictures in a personal way. You can add pictures, then resize, move, change colors, text, shadows, etc..
For more news: http://code.google.com/p/fotowall

*Focus is on simplicity, express your creativity! ;-)*


Sharing Ideas
-------------

I hope to expand the program as soon as I can, since there is many room for improvement and the code is kept clean and small.

- You can join the development.. the whole stuff is done with Qt 4.5 using the
  GraphicsView framework.
- And if you have any Idea or Suggestion, just drop me a line, on the project
  homepage or by mail at  enrico.ros@gmail.com ;-)

### Current Wishlist

This is the current list of requested features. If you have more of them, or any other idea, just press the "Issues" button and add your entry!! ;-)

Special requests:

* checkbox for a "beginner mode" (Alberto Scarpa)

Newest:

* add effects to photos
* place the title anywhere
* display on-screen selection for pictures
* perform rectangular image composition based on an input picture (color, pattern)
* perform image distribution based on shapes or probability sampling (on a sprayed grayscale canvas)
* add an overlay html help when going on the lower-left corner
* make reflections (dunno where.. just make them :D)

Suggested by Contrast on kde-look's page:

* add an "add image" dialog (have a quick way of adding photos)
* rotate the pictures on their z-axis
* add the "color changing stuff" to the picture themselves
* set a background picture (push a button and the picture goes into background in place of the gradient!)

Suggested by Superstoned on kde-look's page:

* document the scroll-wheel
* change the color of the photos (middle colors changer?)
* color changers: it'd be good if it was easier to find them (maybe just use buttons?). animations are cool, thoug...

Suggested by TeeAhr1 on kde-look's page:

* custom fonts


Building
--------

This FotoWall packages provides source code; to make an executable out of the
sources you have to know a little about programming or ask one of your friends
to do it ;-) Or just grab an 'executable package' from the project homepage.

In Linux/X11, Mac, or Windows, install the latest Qt development packages that
you will find on http://www.trolltech.com:

- on linux this is tested with Qt 4.4 and GCC 4.0+
- on windows this is tested witn Qt 4.4 and MSVC Express 2005 and 2008
- on mac this was not tested, report me if it simply works out of the box ;-)

Just open a command prompt (win), shell (linux, mac) and go the sources
location and issue the followings commands:

   qmake
   make   (or nmake, if you're on windows)

The executable will be build and you can start Enjoying FotoWall! ;-)


### Notes for the Windows Download

You must have the Microsoft Visual Studio 2008 Redistributable package (1.7MB) installed in your system, otherwise you will get an error. Click here for downloading the file


ChangeLog
---------

Unreleased Version; New Stuff:

* Reflections are coming...
* More Frame types (default, heart, Plasma backgrounds) [David Eccher]
* More Image Formats (bmp, tiff, gif, ...) [Superstoned]
* Mirror the photo by clicking on an axis [Alberto Scarpa]
* DoubleClick on a picture -> set it as background, and vice-versa [Alberto Scarpa]
* More pretty (plasma icons) and usable (behavior) frame buttons
* New buttons: "Raise to Front" [Superstoned], "Delete"
* Fixed-ratio resize: hold CTRL while resizing
* Drag&Drop: better behavior and can change a picture inside an existing frame too
* Pictures stay on-screen


News
----

**2009-03-02** FotoWall is now on GitHub. Development will continue here. Changes are coming soon!

**2008-09-03** Peter Upfold put together a great ScreenCast of the application!!

See http://fosswire.com/2008/09/03/fotowall-make-wallpaper-collages-from-your-photos/ fot the article and click on the Video link to see the screencast.

**2008-08-01** Thanks to everybody that is sending me patches!

I really appreciate that, even if I don't have time right now to check and apply them.. but I'm willing to give everybody the SVN access, so drop me a note if you want to contribute!

**2008-04-14** Updated this page including the Wishlist

**2008-04-06** FotoWall 0.21 released

Changes in this release are: relicensing and a new program icon

**2008-04-06** Imported the project into Google Code
