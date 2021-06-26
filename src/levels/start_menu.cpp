#include "start_menu.h"
#include <algorithm>
#include "../scenes/scene_menu.h"

StartMenu::StartMenu()
    : lcg::Level()
{
    handlerSelectItemUp  .setFnPress( this, &StartMenu::selectMenuItemUp );
    handlerSelectItemDown.setFnPress( this, &StartMenu::selectMenuItemDown );
}
void StartMenu::onInit( lcg::UserInput* input )
{
    action_SelectMenuItemUp.bind( this );
    action_SelectMenuItemUp.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(0x57 /*W key*/)}) );
    action_SelectMenuItemUp.setAltKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_UP)}) );
    action_SelectMenuItemUp.setCallback( &handlerSelectItemUp );
    action_SelectMenuItemUp.setActive( true );

    action_SelectMenuItemDown.bind( this );
    action_SelectMenuItemDown.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(0x53 /*S key*/)}) );
    action_SelectMenuItemDown.setAltKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_DOWN)}) );
    action_SelectMenuItemDown.setCallback( &handlerSelectItemDown );
    action_SelectMenuItemDown.setActive( true );

    if( nullptr != input )
    {
        input->attach( &action_SelectMenuItemUp );
        input->attach( &action_SelectMenuItemDown );
    }
    return;
}
void StartMenu::onActivate()
{
    currentMenuItem = 0;
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , []( lcg::SceneBuilder* scene )->bool{ return( scene->getName() == SceneMenu::class_name() ); } );
    if( it != refScenes().end() )
        (*it)->as<SceneMenu>()->selectMenuItem( currentMenuItem );
}
void StartMenu::prepareDraw()
{
    beginScene();
    return;
}
bool StartMenu::onSceneShow( int index )
{
    if( index < getScenes().size()
        && getScenes()[index]->getName() == getIgnoreBgrScene() )
        return( false );
    return( true );
}
void StartMenu::selectMenuItemUp()
{
    currentMenuItem --;
    if( currentMenuItem < 0 )
        currentMenuItem = 0;

    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , []( lcg::SceneBuilder* scene )->bool{ return( scene->getName() == SceneMenu::class_name() ); } );
    if( it != refScenes().end() )
        (*it)->as<SceneMenu>()->selectMenuItem( currentMenuItem );
    return;
}
void StartMenu::selectMenuItemDown()
{
    currentMenuItem ++;
    if( currentMenuItem >= SceneMenu::AMOUNT_MENUITEMS )
        currentMenuItem = SceneMenu::AMOUNT_MENUITEMS - 1;

    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , []( lcg::SceneBuilder* scene )->bool{ return( scene->getName() == SceneMenu::class_name() ); } );
    if( it != refScenes().end() )
        (*it)->as<SceneMenu>()->selectMenuItem( currentMenuItem );
    return;
}
StartMenu::~StartMenu()
{
}
