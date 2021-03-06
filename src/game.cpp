#include "game.h"
#include <iostream>

Game::Game( int width, int height )
    : Core( width, height )
{
    handlerStartMenu .setFnPress( this, &Game::launchStartMenu );
    handlerMainMenu  .setFnPress( this, &Game::launchMainMenu  );
    handlerChoiceItem.setFnPress( this, &Game::choiceStartMenu );
    handlerComebackFromConfig.setFnPress( this, &Game::comebackFromConfig );
}
void Game::onInit()
{
    fps.reset();
    state.init( refInput() );
    _scene_startApp.init();
    _scene_Menu.init();
    _scene_ControlSettings.init();
    _scene_GameField.init();
    _scene_GameOver.init();
    _scene_Debug.init();

    action_StartMenu.bind( &state.level_StartApp() );
    action_StartMenu.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_RETURN)}) );
    action_StartMenu.setCallback( &handlerStartMenu );
    action_StartMenu.setActive( true );
    refInput().attach( &action_StartMenu );

    action_MainMenu.bind( &state.level_GameField() );
    action_MainMenu.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_ESCAPE)}) );
    action_MainMenu.setCallback( &handlerMainMenu );
    action_MainMenu.setActive( true );
    refInput().attach( &action_MainMenu );

    action_ChoiceItem.bind( &state.level_StartMenu() );
    action_ChoiceItem.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_RETURN)}) );
    action_ChoiceItem.setCallback( &handlerChoiceItem );
    action_ChoiceItem.setActive( true );
    refInput().attach( &action_ChoiceItem );

    action_CombackFromConfig.bind( &state.level_ShowConfig() );
    action_CombackFromConfig.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_ESCAPE)}) );
    action_CombackFromConfig.setCallback( &handlerComebackFromConfig );
    action_CombackFromConfig.setActive( true );
    refInput().attach( &action_CombackFromConfig );
    return;
}
void Game::onStart()
{
    _scene_startApp.build();
    _scene_Menu.build();
    _scene_ControlSettings.build();
    _scene_GameField.build();
    _scene_GameOver.build();
    _scene_Debug.build();

    state.level_StartApp()
            .attach( &_scene_startApp )
            .attach( &_scene_Debug );
    state.level_StartMenu()
            .attach( &_scene_startApp )
            .attach( &_scene_GameField )
            .attach( &_scene_Menu )
            .attach( &_scene_Debug );
    state.level_ShowConfig()
            .attach( &_scene_startApp )
            .attach( &_scene_GameField )
            .attach( &_scene_ControlSettings )
            .attach( &_scene_Debug );
    state.level_GameField()
            .attach( &_scene_GameField )
            .attach( &_scene_GameOver )
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
    _scene_Menu.forStartMenu();
    state.level_StartMenu().setIgnoreBgrScene( _scene_GameField.getName() );
    state.launch( StartMenu::class_name() );
    return;
}
void Game::launchMainMenu()
{
    if( state.checkGameOver() )
    {
        launchStartMenu();
    }
    else
    {
        _scene_Menu.forMainMenu();
        state.level_StartMenu().setIgnoreBgrScene( _scene_startApp.getName() );
        state.launch( StartMenu::class_name() );
    }
    return;
}
void Game::choiceStartMenu()
{
    switch( state.level_StartMenu().getCurrentMenuItem() )
    {
    case 0:
        state.launch( GameField::class_name() );
        break;
    case 1:
        state.level_ShowConfig().setIgnoreBgrScene( state.level_StartMenu().getIgnoreBgrScene() );
        state.level_ShowConfig().setBack( state.getCurrentLevel()->getName() );
        state.launch( ShowConfig::class_name() );
        break;
    case 2:
        stop();
        break;
    }
    return;
}
void Game::comebackFromConfig()
{
    state.launch( state.level_ShowConfig().getBack() );
}
