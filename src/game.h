#ifndef GAME_H
#define GAME_H

#include <functional>

#include "../lib/engine.h"
#include "snake_state.h"
#include "scenes/package.h"
#include "actions/action_start_menu.h"
#include "actions/action_choice_item.h"
#include "actions/action_comeback_from_config.h"

class Game final : public lcg::Core
{
    typedef lcg::Position Pos;
public:
    explicit Game( int = 0, int = 0 );

private:
    lcg::FPSCounter fps;

protected: // initialize
    virtual void onInit() override;

protected: // prepare before main game loop
    virtual void onStart() override;

protected: // scene process logic (before Draw)
    virtual void onProcess( float ) override;

protected: // draw
    virtual void onPrepareDraw() override;
    virtual const lcg::Scene* getScene() override;

protected: // after draw process
    virtual void onPostProcess() override;

private: // state
    SnakeState state;

private: // scenes
    SceneStart  _scene_startApp;
    SceneMenu   _scene_Menu;
    SceneConfig _scene_ControlSettings;
    SceneDebug  _scene_Debug;

private: // actions
    Action_StartMenu action_StartMenu;
    class Handler_StartMenu final : public lcg::Action::Callback
    {
        std::function<void (Game&)> fnPress;
        Game* obj = nullptr;
    public:
        Handler_StartMenu()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override{ }
        void setFnPress( Game* o, std::function<void(Game&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerStartMenu;

    void launchStartMenu();

    Action_ChoiceItem action_ChoiceItem;
    class Handler_ChoiceItem final : public lcg::Action::Callback
    {
        std::function<void (Game&)> fnPress;
        Game* obj = nullptr;
    public:
        Handler_ChoiceItem()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override{ }
        void setFnPress( Game* o, std::function<void(Game&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerChoiceItem;

    void choiceStartMenu();

    Action_ComebackFromConfig action_CombackFromConfig;
    class Handler_ComebackFromConfig final : public lcg::Action::Callback
    {
        std::function<void (Game&)> fnPress;
        Game* obj = nullptr;
    public:
        Handler_ComebackFromConfig()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override{ }
        void setFnPress( Game* o, std::function<void(Game&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerComebackFromConfig;

    void comebackFromConfig();
};

#endif // GAME_H
