#include "scene_debug.h"

SceneDebug::SceneDebug()
{
}
SceneDebug::~SceneDebug()
{
}

void SceneDebug::onBuild()
{
    _scene.setRoot( root = new lcg::Text("root") );
    if( nullptr != root )
    {
        root->setPosition( 1, 1 );
        root->setColor( lcg::ColorID::white );
    }
    return;
}
void SceneDebug::setText( const std::string& str )
{
    if( nullptr != root )
    {
        root->setString( str );
    }
    return;
}
