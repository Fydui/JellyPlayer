TEMPLATE = app

QT += qml quick
CONFIG += c++11
QT       += core gui

SOURCES += main.cpp \
    music.cpp
QT += multimedia
QT += qml
RESOURCES += qml.qrc
RC_FILE = file.rc
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    music.h
