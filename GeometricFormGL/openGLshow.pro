#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T07:42:33
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openGLshow
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mythread.cpp

HEADERS  += widget.h \
    mythread.h

FORMS    += widget.ui

LIBS += -lopengl32
