#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T19:56:43
# Authors: Clayton Jerlow and Deborah Orret
#
# Credit: Google Images for demo photo royce.jpg
#         and for all photos used for buttons
#
#         Stackoverflow.come for the general idea behind sepia algorithm
#         https://stackoverflow.com/questions/46535331/how-to-convert-image-to-sepia-in-java
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotoEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwind.cpp \
    welwind.cpp \
    image.cpp \
    savewind.cpp

HEADERS += \
        mainwind.h \
    welwind.h \
    image.h \
    savewind.h

FORMS += \
        mainwind.ui \
    welwind.ui \
    savewind.ui

RESOURCES += \
    imgs.qrc
