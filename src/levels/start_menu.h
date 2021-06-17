#ifndef START_MENU_H
#define START_MENU_H

#include "lib/engine.h"
#include "../actions/action_select_item_up.h"
#include "../actions/action_select_item_down.h"

class StartMenu final : public lcg::Level
{
public:
    StartMenu();
    virtual ~StartMenu();

protected:
    virtual void onInit( lcg::UserInput* ) override;

public: // name
    static std::string class_name() { return( "StartMenu" ); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // choice
    virtual void onActivate() override;

public: // prepare draw
    void prepareDraw();

private: // actions
    Action_SelectItemUp   action_SelectMenuItemUp;
    Action_SelectItemDown action_SelectMenuItemDown;

    class Handler_SelectItemUp final : public lcg::Action::Callback
    {
        std::function<void (StartMenu&)> fnPress;
        StartMenu* obj = nullptr;

    public:
        Handler_SelectItemUp()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override {}
        void setFnPress( StartMenu* o, std::function<void(StartMenu&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerSelectItemUp;

    class Handler_SelectItemDown final : public lcg::Action::Callback
    {
        std::function<void (StartMenu&)> fnPress;
        StartMenu* obj = nullptr;

    public:
        Handler_SelectItemDown()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override {}
        void setFnPress( StartMenu* o, std::function<void(StartMenu&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerSelectItemDown;

private: // cursor
    int currentMenuItem = 0;

    void selectMenuItemUp();
    void selectMenuItemDown();

public:
    int getCurrentMenuItem() const { return( currentMenuItem ); }
};

#endif // START_MENU_H
