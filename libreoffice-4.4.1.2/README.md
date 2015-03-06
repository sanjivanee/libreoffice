This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

* A quick overview of the LibreOffice code structure.

** Overview

    You can develop for LibreOffice in one of two ways, one
recommended and one much less so. First the somewhat less recommended
way: it is possible to use the SDK, for which you can read the API
docs here http://api.libreoffice.org/. This re-uses the (extremely
generic) APIs we provide for macro scripting in StarBasic.

    The best way to add a generally useful feature to LibreOffice
is to work on the code base however. Overall this way makes it easier
to compile and build your code, it avoids any arbitrary limitations of
our scripting APIs, and in general is far more simple and intuitive -
if you are a reasonably able C++ programmer.


** The important bits of code

    Each module should have a README file inside it which has some
degree of documentation for that module; patches are most welcome to
improve those. We have those turned into a web-page here:

    http://docs.libreoffice.org/

    However, there are two hundred modules, many of them of only
peripheral interest for a specialist audience. So - where is the
good-stuff, the code that is most useful. Here is a quick overview of
the most important ones:

    sal/      - this provides a simple System Abstraction Layer
    tools/    - this provides basic internal types: 'Rectangle', 'Color' etc.
    vcl/      - this is the widget toolkit library and one rendering abstraction
    svx/      - graphics related helper code, including much of 'draw' / 'impress'
    sfx2/     - core framework: document model / load/save / signals for actions etc.
    framework - UNO wrappers around the core framework, responsible for building
                toolbars, menus, status bars, and the chrome around the document
                using widgets from VCL, and XML descriptions from */uiconfig/ files

    Then applications

    desktop/  - this is where the 'main' for the application lives, init / bootstrap
                the name dates back to an ancient StarOffice that also drew a desktop
    sw/       - writer.
    sc/       - calc
    sd/       - draw / impress

    There are several other libraries that are helpful from a
graphical perspective:

    basebmp/      - enables a VCL compatible rendering API to render to bitmaps,
                    as used for LibreOffice on-line, Android, iOS etc.
    basegfx/      - algorithms and data-types for graphics as used in the canvas
    canvas/       - new (UNO) canvas rendering model with various backends
    cppcanvas/    - C++ helper classes for using the UNO canvas
    drawinglayer/ - code to render and manage document drawing shapes and break
                    them down into primitives we can render more easily.

** Finding out more

    Beyond this, you can read the README files, send us patches, ask
on the mailing list libreoffice@lists.freedesktop.org (no subscription
required) or poke people on IRC #libreoffice-dev on irc.freenode.net -
we're a friendly and generally helpful mob. We know the code can be
hard to get into at first, and so there are no silly questions.

General
-------

In GNU Autoconf terminology, "build" is the platform on which you are
running a build of some software and "host" is the platform on which
the software you are building will run. Only in the specific case of
building compilers and other programming tools is the term "target"
used to indicate the platform for which the tools your are building
will produce code. As LibreOffice is not a compiler, the "target" term
should not be used in the context of cross-compilation.

(For a case where all three of "build", "host" and "target" are
different: consider a gcc cross-compiler running on Windows, producing
code for Android, where the cross-compiler itself was built on
Linux. (This is a real case.) An interesting tidbit is that such
configurations are called "Canadian Cross".)

Even though the LibreOffice build mechanism is highly unorthodox, the
configure script takes the normal --build and --host options like any
GNU Autoconf -based configure script. To cross-compile, you basically
need just to specify a suitable --host option and things should work
out nicely. In practice, many details need to be handled. See examples
below.

Note that in the case of LibreOffice, it is uncommon to run the
configure script directly. Normally one uses the autogen.sh script.
The autogen.sh script reads command-line options from file called
autogen.input if it exists. The typical way of working is to keep
the configure parameters in that file and edit it as needed.


What is so hard, then?
----------------------

Despite the fact that the configure script takes normal --build and
--host options, that is just the beginning. It was necessary to
separate tests for "host" and "build" platforms in the configure
script. See the git log for details. And the reasonably "standard"
configure.in is just the top level; when we get down to the actual
makefilery used to build the bits of LibreOffice, it gets much worse.


Windows
*******

