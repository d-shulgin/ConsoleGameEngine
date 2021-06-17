#include "game.h"
#include <iostream>

Game::Game( int width, int height )
    : Core( width, height )
{
    handlerStartMenu .setFnPress( this, &Game::launchStartMenu );
    handlerChoiceItem.setFnPress( this, &Game::choiceStartMenu );
}
void Game::onInit()
{
    fps.reset();
    state.init( refInput() );
    _scene_startApp.init();
    _scene_Menu.init();
    _scene_Debug.init();

    action_StartMenu.bind( &state.level_StartApp() );
    action_StartMenu.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_RETURN)}) );
    action_StartMenu.setCallback( &handlerStartMenu );
    action_StartMenu.setActive( true );
    refInput().attach( &action_StartMenu );

    action_ChoiceItem.bind( &state.level_StartMenu() );
    action_ChoiceItem.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_RETURN)}) );
    action_ChoiceItem.setCallback( &handlerChoiceItem );
    action_ChoiceItem.setActive( true );
    refInput().attach( &action_ChoiceItem );
    return;
}
void Game::onStart()
{
    _scene_startApp.build();
    _scene_Menu.build();
    _scene_Debug.build();

    state.level_StartApp()
            .attach( &_scene_startApp )
            .attach( &_scene_Debug );
    state.level_StartMenu()
            .attach( &_scene_startApp )
            .attach( &_scene_Menu )
            .attach( &_scene_Debug );
}
void Game::onProcess( float dt )
{
    fps.update( dt );
    _scene_Debug.setFPS( fps.getCurrent() );
    state.currentLevelProcess( dt );
    return;
}
void Game::onPrepareDraw()
{
    state.prepareDraw();
    return;
}
const lcg::Scene* Game::getScene()
{
    const lcg::SceneBuilder* builder = state.getScene();
    if( nullptr != builder )
        return( builder -> scene() );
    return( nullptr );
}
void Game::onPostProcess()
{
}
void Game::launchStartMenu()
{
    state.launch( StartMenu::class_name() );
    return;
}
void Game::choiceStartMenu()
{
    switch( state.level_StartMenu().getCurrentMenuItem() )
    {
    case 0:break;
    case 1:break;
    case 2:
        stop();
        break;
    }
    return;
}
