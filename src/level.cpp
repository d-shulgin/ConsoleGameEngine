#include "level.h"

Level::Level()
{
}
void Level::beginScene()
{
    showScene = 0;
}
void Level::nextScene()
{
    showScene ++;
}
const lcg::Scene* Level::getScene() const
{
    if( showScene < static_cast<int>(scenes.size()) )
        return( scenes[ showScene ] );
    return( nullptr );
}
Level& Level::attachScene( const lcg::Scene* const scene )
{
    scenes.push_back( scene );
    return( *this );
}