There was some support in LibreOffice already from OpenOffice.org days
for building it locally on Windows with the GNU tool-chain (MinGW).
Apparently, those doing that work never attempted cross-compilation.

This OOo-originated MinGW support attempts to be for both running the
Cygwin gcc in its -mno-cygwin mode, and a Windows-native MinGW
compiler. The -mno-cygwin mechanism in the Cygwin gcc is rapidly being
obsoleted, if it isn't already, and we have not attempted to try to
keep it working; in fact we have actively cleaned out mechanisms
related to this. Ditto for native MinGW. If one compiles natively on
Windows, just use a version of Microsoft's compiler. OpenOffice.org
and LibreOffice have been built for Windows all the time using that.

The only case where it makes sense to use MinGW is for
cross-compilation. There is just too much crack involved on Windows
anyway, and it is a semi-miracle that the MSVC build under Cygwin
works as nicely as it does.

MinGW is available as cross-build toolchains pre-packaged in more or
less official packages for many Linux distros including Debian, Fedora
and openSUSE. For instance, the mingw32 packages in the Open Build
Service, running on openSUSE, can be found at:

http://download.opensuse.org/repositories/windows:/mingw:/win32/

For example, you can install it like this:

zypper ar http://download.opensuse.org/repositories/windows:/mingw:/win32/<your_os>/windows:mingw:win32.repo

where <your_os> is one of SLE_11, SLE_11_SP1, openSUSE_XX.Y, or
openSUSE_Factory.

zypper in mingw32-cross-gcc mingw32-cross-gcc-c++ mingw32-python-devel \
    mingw32-python mingw32-libboost_date_time \
    mingw32-libexpat-devel mingw32-libexpat mingw32-boost-devel \
    mingw32-libhyphen-devel mingw32-libhyphen mingw32-hyphen-en \
    mingw32-liblpsolve mingw32-liblpsolve-devel \
    mingw32-libxml2-devel mingw32-libxslt-devel mingw32-libicu \
    mingw32-libicu-devel mingw32-libgraphite2 mingw32-libgraphite2-devel \
    mingw32-libcairo2 mingw32-cairo-devel mingw32-librsvg mingw32-librsvg-devel \
    mingw32-hunspell mingw32-hunspell-devel mingw32-libcurl \
    mingw32-libcurl-devel mingw32-libneon mingw32-libneon-devel \
    mingw32-libopenssl mingw32-libopenssl-devel mingw32-libexttextcat \
    mingw32-libexttextcat-devel mingw32-libdb mingw32-libdb-devel \
    mingw32-cross-pkg-config mingw32-pkg-config mingw32-libcppunit \
    mingw32-libcppunit-devel mingw32-libredland mingw32-libredland-devel \
    mingw32-libmythes mingw32-libmythes-devel mingw32-mozilla-nss \
    mingw32-mozilla-nss-devel mingw32-mozilla-nspr \
    mingw32-mozilla-nspr-devel mingw32-libpoppler mingw32-libpoppler-devel

You also need wine, ideally:

zypper ar http://download.opensuse.org/repositories/Emulators:/Wine/<your_os>/Emulators:Wine.repo

zypper in wine wine-devel wine-devel-32bit

And in order to be able to use 'winegcc -m32', also

zypper in glibc-devel-32bit gcc-32bit

There might be more that are missing, please read carefully what autogen.sh
tells you, and either remove one of the --with-system-*, or install the
missing dependency.

It also looks like graphite2.pc needs tweaking in order to work right; but
that's likely to be fixed in the openSUSE project.

It is somewhat unclear how well thought-out the conditionals and code
for MinGW inside the OOo-originated code in LibreOffice actually
are. It often seems a bit randomish, with copy-pasting having been
preferred to factoring out differences.

Most of the configuration settings are maintained in the
distro-configs/LibreOfficeMinGW.conf file, so in your autogen.input,
you can use:

CC=ccache i686-w64-mingw32-gcc
CXX=ccache i686-w64-mingw32-g++
CC_FOR_BUILD=ccache gcc
CXX_FOR_BUILD=ccache g++
--with-distro=LibreOfficeMinGW

Alternatively, you can use something like the following; but the
preferred way is to keep the LibreOfficeMinGW.conf file up-to-date.

