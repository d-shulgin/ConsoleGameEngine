#include "start_app.h"
#include <algorithm>
#include "../scenes/scene_start.h"

StartApp::StartApp()
    : lcg::Level()
{
}
void StartApp::onActivate()
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , []( lcg::SceneBuilder* scene )->bool{ return( scene->getName() == SceneStart::class_name() ); } );
    if( it != refScenes().end() )
        (*it)->as<SceneStart>()->showInvitation();
    return;
}
void StartApp::onDeactivate()
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , []( lcg::SceneBuilder* scene )->bool{ return( scene->getName() == SceneStart::class_name() ); } );
    if( it != refScenes().end() )
        (*it)->as<SceneStart>()->hideInvitation();
    return;
}
void StartApp::prepareDraw()
{
    beginScene();
    return;
}
StartApp::~StartApp()
{
}
