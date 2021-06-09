#include "game.h"
#include <iostream>

Game::Game( int width, int height )
    : Core( width, height )
{
}
void Game::onInit()
{
    initStartApp();
    initMainMenu();
    state.refLevel( LevelID::startedMainMenu )
            .attachScene( &sceneStartApp )
            .attachScene( &sceneMenu );

//    std::cout << "after engine initialized..." << std::endl;
//    std::cout << "surface size: w(" << getSurface().size().width << "); h("
//              << getSurface().size().height << ")" << std::endl;

//    setBgColor( lcg::ColorID::gray );
//    setFgColor( lcg::ColorID::blue );
//    putText(  0, 0, "1 - line" );
//    setFgColor( lcg::ColorID::sky );
//    putText(  1, 1, "2 - line" );
//    setFgColor( lcg::ColorID::red );
//    putText(  2, 2, "3 - line" );
//    setFgColor( lcg::ColorID::pink );
//    putText(  3, 3, "4 - line" );
//    setFgColor( lcg::ColorID::green );
//    putText(  4, 4, "5 - line" );
//    setFgColor( lcg::ColorID::yellow );
//    putText(  5, 5, "6 - line" );
//    setFgColor( lcg::ColorID::light_blue );
//    putText(  6, 6, "7 - line" );
//    setFgColor( lcg::ColorID::light_sky );
//    putText(  7, 7, "8 - line" );
//    setFgColor( lcg::ColorID::light_red );
//    putText(  8, 8, "9 - line" );
//    setFgColor( lcg::ColorID::light_pink );
//    putText(  9, 9, "10 - line" );
//    setFgColor( lcg::ColorID::black );
//    putText( 10, 10, "This is test!!!" );

    // rabbit
//    setBgColor( lcg::ColorID::black );
//    setFgColor( lcg::ColorID::sky );
//    putText( 30, 5, "   /\\/\\" );
//    putText( 30, 6, "   (=o;o)" );
//    putText( 30, 7, "===(\"(\")(\")" );

//    swapBuffers();

    //
//    setBgColor( lcg::ColorID::black );
//    setFgColor( lcg::ColorID::sky );
//    putText( 10, 4+0,  "            §§§§§§§§§§§§§§§§§§                                                                           " );
//    putText( 10, 4+1,  "          §§§§§§§§§§§§§§§§§§§§§§§§                                                                       " );
//    putText( 10, 4+2,  "        §§§§§§§§§§§§§§§§§§§§§§§§§§§§                                                                     " );
//    putText( 10, 4+3,  "      §§§$§§§§§§         §§§§§§§§§§§§                                                                    " );
//    putText( 10, 4+4,  "      §§$§$§§§§              §§§§§§§§§                                                                   " );
//    putText( 10, 4+5,  "     §§$§§$§§§                §§§§§§§§                                                                   " );
//    putText( 10, 4+6,  "    §§$§§§§$§§§               §§§§§§§§                                                                   " );
//    putText( 10, 4+7,  "   §§$§§§§$§§§§               §§§§§§§§                                                                   " );
//    putText( 10, 4+8,  "   §§§$§§$§§§§               §§§§§§§§§                                                                   " );
//    putText( 10, 4+9,  "  (O)§§$§§(O)               §§§§§§§§§                                                                    " );
//    putText( 10, 4+10, "   §§§$§$§§§               §§§§§§§§§                                                                     " );
//    putText( 10, 4+11, "    §§§§§§§               §§§§§§§§§                                          KK                          " );
//    putText( 10, 4+12, "   §§§§§§§               §§§§§§§§§                                          kKK                          " );
//    putText( 10, 4+13, "    §§§§               §§§§§§§§§§                                           kKK                          " );
//    putText( 10, 4+14, "     $               §§§§§§§§§§§                                            kKK                          " );
//    putText( 10, 4+15, "    $              §§§§§§§§§§§                                              KKk                          " );
//    putText( 10, 4+16, "    $            §§§§§§§§§§§                                                KKk                          " );
//    putText( 10, 4+17, "   $           §§§§§§§§§§§                                                 kKKk                          " );
//    putText( 10, 4+18, "  $ $        §§§§§§§§§§§                                                   kKK                 eEEEe     " );
//    putText( 10, 4+19, "           §§§§§§§§§§§                                          aAAA       kKK      kKK       EEEEEE     " );
//    putText( 10, 4+20, "         §§§§§§§§§§§                    NN                     AAAAAa      kKk     kKKK      EEEe EE     " );
//    putText( 10, 4+21, "       §§§§§§§§§§§                      NN    nNNNn           AAAa aAA     kKk    KKKKk     EEe  eEE     " );
//    putText( 10, 4+22, "     §§§§§§§§§§§                        NN   nNNNNNn         AAA    AA     KKk   KKKk      eEE   EEe     " );
//    putText( 10, 4+23, "   §§§§§§§§§§§                          NN   NNn NNN        aAA     AA     KKk kKKKk       EEe eEEe      " );
//    putText( 10, 4+24, "  §§§§§§§§§§§                           NN  NNn  nNNn      aAAa    aAA     KK kKKKk       eEE eEEe       " );
//    putText( 10, 4+25, " §§§§§§§§§§§                           nNN nNn    NNn      AAa     AAA     KKkKKKk        EEeeEEe        " );
//    putText( 10, 4+26, " §§§§§§§§§§§                           nNN NN     NNn     aAA     aAAA     KKKKKKk        EEEEE          " );
//    putText( 10, 4+27, "  §§§§§§§§§§§                          nNnnNn     NNN     AAa    aAAAA    kKKkkKKKk       EEEe     eE    " );
//    putText( 10, 4+28, "   §§§§§§§§§§§               §§§§§§§§  nNnNN      NNN     AA    aAAaAA    KKk  kKKKk      EE       EE    " );
//    putText( 10, 4+29, "      §§§§§§§§§§§          §§§§§§§     NNnNn      nNNn    AA   aAAa AAa   KK    kKKKk     EEe    eEEe    " );
//    putText( 10, 4+30, "          §§§§§§§§§§§§§§§§§§§§§        NNNN       nNNNNN  AAa aAAa  AAA   KK     kKKKk    EEEe eEEEe     " );
//    putText( 10, 4+31, "              §§§§§§§§§§§§§§           NNNn        nNNNn  AAAAAAa   aAAA  KK      kKKKKK  eEEEEEEEe      " );
//    putText( 10, 4+32, "                  §§§§§§§              NNn                 AAAAa     AAa  KK       kKKKk   eEEEEe        " );

//    setFgColor( lcg::ColorID::white );
//    putText( 44, 4+41, "PRESS (ENTER) KEY TO CONTINUE..." );


    //    swapBuffers();
}

