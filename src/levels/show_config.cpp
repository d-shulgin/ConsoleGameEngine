#include "show_config.h"

ShowConfig::ShowConfig()
    : lcg::Level()
{
}
void ShowConfig::onInit( lcg::UserInput* )
{
}
void ShowConfig::onActivate()
{
}
void ShowConfig::prepareDraw()
{
    beginScene();
}
bool ShowConfig::onSceneShow( int index )
{
    if( static_cast<std::size_t>(index) < getScenes().size()
        && getScenes()[index]->getName() == getIgnoreBgrScene() )
        return( false );
    return( true );
}
ShowConfig::~ShowConfig()
{
}
