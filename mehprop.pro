TARGET = meshprop
INCLUDEPATH += . ./vcglib
CONFIG += console stl
TEMPLATE = app
SOURCES += meshprop.cpp ./vcglib/wrap/ply/plylib.cpp

# Mac specific Config required to avoid to make application bundles
CONFIG -= app_bundle
CONFIG -= qt
