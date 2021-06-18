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
    lib/render/sprite.cpp \
    lib/types/image.cpp \
    lib/game/animation.cpp \
    lib/utils/fps_counter.cpp \
    lib/game/level.cpp \
    src/levels/start_app.cpp \
    src/scenes/scene_start.cpp \
    lib/game/scene_builder.cpp \
    lib/game/game_state.cpp \
    src/snake_state.cpp \
    lib/game/action.cpp \
    src/actions/action_start_menu.cpp \
    lib/input/vkey.cpp \
    lib/input/keyboard_shortcut.cpp \
    lib/input/user_input.cpp \
    src/scenes/scene_debug.cpp \
    src/levels/start_menu.cpp \
    src/scenes/scene_menu.cpp \
    src/actions/action_select_item_up.cpp \
    src/actions/action_select_item_down.cpp \
    src/actions/action_choice_item.cpp \
    src/scenes/scene_config.cpp \
    src/levels/show_config.cpp \
    src/actions/action_comeback_from_config.cpp

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
    lib/render/sprite.h \
    lib/types/image.h \
    lib/game/animation.h \
    lib/utils/fps_counter.h \
    lib/game/level.h \
    src/levels/start_app.h \
    src/scenes/scene_start.h \
    src/scenes/package.h \
    lib/game/scene_builder.h \
    lib/game/game_state.h \
    src/snake_state.h \
    src/levels/package.h \
    lib/game/action.h \
    src/actions/action_start_menu.h \
    lib/input/vkey.h \
    lib/input/keyboard_shortcut.h \
    lib/input/user_input.h \
    src/scenes/scene_debug.h \
    src/levels/start_menu.h \
    src/scenes/scene_menu.h \
    src/actions/action_select_item_up.h \
    src/actions/action_select_item_down.h \
    src/actions/action_choice_item.h \
    src/scenes/scene_config.h \
    src/levels/show_config.h \
    src/actions/action_comeback_from_config.h

