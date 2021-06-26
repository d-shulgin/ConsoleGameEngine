#include "show_config.h"

ShowConfig::ShowConfig()
    : lcg::Level()
{
}
void ShowConfig::onInit( lcg::UserInput* input )
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
    if( index < getScenes().size()
        && getScenes()[index]->getName() == getIgnoreBgrScene() )
        return( false );
    return( true );
}
ShowConfig::~ShowConfig()
{
}
