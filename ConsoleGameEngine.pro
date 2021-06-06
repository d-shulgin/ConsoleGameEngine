TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    src/game.cpp \
    lib/core.cpp \
    lib/surface.cpp \
    lib/surface/screen_buffer.cpp \
    lib/types/color.cpp \
    lib/render/scene.cpp

HEADERS += \
    lib/engine.h \
    src/game.h \
    lib/core.h \
    lib/surface.h \
    lib/surface/screen_buffer.h \
    lib/types/color.h \
    lib/render/scene.h

