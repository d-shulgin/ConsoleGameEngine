#include "scene_menu.h"

SceneMenu::SceneMenu()
{
}
SceneMenu::~SceneMenu()
{
}

void SceneMenu::onBuild()
{
    rsc.load();

    lcg::Group* root = nullptr;

    _scene.setRoot( root = new lcg::Group("root") );
    if( nullptr != root )
    {
        root -> setPosition( 30, 10 );
        root -> addChild( background = new lcg::Sprite("logotype") );
        root -> addChild( cursor = new lcg::Sprite("cursor") );
        loadBackground();
        loadCursor();
    }
    return;
}
void SceneMenu::loadBackground()
{
    if( nullptr != background )
    {
        background->setImage( rsc.background() );
        background->setPosition(0, 0);
    }
    return;
}
void SceneMenu::loadCursor()
{
    if( nullptr != cursor )
    {
        cursorAnim.addImage( rsc.cursor(0) );
        cursorAnim.addImage( rsc.cursor(1) );
        cursorAnim.addImage( rsc.cursor(2) );
        cursorAnim.addImage( rsc.cursor(3) );
        cursorAnim.addImage( rsc.cursor(4) );
        cursorAnim.addImage( rsc.cursor(5) );
//        cursorAnim.addImage( rsc.cursor(6) );
//        cursorAnim.addImage( rsc.cursor(7) );
//        cursorAnim.addImage( rsc.cursor(8) );
//        cursorAnim.addImage( rsc.cursor(9) );
//        cursorAnim.addImage( rsc.cursor(10) );
//        cursorAnim.addImage( rsc.cursor(11) );
//        cursorAnim.addImage( rsc.cursor(12) );
//        cursorAnim.addImage( rsc.cursor(13) );
//        cursorAnim.addImage( rsc.cursor(14) );
//        cursorAnim.addImage( rsc.cursor(15) );
//        cursorAnim.addImage( rsc.cursor(16) );
//        cursorAnim.addImage( rsc.cursor(17) );
        cursorAnim.setCycle( true );
        cursorAnim.setRestartFrame( 0 );
        cursorAnim.setSpeed( 12.0f );
        cursor->setImage( cursorAnim.getImage() );
        selectMenuItem( 0 );
    }
    cursorAnim.start();
    return;
}
void SceneMenu::selectMenuItem( int item )
{
    if( nullptr != cursor )
    {
        cursor->setPosition( 1, 3+item*6 );
    }
    return;
}
void SceneMenu::onProcess( float dt )
{
    cursorAnim.update( dt );
    if( nullptr != cursor )
        cursor->setImage( cursorAnim.getImage() );
    return;
}


