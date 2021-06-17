#include "scene_menu.h"
#include <sstream>

SceneMenu::SceneMenu()
{
}
SceneMenu::~SceneMenu()
{
}

void SceneMenu::onInit()
{
    initTips();
    return;
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
        root -> addChild( tip = new lcg::Text("tip") );
        for( int i = 0; i < AMOUNT_MENUITEMS; i++ )
        {
            std::stringstream ss;
            ss << i+1;
            root -> addChild( items[i] = new lcg::Sprite("item_"+ss.str()) );
        }
        loadBackground();
        loadCursor();
        loadItems();
        loadTips();
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
void SceneMenu::loadItems()
{
    items[0]->setImage( rsc.itemStart() );
    items[0]->setPosition( 2, 4+0*6);
    items[1]->setImage( rsc.itemConfig() );
    items[1]->setPosition( 2, 4+1*6);
    items[2]->setImage( rsc.itemExit() );
    items[2]->setPosition( 2, 4+2*6);
    return;
}
void SceneMenu::initTips()
{
    //                     123456789012345678901234567890123456789012345678
    tipStrings.push_back( "You can select a menu item by moving the cursor \n\n"
                          "with the arrows (up / down) or buttons W and S, \n\n"
                          "confirm the selection by pressing Enter." );
    tipStrings.push_back( "The START menu item starts the game." );
    tipStrings.push_back( "The CONFIG menu item shows the configuration of \n\n"
                          "the game actions." );
    tipStrings.push_back( "The EXIT menu item allows you to exit the game." );
    timeShowTip = TIME_SHOWTIP;
    timeHideTip = 0.0f;
}
void SceneMenu::loadTips()
{
    if( nullptr != tip )
    {
        tip -> setPosition( 10, 23 );
        tip -> setColor( lcg::ColorID::light_yellow );
        tip -> setBackgroundColor( lcg::ColorID::black  );
        tip -> setString( getTip() );
        tip -> setVisible( timeShowTip > 0.0f );
    }
    return;
}
void SceneMenu::processTips( float dt )
{
    if( nullptr != tip && !tipStrings.empty() )
    {
        if( timeShowTip > 0.0f )
        {
            timeShowTip -= dt;
            if( timeShowTip <= 0.0f )
            {
                timeHideTip = TIME_HIDETIP;
                tip -> setVisible( false );
                ++tipSelected %= tipStrings.size();
            }
        }
        if( timeHideTip > 0.0f )
        {
            timeHideTip -= dt;
            if( timeHideTip <= 0.0f )
            {
                timeShowTip = TIME_SHOWTIP;
                tip -> setString( getTip() );
                tip -> setVisible( true );
            }
        }
    }
    return;
}
void SceneMenu::onProcess( float dt )
{
    cursorAnim.update( dt );
    if( nullptr != cursor )
        cursor->setImage( cursorAnim.getImage() );
    processTips( dt );
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
                .addBgColors("ssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSS")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("Sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("Sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("sbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbS");
        _cursor[1] = lcg::Image( 58, 7 );
        _cursor[1].beginSymbols().beginBgColors() // #001
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("bssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssS")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("Sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("Sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("bbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSS");
        _cursor[2] = lcg::Image( 58, 7 );
        _cursor[2].beginSymbols().beginBgColors() // #002
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("bbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbss")
                .addBgColors("SbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("SbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("bSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSs");
        _cursor[3] = lcg::Image( 58, 7 );
        _cursor[3].beginSymbols().beginBgColors() // #003
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("SbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbs")
                .addBgColors("Sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("SSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSss");
        _cursor[4] = lcg::Image( 58, 7 );
        _cursor[4].beginSymbols().beginBgColors() // #004
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("SSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbb")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("Sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("SssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssb");
        _cursor[5] = lcg::Image( 58, 7 );
        _cursor[5].beginSymbols().beginBgColors() // #005
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addSymbols ("                                                          ")
                .addBgColors("sSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSbbssSSb")
                .addBgColors("sbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbs")
                .addBgColors("SbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("SbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbS")
                .addBgColors("ssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbbSSssbb");
    }
    // itemStart  |
    {
        _itemStart = lcg::Image( 56, 5 );
        _itemStart.beginSymbols().beginColors().beginBgColors()
                .addSymbols ( "            @@@@@ @@@@@@     @@ @@@@   @@@@@@           " )
                .addSymbols ( "           @        @@      @ @ @@  @    @@             " )
                .addSymbols ( "            @@@@    @@     @@@@ @@@@     @@             " )
                .addSymbols ( "                @   @@    @   @ @@  @    @@             " )
                .addSymbols ( "           @@@@@    @@   @    @ @@   @   @@             " )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    // itemResume |
    {
        _itemResume = lcg::Image( 56, 5 );
        _itemResume.beginSymbols().beginColors().beginBgColors()
                .addSymbols ( "      @@@@   @@@@@@  @@@@@ @@   @ @@     @@ @@@@@@      " )
                .addSymbols ( "      @@  @  @@     @      @@   @ @@@   @@@ @@          " )
                .addSymbols ( "      @@@@   @@@@    @@@@  @@   @ @@ @ @ @@ @@@@        " )
                .addSymbols ( "      @@  @  @@          @  @  @  @@  @  @@ @@          " )
                .addSymbols ( "      @@   @ @@@@@@ @@@@@    @@   @@     @@ @@@@@@      " )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    // itemConfig |
    {
        _itemConfig = lcg::Image( 56, 5 );
        _itemConfig.beginSymbols().beginColors().beginBgColors()
                .addSymbols ( "         @@@@   @@@@  @@   @ @@@@@@ @@@@  @@@@          " )
                .addSymbols ( "        @@   @ @@  @@ @@@  @ @@      @@  @@   @         " )
                .addSymbols ( "        @@     @@  @@ @@ @ @ @@@@    @@  @@             " )
                .addSymbols ( "        @@   @ @@  @@ @@  @@ @@      @@  @@  @@         " )
                .addSymbols ( "         @@@@   @@@@  @@   @ @@     @@@@  @@@@@         " )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    // itemExit   |
    {
        _itemExit = lcg::Image( 56, 5 );
        _itemExit.beginSymbols().beginColors().beginBgColors()
                .addSymbols ( "               @@@@@@ @@  @@ @@@@ @@@@@@                " )
                .addSymbols ( "               @@      @  @   @@    @@                  " )
                .addSymbols ( "               @@@@     @@    @@    @@                  " )
                .addSymbols ( "               @@      @  @   @@    @@                  " )
                .addSymbols ( "               @@@@@@ @@  @@ @@@@   @@                  " )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addColors  ( "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    return;
}