CC=ccache i686-w64-mingw32-gcc
CXX=ccache i686-w64-mingw32-g++
CC_FOR_BUILD=ccache gcc
CXX_FOR_BUILD=ccache g++
--build=x86_64-unknown-linux-gnu
--host=i686-w64-mingw32
--with-distro=LibreOfficeWin32
--disable-activex
--disable-directx
--disable-ext-nlpsolver
--disable-report-builder
--disable-scripting-beanshell
--disable-scripting-javascript
--disable-ext-wiki-publisher
--disable-pdfimport
--enable-python=system
--with-system-altlinuxhyph
--with-system-boost
--with-system-cairo
--with-system-cppunit
--with-system-curl
--with-system-expat
--with-system-hunspell
--with-system-icu
--with-system-libpng
--with-system-libwpd
--with-system-libwpg
--with-system-libwps
--with-system-libxml
--with-system-lpsolve
--with-system-mythes
--with-system-neon
--with-system-openssl
--with-system-redland
--with-vendor=no
--without-help
--without-helppack-integration
--without-myspell-dicts

Once you have compiled it, you may want to try to run it, for instance
using Wine:

$ cd /tmp
$ tar xf <your-build-dir>/workdir/wntgcci.pro/installation/LibreOffice_Dev/archive/install/en-US/LibO-Dev_4.1.0.0.alpha0_Win_x86_archive.tar.gz
$ cd LibO-Dev_4.1.0.0.alpha0_Win_x86_archive/LOdev\ 4.1/program/
$ wine soffice.exe

NB. it is important to unpack somewhere low in the hierarchy structure (like
in /tmp as advised above), otherwise you'll get BerkeleyDB errors on startup.

And if you are brave enough, you can even debug it.  First you have to add the
URE dll's to the wine's PATH using 'wine regedit' - see
http://www.winehq.org/docs/wineusr-guide/environment-variables, and add
Z:\tmp\LibO-Dev_4.1.0.0.alpha0_Win_x86_archive/LOdev\ 4.1\URE\bin
to "Path" in My Computer->HKEY_CURRENT_USER->Environment.

And start debugging:

$ winedbg soffice.bin