void SceneMenu::Resources::load()
{
    // background |
    {
        _background = lcg::Image( 60, 30 );
        _background.beginSymbols()
                .addSymbols( "------------------------------------------------------------" )
                .addSymbols( "|                        Main menu                         |" )
                .addSymbols( "|----------------------------------------------------------|" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|       *                                                  |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|           *                                              |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|       *                                                  |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|           *                                              |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|       *                                                  |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|           *                                              |" )
                .addSymbols( "|        ***                                               |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|==========================================================|" )
                .addSymbols( "| Advice:                                                  |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "|                                                          |" )
                .addSymbols( "------------------------------------------------------------" );
        _background.beginColors()
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "BYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYB" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "B YYYYYYY                                                  B" )
                .addColors( "B                                                          B" )
                .addColors( "B                                                          B" )
                .addColors( "B                                                          B" )
                .addColors( "B                                                          B" )
                .addColors( "B                                                          B" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" );
        _background.beginBgColors()
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
                .addBgColors( "b                                                          b" )
                .addBgColors( "b                                                          b" )
                .addBgColors( "b                                                          b" )
                .addBgColors( "b                                                          b" )
                .addBgColors( "b                                                          b" )
                .addBgColors( "b                                                          b" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    // cursor     |
    {
        _cursor[0] = lcg::Image( 58, 7 );
        _cursor[0].beginSymbols().beginBgColors() // #000
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("S                                                        s")
                .addBgColors("S                                                        s")
                .addBgColors("s                                                        S")
                .addBgColors("s  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  S");
        _cursor[1] = lcg::Image( 58, 7 );
        _cursor[1].beginSymbols().beginBgColors() // #001
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors(" ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssS")
                .addBgColors("                                                         S")
                .addBgColors("S                                                         ")
                .addBgColors("S                                                         ")
                .addBgColors("s                                                        s")
                .addBgColors("s                                                        s")
                .addBgColors("  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SS");
        _cursor[2] = lcg::Image( 58, 7 );
        _cursor[2].beginSymbols().beginBgColors() // #002
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ss")
                .addBgColors("S                                                        S")
                .addBgColors("S                                                        S")
                .addBgColors("s                                                         ")
                .addBgColors("s                                                         ")
                .addBgColors("                                                         s")
                .addBgColors(" SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSs");
        _cursor[3] = lcg::Image( 58, 7 );
        _cursor[3].beginSymbols().beginBgColors() // #003
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("S  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  s")
                .addBgColors("S                                                        s")
                .addBgColors("s                                                        S")
                .addBgColors("s                                                        S")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss");
        _cursor[4] = lcg::Image( 58, 7 );
        _cursor[4].beginSymbols().beginBgColors() // #004
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("SS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ")
                .addBgColors("s                                                        s")
                .addBgColors("s                                                        s")
                .addBgColors("                                                         S")
                .addBgColors("                                                         S")
                .addBgColors("S                                                         ")
                .addBgColors("Sss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss ");
        _cursor[5] = lcg::Image( 58, 7 );
        _cursor[5].beginSymbols().beginBgColors() // #005
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("sSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS  ssSS ")
                .addBgColors("s                                                         ")
                .addBgColors("                                                         s")
                .addBgColors("                                                         s")
                .addBgColors("S                                                        S")
                .addBgColors("S                                                        S")
                .addBgColors("ss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  SSss  ");
//        _cursor[6] = lcg::Image( 58, 7 );
//        _cursor[6].beginSymbols().beginBgColors() // #006
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("  S     S     S     S     S     S     S     S     S     S ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                         S")
//                .addBgColors("    S     S     S     S     S     S     S     S     S     ");
//        _cursor[7] = lcg::Image( 58, 7 );
//        _cursor[7].beginSymbols().beginBgColors() // #007
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("  Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("s                                                         ")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                         S")
//                .addBgColors("   sS    sS    sS    sS    sS    sS    sS    sS    sS    s");
//        _cursor[8] = lcg::Image( 58, 7 );
//        _cursor[8].beginSymbols().beginBgColors() // #008
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("  sS    sS    sS    sS    sS    sS    sS    sS    sS    sS")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("S                                                         ")
//                .addBgColors("s                                                         ")
//                .addBgColors("                                                         s")
//                .addBgColors("   Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    S");
//        _cursor[9] = lcg::Image( 58, 7 );
//        _cursor[9].beginSymbols().beginBgColors() // #009
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("   S     S     S     S     S     S     S     S     S     S")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("   S     S     S     S     S     S     S     S     S     S");
//        _cursor[10] = lcg::Image( 58, 7 );
//        _cursor[10].beginSymbols().beginBgColors() // #010
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("   Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    S")
//                .addBgColors("                                                         s")
//                .addBgColors("s                                                         ")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("  sS    sS    sS    sS    sS    sS    sS    sS    sS    sS");
//        _cursor[11] = lcg::Image( 58, 7 );
//        _cursor[11].beginSymbols().beginBgColors() // #011
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("   sS    sS    sS    sS    sS    sS    sS    sS    sS    s")
//                .addBgColors("                                                         S")
//                .addBgColors("S                                                         ")
//                .addBgColors("s                                                         ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("  Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss");
//        _cursor[12] = lcg::Image( 58, 7 );
//        _cursor[12].beginSymbols().beginBgColors() // #012
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("    S     S     S     S     S     S     S     S     S     ")
//                .addBgColors("                                                         S")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("  S     S     S     S     S     S     S     S     S     S ");
//        _cursor[13] = lcg::Image( 58, 7 );
//        _cursor[13].beginSymbols().beginBgColors() // #013
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    ")
//                .addBgColors("s                                                        S")
//                .addBgColors("S                                                        s")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors(" sS    sS    sS    sS    sS    sS    sS    sS    sS    sS ");
//        _cursor[14] = lcg::Image( 58, 7 );
//        _cursor[14].beginSymbols().beginBgColors() // #014
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("    sS    sS    sS    sS    sS    sS    sS    sS    sS    ")
//                .addBgColors("S                                                        s")
//                .addBgColors("s                                                        S")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors(" Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss ");
//        _cursor[15] = lcg::Image( 58, 7 );
//        _cursor[15].beginSymbols().beginBgColors() // #015
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("     S     S     S     S     S     S     S     S     S    ")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                         S")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors(" S     S     S     S     S     S     S     S     S     S  ");
//        _cursor[16] = lcg::Image( 58, 7 );
//        _cursor[16].beginSymbols().beginBgColors() // #016
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("s    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss   ")
//                .addBgColors("S                                                         ")
//                .addBgColors("                                                         S")
//                .addBgColors("                                                         s")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("sS    sS    sS    sS    sS    sS    sS    sS    sS    sS  ");
//        _cursor[17] = lcg::Image( 58, 7 );
//        _cursor[17].beginSymbols().beginBgColors() // #017
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addSymbols ("                                                          ")
//                .addBgColors("S    sS    sS    sS    sS    sS    sS    sS    sS    sS   ")
//                .addBgColors("s                                                         ")
//                .addBgColors("                                                         s")
//                .addBgColors("                                                         S")
//                .addBgColors("                                                          ")
//                .addBgColors("                                                          ")
//                .addBgColors("Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss  ");
    }
#ifdef DEPRECATE
    // cursor     |
    {
        _cursor[0] = lcg::Image( 58, 7 );
        _cursor[0].beginSymbols().beginBgColors() // #000
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("S     S     S     S     S     S     S     S     S     S   ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                         S")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("S     S     S     S     S     S     S     S     S     S   ");
        _cursor[1] = lcg::Image( 58, 7 );
        _cursor[1].beginSymbols().beginBgColors() // #001
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss  ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                         S")
                .addBgColors("                                                         s")
                .addBgColors("s                                                         ")
                .addBgColors("S    sS    sS    sS    sS    sS    sS    sS    sS    sS   ");
        _cursor[2] = lcg::Image( 58, 7 );
        _cursor[2].beginSymbols().beginBgColors() // #002
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("sS    sS    sS    sS    sS    sS    sS    sS    sS    sS  ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                         s")
                .addBgColors("                                                         S")
                .addBgColors("S                                                         ")
                .addBgColors("s    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss   ");
        _cursor[3] = lcg::Image( 58, 7 );
        _cursor[3].beginSymbols().beginBgColors() // #003
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors(" S     S     S     S     S     S     S     S     S     S  ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                         S")
                .addBgColors("S                                                         ")
                .addBgColors("     S     S     S     S     S     S     S     S     S    ");
        _cursor[4] = lcg::Image( 58, 7 );
        _cursor[4].beginSymbols().beginBgColors() // #004
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors(" Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("s                                                        S")
                .addBgColors("S                                                        s")
                .addBgColors("    sS    sS    sS    sS    sS    sS    sS    sS    sS    ");
        _cursor[5] = lcg::Image( 58, 7 );
        _cursor[5].beginSymbols().beginBgColors() // #005
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors(" sS    sS    sS    sS    sS    sS    sS    sS    sS    sS ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("S                                                        s")
                .addBgColors("s                                                        S")
                .addBgColors("    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    ");
        _cursor[6] = lcg::Image( 58, 7 );
        _cursor[6].beginSymbols().beginBgColors() // #006
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("  S     S     S     S     S     S     S     S     S     S ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("S                                                         ")
                .addBgColors("                                                         S")
                .addBgColors("    S     S     S     S     S     S     S     S     S     ");
        _cursor[7] = lcg::Image( 58, 7 );
        _cursor[7].beginSymbols().beginBgColors() // #007
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("  Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("s                                                         ")
                .addBgColors("S                                                         ")
                .addBgColors("                                                         S")
                .addBgColors("   sS    sS    sS    sS    sS    sS    sS    sS    sS    s");
        _cursor[8] = lcg::Image( 58, 7 );
        _cursor[8].beginSymbols().beginBgColors() // #008
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("  sS    sS    sS    sS    sS    sS    sS    sS    sS    sS")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("S                                                         ")
                .addBgColors("s                                                         ")
                .addBgColors("                                                         s")
                .addBgColors("   Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    S");
        _cursor[9] = lcg::Image( 58, 7 );
        _cursor[9].beginSymbols().beginBgColors() // #009
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("   S     S     S     S     S     S     S     S     S     S")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("S                                                         ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("   S     S     S     S     S     S     S     S     S     S");
        _cursor[10] = lcg::Image( 58, 7 );
        _cursor[10].beginSymbols().beginBgColors() // #010
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("   Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    S")
                .addBgColors("                                                         s")
                .addBgColors("s                                                         ")
                .addBgColors("S                                                         ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("  sS    sS    sS    sS    sS    sS    sS    sS    sS    sS");
        _cursor[11] = lcg::Image( 58, 7 );
        _cursor[11].beginSymbols().beginBgColors() // #011
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("   sS    sS    sS    sS    sS    sS    sS    sS    sS    s")
                .addBgColors("                                                         S")
                .addBgColors("S                                                         ")
                .addBgColors("s                                                         ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("  Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss");
        _cursor[12] = lcg::Image( 58, 7 );
        _cursor[12].beginSymbols().beginBgColors() // #012
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("    S     S     S     S     S     S     S     S     S     ")
                .addBgColors("                                                         S")
                .addBgColors("S                                                         ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("  S     S     S     S     S     S     S     S     S     S ");
        _cursor[13] = lcg::Image( 58, 7 );
        _cursor[13].beginSymbols().beginBgColors() // #013
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    ")
                .addBgColors("s                                                        S")
                .addBgColors("S                                                        s")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors(" sS    sS    sS    sS    sS    sS    sS    sS    sS    sS ");
        _cursor[14] = lcg::Image( 58, 7 );
        _cursor[14].beginSymbols().beginBgColors() // #014
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("    sS    sS    sS    sS    sS    sS    sS    sS    sS    ")
                .addBgColors("S                                                        s")
                .addBgColors("s                                                        S")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors(" Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss ");
        _cursor[15] = lcg::Image( 58, 7 );
        _cursor[15].beginSymbols().beginBgColors() // #015
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("     S     S     S     S     S     S     S     S     S    ")
                .addBgColors("S                                                         ")
                .addBgColors("                                                         S")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors(" S     S     S     S     S     S     S     S     S     S  ");
        _cursor[16] = lcg::Image( 58, 7 );
        _cursor[16].beginSymbols().beginBgColors() // #016
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("s    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss   ")
                .addBgColors("S                                                         ")
                .addBgColors("                                                         S")
                .addBgColors("                                                         s")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("sS    sS    sS    sS    sS    sS    sS    sS    sS    sS  ");
        _cursor[17] = lcg::Image( 58, 7 );
        _cursor[17].beginSymbols().beginBgColors() // #017
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("S    sS    sS    sS    sS    sS    sS    sS    sS    sS   ")
                .addBgColors("s                                                         ")
                .addBgColors("                                                         s")
                .addBgColors("                                                         S")
                .addBgColors("                                                          ")
                .addBgColors("                                                          ")
                .addBgColors("Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss    Ss  ");
    }
#endif // DEPRECATE
    return;
}
