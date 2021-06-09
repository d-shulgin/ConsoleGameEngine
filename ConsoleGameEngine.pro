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
    lib/render/scene.cpp \
    lib/render/group.cpp \
    lib/render/view.cpp \
    lib/render/text.cpp \
    lib/types/position.cpp \
    src/game_state.cpp \
    src/level.cpp \
    lib/render/sprite.cpp \
    lib/types/image.cpp

HEADERS += \
    lib/engine.h \
    src/game.h \
    lib/core.h \
    lib/surface.h \
    lib/surface/screen_buffer.h \
    lib/types/color.h \
    lib/render/scene.h \
    lib/render/group.h \
    lib/render/view.h \
    lib/render/text.h \
    lib/types/position.h \
    src/game_state.h \
    src/level.h \
    lib/render/sprite.h \
    lib/types/image.h

