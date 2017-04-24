#-------------------------------------------------
#
# Project created by QtCreator 2016-10-17T16:34:39
#
#-------------------------------------------------

QT       += core gui opengl
QT += widgets

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AmigurumiVisualizer
TEMPLATE = app


SOURCES += main.cpp\
    amigurumi/stitch.cpp \
    amigurumi/round.cpp \
    amigurumi/element.cpp \
    amigurumi/amigurumi.cpp \
    OGL/gldisplaywidget.cpp \
    OGL/camera.cpp \
    OGL/modelelement.cpp \
    GUI/mainwindow.cpp \
    patternParser/patternparser.cpp \
    tests/testsamigurumi.cpp \
    OGL/glmainframe.cpp \
    OGL/renderthread.cpp

HEADERS  += amigurumi/stitch.h \
    amigurumi/round.h \
    amigurumi/element.h \
    amigurumi/amigurumi.h \
    OGL/gldisplaywidget.h \
    OGL/camera.h \
    OGL/modelelement.h \
    GUI/mainwindow.h \
    patternParser/patternparser.h \
    tests/testsamigurumi.h \
    OGL/glmainframe.h \
    OGL/renderthread.h

# FORMS    += mainwindow.ui

DISTFILES += \
    res/testPattern.txt

RESOURCES += \
    res/patterntestsres.qrc
