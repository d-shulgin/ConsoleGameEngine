#include "scene_debug.h"
#include <sstream>
#include <iomanip>

SceneDebug::SceneDebug()
    : lcg::SceneBuilder()
{
}
SceneDebug::~SceneDebug()
{
}

void SceneDebug::onBuild()
{
    lcg::Group* root = nullptr;
    _scene.setRoot( root = new lcg::Group("root") );
    if( nullptr != root )
    {
        root -> setPosition( 0, 0 );
        root -> addChild( console = new lcg::Text("console") );
        root -> addChild( fps = new lcg::Text("FPS") );
        if( nullptr != console )
        {
            console->setPosition( 1, 1 );
            console->setColor( lcg::ColorID::white );
        }
        if( nullptr != fps )
        {
            fps->setPosition( 110, 1 );
            fps->setColor( lcg::ColorID::white );
        }
    }
    return;
}
void SceneDebug::setConsole( const std::string& str )
{
    if( nullptr != console )
    {
        console->setString( str );
    }
    return;
}
void SceneDebug::setFPS( float fpsVal )
{
    if( nullptr != fps )
    {
        std::stringstream ss;
        ss << std::setprecision(3) << fpsVal;
        fps->setString( "FPS: "+ss.str() );
    }
    return;
}
