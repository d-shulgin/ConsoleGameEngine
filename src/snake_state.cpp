#include "snake_state.h"

SnakeState::SnakeState()
    : lcg::GameState()
{
}
void SnakeState::onInit()
{
    attach( &_level_StartApp );
    attach( &_level_StartMenu );
    _level_StartApp.init( getInput() );
    _level_StartMenu.init( getInput() );
    return;
}
const lcg::SceneBuilder* SnakeState::getScene()
{
    if( _level_StartApp.getName() == getCurrentLevel()->getName() )
        return( _level_StartApp.getScene() );
    if( _level_StartMenu.getName() == getCurrentLevel()->getName() )
        return( _level_StartMenu.getScene() );
    return( nullptr );
}
void SnakeState::currentLevelProcess( float dt )
{
    currentLevel()->process( dt );
    return;
}
void SnakeState::onPrepareDraw()
{
    if( _level_StartApp.getName() == getCurrentLevel()->getName() )
        _level_StartApp.prepareDraw();
    else if( _level_StartMenu.getName() == getCurrentLevel()->getName() )
        _level_StartMenu.prepareDraw();
    return;
}
SnakeState::~SnakeState()
{
}