void Game::initStartApp()
{
    lcg::Group* root = nullptr;
    lcg::Sprite* logotype = nullptr;
    lcg::Text* invitation = nullptr;

    sceneStartApp.setRoot( root = new lcg::Group("root") );
    root->setPosition(0, 0);
    root->addChild( logotype = new lcg::Sprite("logotype") );
    root->addChild( invitation = new lcg::Text("invitation") );

    invitation->setData( Pos(44, 45), "PRESS (ENTER) KEY TO CONTINUE...", lcg::ColorID::white );

    //  1234567890          1234567890          1234567890          1234567890          1234567890          12345
    // "                  §§§§§§§              NNn                 AAAAa     AAa  KK       kKKKk   eEEEEe        "
    lcg::Image logo( 105, 33 );
    logo.beginSymbols()
            .addSymbols("            §§§§§§§§§§§§§§§§§§                                                                           ")
            .addSymbols("          §§§§§§§§§§§§§§§§§§§§§§§§                                                                       ")
            .addSymbols("        §§§§§§§§§§§§§§§§§§§§§§§§§§§§                                                                     ")
            .addSymbols("      §§§$§§§§§§         §§§§§§§§§§§§                                                                    ")
            .addSymbols("      §§$§$§§§§              §§§§§§§§§                                                                   ")
            .addSymbols("     §§$§§$§§§                §§§§§§§§                                                                   ")
            .addSymbols("    §§$§§§§$§§§               §§§§§§§§                                                                   ")
            .addSymbols("   §§$§§§§$§§§§               §§§§§§§§                                                                   ")
            .addSymbols("   §§§$§§$§§§§               §§§§§§§§§                                                                   ")
            .addSymbols("  (O)§§$§§(O)               §§§§§§§§§                                                                    ")
            .addSymbols("   §§§$§$§§§               §§§§§§§§§                                                                     ")
            .addSymbols("    §§§§§§§               §§§§§§§§§                                          KK                          ")
            .addSymbols("   §§§§§§§               §§§§§§§§§                                          kKK                          ")
            .addSymbols("    §§§§               §§§§§§§§§§                                           kKK                          ")
            .addSymbols("     $               §§§§§§§§§§§                                            kKK                          ")
            .addSymbols("    $              §§§§§§§§§§§                                              KKk                          ")
            .addSymbols("    $            §§§§§§§§§§§                                                KKk                          ")
            .addSymbols("   $           §§§§§§§§§§§                                                 kKKk                          ")
            .addSymbols("  $ $        §§§§§§§§§§§                                                   kKK                 eEEEe     ")
            .addSymbols("           §§§§§§§§§§§                                          aAAA       kKK      kKK       EEEEEE     ")
            .addSymbols("         §§§§§§§§§§§                    NN                     AAAAAa      kKk     kKKK      EEEe EE     ")
            .addSymbols("       §§§§§§§§§§§                      NN    nNNNn           AAAa aAA     kKk    KKKKk     EEe  eEE     ")
            .addSymbols("     §§§§§§§§§§§                        NN   nNNNNNn         AAA    AA     KKk   KKKk      eEE   EEe     ")
            .addSymbols("   §§§§§§§§§§§                          NN   NNn NNN        aAA     AA     KKk kKKKk       EEe eEEe      ")
            .addSymbols("  §§§§§§§§§§§                           NN  NNn  nNNn      aAAa    aAA     KK kKKKk       eEE eEEe       ")
            .addSymbols(" §§§§§§§§§§§                           nNN nNn    NNn      AAa     AAA     KKkKKKk        EEeeEEe        ")
            .addSymbols(" §§§§§§§§§§§                           nNN NN     NNn     aAA     aAAA     KKKKKKk        EEEEE          ")
            .addSymbols("  §§§§§§§§§§§                          nNnnNn     NNN     AAa    aAAAA    kKKkkKKKk       EEEe     eE    ")
            .addSymbols("   §§§§§§§§§§§               §§§§§§§§  nNnNN      NNN     AA    aAAaAA    KKk  kKKKk      EE       EE    ")
            .addSymbols("      §§§§§§§§§§§          §§§§§§§     NNnNn      nNNn    AA   aAAa AAa   KK    kKKKk     EEe    eEEe    ")
            .addSymbols("          §§§§§§§§§§§§§§§§§§§§§        NNNN       nNNNNN  AAa aAAa  AAA   KK     kKKKk    EEEe eEEEe     ")
            .addSymbols("              §§§§§§§§§§§§§§           NNNn        nNNNn  AAAAAAa   aAAA  KK      kKKKKK  eEEEEEEEe      ")
            .addSymbols("                  §§§§§§§              NNn                 AAAAa     AAa  KK       kKKKk   eEEEEe        ");
    logo.beginColors()
            .addColors ("            GGGGGGGGGGGGGGGGGG                                                                           ")
            .addColors ("          GGGGGGGGGGGGGGGGGGGGGGGG                                                                       ")
            .addColors ("        GGGGGGGGGGGGGGGGGGGGGGGGGGGG                                                                     ")
            .addColors ("      GGGGGGGGGG         GGGGGGGGGGGG                                                                    ")
            .addColors ("      GGGGGGGGG              GGGGGGGGG                                                                   ")
            .addColors ("     GGGGGGGGG                GGGGGGGG                                                                   ")
            .addColors ("    GGGGGGGGGGG               GGGGGGGG                                                                   ")
            .addColors ("   GGGGGGGGGGGG               GGGGGGGG                                                                   ")
            .addColors ("   GGGGGGGGGGG               GGGGGGGGG                                                                   ")
            .addColors ("  YYYGGGGGYYY               GGGGGGGGG                                                                    ")
            .addColors ("   GGGGGGGGG               GGGGGGGGG                                                                     ")
            .addColors ("    GGGGGGG               GGGGGGGGG                                          YY                          ")
            .addColors ("   GGGGGGG               GGGGGGGGG                                          yYY                          ")
            .addColors ("    GGGG               GGGGGGGGGG                                           yYY                          ")
            .addColors ("     r               GGGGGGGGGGG                                            yYY                          ")
            .addColors ("    r              GGGGGGGGGGG                                              YYy                          ")
            .addColors ("    r            GGGGGGGGGGG                                                YYy                          ")
            .addColors ("   r           GGGGGGGGGGG                                                 yYYy                          ")
            .addColors ("  r r        GGGGGGGGGGG                                                   yYY                 yYYYy     ")
            .addColors ("           GGGGGGGGGGG                                          yYYY       yYY      yYY       YYYYYY     ")
            .addColors ("         GGGGGGGGGGG                    YY                     YYYYYy      yYy     yYYY      YYYy YY     ")
            .addColors ("       GGGGGGGGGGG                      YY    yYYYy           YYYy yYY     yYy    YYYYy     YYy  yYY     ")
            .addColors ("     GGGGGGGGGGG                        YY   yYYYYYy         YYY    YY     YYy   YYYy      yYY   YYy     ")
            .addColors ("   GGGGGGGGGGG                          YY   YYy YYY        yYY     YY     YYy yYYYy       YYy yYYy      ")
            .addColors ("  GGGGGGGGGGG                           YY  YYy  yYYy      yYYy    yYY     YY yYYYy       yYY yYYy       ")
            .addColors (" GGGGGGGGGGG                           yYY yYy    YYy      YYy     YYY     YYyYYYy        YYyyYYy        ")
            .addColors (" GGGGGGGGGGG                           yYY YY     YYy     yYY     yYYY     YYYYYYy        YYYYY          ")
            .addColors ("  GGGGGGGGGGG                          yYyyYy     YYY     YYy    yYYYY    yYYyyYYYy       YYYy     yY    ")
            .addColors ("   GGGGGGGGGGG               GGGGGGGG  yYyYY      YYY     YY    yYYyYY    YYy  yYYYy      YY       YY    ")
            .addColors ("      GGGGGGGGGGG          GGGGGGG     YYyYy      yYYy    YY   yYYy YYy   YY    yYYYy     YYy    yYYy    ")
            .addColors ("          GGGGGGGGGGGGGGGGGGGGG        YYYY       yYYYYY  YYy yYYy  YYY   YY     yYYYy    YYYy yYYYy     ")
            .addColors ("              GGGGGGGGGGGGGG           YYYy        yYYYy  YYYYYYy   yYYY  YY      yYYYYY  yYYYYYYYy      ")
            .addColors ("                  GGGGGGG              YYy                 YYYYy     YYy  YY       yYYYy   yYYYYy        ");
    logotype->setImage( logo );
    logotype->setPosition(7, 5);
}
void Game::initMainMenu()
{
    lcg::Group* root = nullptr;
    lcg::Group* menu = nullptr;
    lcg::Sprite* menuBgr = nullptr;

    sceneMenu.setRoot( root = new lcg::Group("root") );
    root->setPosition( 49, 25 );
    root->addChild( menuBgr = new lcg::Sprite("background") );
    root->addChild( menu = new lcg::Group("menu") );
    menu->setPosition(1, 4);
    menu->addChild( mainMenu[0] = new lcg::Text("MM_item01") );
    menu->addChild( mainMenu[1] = new lcg::Text("MM_item02") );
    menu->addChild( mainMenu[2] = new lcg::Text("MM_item03") );

    mainMenu[0]->setData( Pos(0, 0), "       Start      ", lcg::ColorID::light_sky, lcg::ColorID::red );
    mainMenu[1]->setData( Pos(0, 2), "       Load       ",  lcg::ColorID::light_sky );
    mainMenu[2]->setData( Pos(0, 4), "       Exit       ",  lcg::ColorID::light_sky );

    lcg::Image background( 20, 11 );
    background.beginSymbols()
            .addSymbols( "====================" )
            .addSymbols( "|     Main menu    |" )
            .addSymbols( "====================" )
            .addSymbols( "|                  |" )
            .addSymbols( "|                  |" )
            .addSymbols( "|                  |" )
            .addSymbols( "|                  |" )
            .addSymbols( "|                  |" )
            .addSymbols( "|                  |" )
            .addSymbols( "|                  |" )
            .addSymbols( "====================" );
    background.beginColors()
            .addColors( "RRRRRRRRRRRRRRRRRRRR" )
            .addColors( "RGGGGGGGGGGGGGGGGGGR" )
            .addColors( "RRRRRRRRRRRRRRRRRRRR" )
            .addColors( "R                  R" )
            .addColors( "R                  R" )
            .addColors( "R                  R" )
            .addColors( "R                  R" )
            .addColors( "R                  R" )
            .addColors( "R                  R" )
            .addColors( "R                  R" )
            .addColors( "RRRRRRRRRRRRRRRRRRRR" );
    menuBgr->setImage( background );
    menuBgr->setPosition(0, 0);

//    if( scene.getRoot()->as<lcg::Group>() != nullptr )
//    {
//        std::cout << "children count: " << scene.getRoot()->as<lcg::Group>()->getChildren().size() << std::endl;
//        const lcg::Text* item = scene.getRoot()->as<lcg::Group>()
//                                ->getChild( "MM_item02" )->as<lcg::Text>();
//        if( nullptr != item )
//            std::cout << "select MM_item02: " << item->getData() << std::endl;
//    }
//    else
//        std::cout << "can not convert View to Group" << std::endl;
    return;
}
void Game::onStart()
{
}
void Game::onProcess()
{
}
void Game::onPostProcess()
{
}
void Game::onPrepareDraw()
{
    state.refLevel( LevelID::startedMainMenu ).beginScene();
}
const lcg::Scene* Game::getScene() const
{
    return( state.crefLevel( LevelID::startedMainMenu ).getScene() );
}
void Game::nextScene()
{
    state.refLevel( LevelID::startedMainMenu ).nextScene();
}
