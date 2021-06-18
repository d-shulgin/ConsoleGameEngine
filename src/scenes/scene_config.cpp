#include "scene_config.h"

SceneConfig::SceneConfig()
    : lcg::SceneBuilder()
{
}
SceneConfig::~SceneConfig()
{
}

void SceneConfig::onBuild()
{
    rsc.load();

    lcg::Group* root = nullptr;
    _scene.setRoot( root = new lcg::Group("root") );
    if( nullptr != root )
    {
        root -> setPosition( 30, 10 );
        root -> addChild( background = new lcg::Sprite("bgr") );

        loadBackground();
    }
    return;
}
void SceneConfig::loadBackground()
{
    if( nullptr != background )
    {
        background -> setImage( rsc.background() );
        background -> setPosition( 0, 0 );
    }
    return;
}
void SceneConfig::onProcess(float)
{
}


void SceneConfig::Resources::load()
{
    // background |
    {
        _background = lcg::Image( 60, 30 );
        _background.beginSymbols().beginColors().beginBgColors()
                .addSymbols( "------------------------------------------------------------" )
                .addSymbols( "|                     Control settings                     |" )
                .addSymbols( "------------------------------------------------------------" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "| Press ESC to go back.                                    |" )
                .addSymbols( "------------------------------------------------------------" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "BYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYB" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    return;
}
