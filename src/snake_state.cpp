#include "snake_state.h"

SnakeState::SnakeState()
    : lcg::GameState()
{
}
void SnakeState::onInit()
{
    attach( &_level_StartApp );
    return;
}
const lcg::SceneBuilder* SnakeState::getScene()
{
    if( _level_StartApp.getName() == getCurrentLevel()->getName() )
        return( _level_StartApp.getScene() );
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
    return;
}
SnakeState::~SnakeState()
{
}
