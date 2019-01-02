#! [0]
TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../addwindow
HEADERS         = addplugin.h
SOURCES         = addplugin.cpp
TARGET          = $$qtLibraryTarget(addplugin)
DESTDIR         = ../plugins
#! [0]

EXAMPLE_FILES = echoplugin.json

# install
target.path = $${OBJECTS_DIR}/plugins #$$[QT_INSTALL_EXAMPLES]/widgets/tools/echoplugin/plugins
INSTALLS += target

CONFIG += install_ok  # Do not cargo-cult this!