Would be great to be able to use winedbg --gdb, but it was crashing here :-( -
but maybe you'll be more lucky.

Tricks of some use with winedbg:
--------------------------------

To examine OUStrings, you might want to use the following trick (prints 50
unicode characters of rLibName OUString - the +10 is where the buffer starts):

Wine-dbg>x /50u rLibName->pData+10
0x0909b6c8: vnd.sun.star.expand:$LO_LIB_DIR/abplo.dll

TODO:

- make the debugging more convenient on (native) Windows
  - check possibilities like WinGDB - http://www.wingdb.com/
  - or find / write a MSVS / WinDBG extension that can read MinGW debugging
    symbols natively; more info
    http://windbg.info/forum/12-symbol-and-source-files-/21-debugging-mingwgcc-built-dll-in-visual-studio.html

- installation
  - so far the make_installer.pl calls makecab.exe, uuidgen.exe, and
    others; would be best to avoid that if at all possible (using a free
    cab implementation, part of Wine or something)
  - MSI generation

- runtime
  - no idea if the entire thing works after the installation at all; I
    suppose there will be runtime problems to look at too

- cleanup
  - enable & fix pieces that are currently disabled
    - --without-myspell-dicts
    - --disable-directx
    - --disable-activex
  - much of the stuff currently relies on --with-system-*, and
    consequently on the mingw32-* openSUSE packages; might be good to be
    able to build with as few dependencies as possible - but that is low
    prio

- profiling
  - when all the above is sorted out, we should look at the speed of
    this vs. the speed of the MSVC version


iOS
***

iOS is the operating system on Apple's mobile devices. Clearly for a
device like the iPad it would not be acceptable to run a normal
LibreOffice application with overlapping windows and mouse-oriented
GUI widgets.

It makes sense to use only a part of LibreOffice's code for iOS. Lots
of the GUI-oriented code should be left out. iOS apps that want to use
the applicable LibreOffice code will handle all their GUI in a
platform-dependent manner. How well it will be possible to do such a
split remains to be seen.

Obviously we want it to be possible to eventually distribute apps
using LibreOffice code through the App Store. Technically, one
important special aspect of iOS is that apps in the App Store are not
allowed to load own dynamic libraries. (System libraries are used in
the form of dynamic libraries, just like on Mac OS X, of which iOS is
a variant.)

Thus all the libraries in LibreOffice that normally are shared
libraries (DLLs on Windows, shared objects (.so) on Linux, dynamic
libraries on Mac OS X (.dylib)) must be built as static archives
instead. This has some interesting consequences for how UNO is
implemented and used.

An iOS app is a "bundle" that contains a single executable, In an app
using LibreOffice code, that eecutable then congtains the necessary
LibreOffice libraries and UNO components statically linked.

The Apple tool-chain for iOS cross-building is available only for OS
X. In order to be able to run and debug an app on an actual device
(and not just the iOS Simulator) you need to be registered in the iOS
Developer Program.

Here is an autogen.input for iOS (device) using Xcode 4.6, on OS X 10.8:

--build=i386-apple-darwin10.7.0
--host=arm-apple-darwin10
--enable-dbgutil
--enable-debug
--enable-werror

For the iOS Simulator, but note that building for the simulator is
broken at the moment (July 2014):

--build=i386-apple-darwin10.7.0
--host=arm-apple-darwin10
--enable-ios-simulator
--enable-dbgutil
--enable-debug
--enable-werror

You will have to install autoconf and automake yourself before running
autogen.sh. They are no longer included in Xcode 4.3 and later (not
even in the add-on "command line tools").

The -mmacosx-version-min=10.7 is necessary when building for the iOS
simulator to avoid clang replacing simple calls to fprintf with calls
to fwrite$UNIX2003 which Xcode then warns that doesn't exist on iOS.


Android
*******

From a technical point of view the core Android OS (the kernel) is
Linux, but everything else is different. Unlike iOS, an Android app
can use shared objects just fine, so that aspect of UNO doesn't need
special handling. Except that there is a silly low limit in the
Android dynamic linker on the number of libraries you can dlopen. This
is a limitation in user-level (but system-provided and not really
replaceable) code, not the kernel.

Thus, just like for iOS, also for Android the LibreOffice libraries
and UNO components are built as static archives. For Android, those
static archives, and any app-specific native code, are linked into one
single app-specific shared library, called liblo-native-code.so.

For the GUI, the same holds as said above for iOS. The GUI layer needs
to be platform-specific, written in Java.

Android cross-compilation work has been done mainly on Linux (openSUSE
in particular). Earlier also cross-compiling from OS X was tried. The
Android cross-compilation tool-chain (the "Native Development Kit", or
NDK) is available for Linux, OS X and Windows, but trying to
cross-compile LibreOffice from Windows will probably drive you insane.

You will also need the Android SDK as full "make" also builds a couple
of Android apps where the upper layer is written in Java.

Use the "android" tool from the SDK to install the SDK Tools, SDK
Platform Tools, the API 15 SDK Platform and the Android Support
Library. If you want to run the Android apps in the emulator, you of
course need an appropriate system image for that.

Here is an autogen.input for Android on ARM when cross-compiling
from Linux:

--build=x86_64-unknown-linux-gnu
--enable-dbgutil
--enable-debug
--enable-werror
--with-android-ndk=/home/tml/android-ndk-r9c
--with-android-ndk-toolchain-version=4.8
--with-android-sdk=/home/tml/adt-bundle-linux/sdk
--with-distro=LibreOfficeAndroid

And here is an (quite old) autogen.input for Android on X86:

--with-android-ndk=/opt/libreoffice/android-ndk-r8b
--with-android-ndk-toolchain-version=4.6
--with-android-sdk=/opt/libreoffice/android-sdk-linux
--build=i586-suse-linux
--enable-ccache
--with-distro=LibreOfficeAndroidX86

There are a couple of (more or less) interactive apps that you can run
on the emulator or on a device that use LibreOffice code. Look in
android/experimental. DocumentLoader is just a testbench, really for
code to load a document (just Writer ones so far) and display one page
at a time. LibreOffice4Android is what resulted from a Google Summer
of Code project in 2012, a document viewer. desktop is a totally
different app, where the actual LibreOffice desktop GUI is present.
Note that none of these apps in any way are claimed to be ready for
end-users. No "beta testing" offers needed, it is painfully obvious
what problems they have.

To run some of the apps, do "make install" followed by either "make
run" or starting it from Android itself. You most likely want to have
an "adb logcat" running in another window.

To debug, do manually what "make run" would do and when the app has
started, run ndk-gdb.

You can also do that manually; to install:

  <android-sdk-linux>/platform-tools/adb install -r android/experimental/LOAndroid3/bin/LibreOfficeViewer-debug.apk

To see the log:

  <android-sdk-linux>/platform-tools/adb logcat

To debug, install the .apk, run it, and then:

  cd android/experimental/LOAndroid3
  <android-ndk-r9d>/ndk-gdb --adb=<android-sdk-linux>/platform-tools/adb

NB: If you happen to upgrade to Android SDK Tools 23, and the build (using
'make verbose=t android') fails for you with:

       [dx] UNEXPECTED TOP-LEVEL EXCEPTION:
       [dx] java.io.FileNotFoundException: /local/libreoffice/android-sdk-linux/tools/support/annotations.jar (no such file or directory)

you need to copy the annotations.jar from an older sdk; like

wget 'http://dl-ssl.google.com/android/repository/tools_r22.6.2-linux.zip'
unzip tools_r22.6.2-linux.zip
cp tools/support/annotations.jar <android-sdk-linux>/tools/support/

Raspbian
********

In theory, this should work also for another Linux, it does not need to be Raspbian.
But this cross-compilation work is tested from Debian and openSUSE to Raspbian.

You will need headers, pkg-config files and libraries from a Raspbian
system to build against. Available at
http://dev-www.libreoffice.org/extern/ . Look for the latest
raspbian-root-*.tar.gz . For instance:

$ wget http://dev-www.libreoffice.org/extern/raspbian-root-20140120.tar.gz
$ mkdir raspbian-root
$ cd raspbian-root
$ tar -xf raspbian-root-20140120.tar.gz

You can build cross-compiler yourself or get the executables here:
$ git clone git://github.com/raspberrypi/tools

tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian is known to work.

Then create pkg-config wrapper, something like:
$ cat > pkg-config-wrapper-host << _EOF
#!/bin/sh

if [ "$CROSS_COMPILING" = TRUE ]; then
   SYSROOT=$HOME/lo/raspbian-root
   export PKG_CONFIG_PATH=${SYSROOT}/usr/lib/arm-linux-gnueabihf/pkgconfig:${SYSROOT}/usr/share/pkgconfig
   export PKG_CONFIG_LIBDIR=${SYSROOT}/usr/lib/pkgconfig
   export PKG_CONFIG_SYSROOT_DIR=${SYSROOT}
fi

exec pkg-config "\$@"
_EOF
$ chmod +x pkg-config-wrapper-host

This does not work with pkg-config 0.23. 0.26 is known to work.

And you are ready to build with autogen.input similar to:

PKG_CONFIG=<path-to-pkg-config-wrapper-host>
CC=<path-to-arm-linux-gnueabihf-gcc> --sysroot=<path-to-raspbian_rootfs>
CXX=<path-to-arm-linux-gnueabihf-g++> --sysroot=<path-to-raspbian_rootfs>
--build=x86_64-unknown-linux-gnu
--host=arm-unknown-linux-gnueabihf
--disable-sdk
--enable-python=system
PYTHON_CFLAGS=-I<path-to-raspbian_rootfs>/usr/include/python2.7
PYTHON_LIBS=-lpython2.7
--with-java
JAVAINC=-I<path-to-raspbian_rootfs>/usr/lib/jvm/java-6-openjdk-armhf/include
--with-system-cairo
--with-system-cppunit
--with-system-icu
--with-system-neon
--with-system-nss
--with-system-openldap
--with-system-openssl
--with-system-redland

Finally, when you are ready to run the binaries in Raspbian,
you may need to get more system libraries, who knows.
$ sudo apt-get install libreoffice # or similar
That installs libreoffice too, which you don't need because you have
just built one, but I don't know how to avoid it easily.