#############################################################################
# Makefile for building: 4gui
# Generated by qmake (2.01a) (Qt 4.6.3) on: ?? 9? 25 10:44:30 2016
# Project:  ../4gui/4gui.pro
# Template: app
# Command: /opt/qtsdk-2010.04/qt/bin/qmake -spec /opt/qtsdk-2010.04/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile ../4gui/4gui.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/qtsdk-2010.04/qt/mkspecs/linux-g++-64 -I../4gui -I/opt/qtsdk-2010.04/qt/include/QtCore -I/opt/qtsdk-2010.04/qt/include/QtGui -I/opt/qtsdk-2010.04/qt/include -I. -I. -I../4gui -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-rpath,/opt/qtsdk-2010.04/qt/lib
LIBS          = $(SUBLIBS)  -L/opt/qtsdk-2010.04/qt/lib -lQtGui -L/opt/qtsdk-2010.04/qt/lib -L/usr/X11R6/lib64 -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/qtsdk-2010.04/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../4gui/main.cpp \
		../4gui/widget.cpp moc_widget.cpp
OBJECTS       = main.o \
		widget.o \
		moc_widget.o
DIST          = /opt/qtsdk-2010.04/qt/mkspecs/common/g++.conf \
		/opt/qtsdk-2010.04/qt/mkspecs/common/unix.conf \
		/opt/qtsdk-2010.04/qt/mkspecs/common/linux.conf \
		/opt/qtsdk-2010.04/qt/mkspecs/qconfig.pri \
		/opt/qtsdk-2010.04/qt/mkspecs/features/qt_functions.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/qt_config.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/exclusive_builds.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/default_pre.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/debug.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/default_post.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/warn_on.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/qt.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/unix/thread.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/moc.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/resources.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/uic.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/yacc.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/lex.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/include_source_dir.prf \
		../4gui/4gui.pro
QMAKE_TARGET  = 4gui
DESTDIR       = 
TARGET        = 4gui

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_widget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ../4gui/4gui.pro  /opt/qtsdk-2010.04/qt/mkspecs/linux-g++-64/qmake.conf /opt/qtsdk-2010.04/qt/mkspecs/common/g++.conf \
		/opt/qtsdk-2010.04/qt/mkspecs/common/unix.conf \
		/opt/qtsdk-2010.04/qt/mkspecs/common/linux.conf \
		/opt/qtsdk-2010.04/qt/mkspecs/qconfig.pri \
		/opt/qtsdk-2010.04/qt/mkspecs/features/qt_functions.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/qt_config.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/exclusive_builds.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/default_pre.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/debug.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/default_post.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/warn_on.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/qt.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/unix/thread.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/moc.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/resources.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/uic.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/yacc.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/lex.prf \
		/opt/qtsdk-2010.04/qt/mkspecs/features/include_source_dir.prf \
		/opt/qtsdk-2010.04/qt/lib/libQtGui.prl \
		/opt/qtsdk-2010.04/qt/lib/libQtCore.prl
	$(QMAKE) -spec /opt/qtsdk-2010.04/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile ../4gui/4gui.pro
/opt/qtsdk-2010.04/qt/mkspecs/common/g++.conf:
/opt/qtsdk-2010.04/qt/mkspecs/common/unix.conf:
/opt/qtsdk-2010.04/qt/mkspecs/common/linux.conf:
/opt/qtsdk-2010.04/qt/mkspecs/qconfig.pri:
/opt/qtsdk-2010.04/qt/mkspecs/features/qt_functions.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/qt_config.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/exclusive_builds.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/default_pre.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/debug.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/default_post.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/warn_on.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/qt.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/unix/thread.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/moc.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/resources.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/uic.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/yacc.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/lex.prf:
/opt/qtsdk-2010.04/qt/mkspecs/features/include_source_dir.prf:
/opt/qtsdk-2010.04/qt/lib/libQtGui.prl:
/opt/qtsdk-2010.04/qt/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /opt/qtsdk-2010.04/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile ../4gui/4gui.pro

dist: 
	@$(CHK_DIR_EXISTS) ../4gui/.tmp/4gui1.0.0 || $(MKDIR) ../4gui/.tmp/4gui1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) ../4gui/.tmp/4gui1.0.0/ && $(COPY_FILE) --parents ../4gui/widget.h ../4gui/.tmp/4gui1.0.0/ && $(COPY_FILE) --parents ../4gui/main.cpp ../4gui/widget.cpp ../4gui/.tmp/4gui1.0.0/ && $(COPY_FILE) --parents ../4gui/widget.ui ../4gui/.tmp/4gui1.0.0/ && (cd `dirname ../4gui/.tmp/4gui1.0.0` && $(TAR) 4gui1.0.0.tar 4gui1.0.0 && $(COMPRESS) 4gui1.0.0.tar) && $(MOVE) `dirname ../4gui/.tmp/4gui1.0.0`/4gui1.0.0.tar.gz . && $(DEL_FILE) -r ../4gui/.tmp/4gui1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_widget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_widget.cpp
moc_widget.cpp: ../4gui/widget.h
	/opt/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) ../4gui/widget.h -o moc_widget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_widget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_widget.h
ui_widget.h: ../4gui/widget.ui
	/opt/qtsdk-2010.04/qt/bin/uic ../4gui/widget.ui -o ui_widget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ../4gui/main.cpp ../4gui/widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../4gui/main.cpp

widget.o: ../4gui/widget.cpp ../4gui/widget.h \
		ui_widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widget.o ../4gui/widget.cpp

moc_widget.o: moc_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widget.o moc_widget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

