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
//    lcg::Text* invitation = nullptr;

    sceneStartApp.setRoot( root = new lcg::Group("root") );
    root->setPosition(0, 0);
    root->addChild( logotype = new lcg::Sprite("logotype") );
//    root->addChild( invitation = new lcg::Text("invitation") );
//    invitation->setData( Pos(44, 45), "PRESS (ENTER) KEY TO CONTINUE...", lcg::ColorID::white );

    logo = lcg::Image( 120, 50 );
    logo.beginSymbols()
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                   §§§§§§§§§§§§§§§§§§                                                                                   ")
            .addSymbols("                 §§§§§§§§§§§§§§§§§§§§§§§§                                                                               ")
            .addSymbols("               §§§§§§§§§§§§§§§§§§§§§§§§§§§§                                                                             ")
            .addSymbols("             §§§$§§§§§§         §§§§§§§§§§§§                                                                            ")
            .addSymbols("             §§$§$§§§§              §§§§§§§§§                                                                           ")
            .addSymbols("            §§$§§$§§§                §§§§§§§§                                                                           ")
            .addSymbols("           §§$§§§§$§§§               §§§§§§§§                                                                           ")
            .addSymbols("          §§$§§§§$§§§§               §§§§§§§§                                                                           ")
            .addSymbols("          §§§$§§$§§§§               §§§§§§§§§                                                                           ")
            .addSymbols("         (O)§§$§§(O)               §§§§§§§§§                                                                            ")
            .addSymbols("          §§§$§$§§§               §§§§§§§§§                                                                             ")
            .addSymbols("           §§§§§§§               §§§§§§§§§                                          KK                                  ")
            .addSymbols("          §§§§§§§               §§§§§§§§§                                          kKK                                  ")
            .addSymbols("           §§§§               §§§§§§§§§§                                           kKK                                  ")
            .addSymbols("            $               §§§§§§§§§§§                                            kKK                                  ")
            .addSymbols("           $              §§§§§§§§§§§                                              KKk                                  ")
            .addSymbols("           $            §§§§§§§§§§§                                                KKk                                  ")
            .addSymbols("          $           §§§§§§§§§§§                                                 kKKk                                  ")
            .addSymbols("         $ $        §§§§§§§§§§§                                                   kKK                 eEEEe             ")
            .addSymbols("                  §§§§§§§§§§§                                          aAAA       kKK      kKK       EEEEEE             ")
            .addSymbols("                §§§§§§§§§§§                    NN                     AAAAAa      kKk     kKKK      EEEe EE             ")
            .addSymbols("              §§§§§§§§§§§                      NN    nNNNn           AAAa aAA     kKk    KKKKk     EEe  eEE             ")
            .addSymbols("            §§§§§§§§§§§                        NN   nNNNNNn         AAA    AA     KKk   KKKk      eEE   EEe             ")
            .addSymbols("          §§§§§§§§§§§                          NN   NNn NNN        aAA     AA     KKk kKKKk       EEe eEEe              ")
            .addSymbols("         §§§§§§§§§§§                           NN  NNn  nNNn      aAAa    aAA     KK kKKKk       eEE eEEe               ")
            .addSymbols("        §§§§§§§§§§§                           nNN nNn    NNn      AAa     AAA     KKkKKKk        EEeeEEe                ")
            .addSymbols("        §§§§§§§§§§§                           nNN NN     NNn     aAA     aAAA     KKKKKKk        EEEEE                  ")
            .addSymbols("         §§§§§§§§§§§                          nNnnNn     NNN     AAa    aAAAA    kKKkkKKKk       EEEe     eE            ")
            .addSymbols("          §§§§§§§§§§§               §§§§§§§§  nNnNN      NNN     AA    aAAaAA    KKk  kKKKk      EE       EE            ")
            .addSymbols("             §§§§§§§§§§§          §§§§§§§     NNnNn      nNNn    AA   aAAa AAa   KK    kKKKk     EEe    eEEe            ")
            .addSymbols("                 §§§§§§§§§§§§§§§§§§§§§        NNNN       nNNNNN  AAa aAAa  AAA   KK     kKKKk    EEEe eEEEe             ")
            .addSymbols("                     §§§§§§§§§§§§§§           NNNn        nNNNn  AAAAAAa   aAAA  KK      kKKKKK  eEEEEEEEe              ")
            .addSymbols("                         §§§§§§§              NNn                 AAAAa     AAa  KK       kKKKk   eEEEEe                ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ")
            .addSymbols("                                                                                                                        ");
    logo.beginColors()
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                   GGGGGGGGGGGGGGGGGG                                                                                   ")
            .addColors ("                 GGGGGGGGGGGGGGGGGGGGGGGG                                                                               ")
            .addColors ("               GGGGGGGGGGGGGGGGGGGGGGGGGGGG                                                                             ")
            .addColors ("             GGGGGGGGGG         GGGGGGGGGGGG                                                                            ")
            .addColors ("             GGGGGGGGG              GGGGGGGGG                                                                           ")
            .addColors ("            GGGGGGGGG                GGGGGGGG                                                                           ")
            .addColors ("           GGGGGGGGGGG               GGGGGGGG                                                                           ")
            .addColors ("          GGGGGGGGGGGG               GGGGGGGG                                                                           ")
            .addColors ("          GGGGGGGGGGG               GGGGGGGGG                                                                           ")
            .addColors ("         YYYGGGGGYYY               GGGGGGGGG                                                                            ")
            .addColors ("          GGGGGGGGG               GGGGGGGGG                                                                             ")
            .addColors ("           GGGGGGG               GGGGGGGGG                                          YY                                  ")
            .addColors ("          GGGGGGG               GGGGGGGGG                                          yYY                                  ")
            .addColors ("           GGGG               GGGGGGGGGG                                           yYY                                  ")
            .addColors ("            r               GGGGGGGGGGG                                            yYY                                  ")
            .addColors ("           r              GGGGGGGGGGG                                              YYy                                  ")
            .addColors ("           r            GGGGGGGGGGG                                                YYy                                  ")
            .addColors ("          r           GGGGGGGGGGG                                                 yYYy                                  ")
            .addColors ("         r r        GGGGGGGGGGG                                                   yYY                 yYYYy             ")
            .addColors ("                  GGGGGGGGGGG                                          yYYY       yYY      yYY       YYYYYY             ")
            .addColors ("                GGGGGGGGGGG                    YY                     YYYYYy      yYy     yYYY      YYYy YY             ")
            .addColors ("              GGGGGGGGGGG                      YY    yYYYy           YYYy yYY     yYy    YYYYy     YYy  yYY             ")
            .addColors ("            GGGGGGGGGGG                        YY   yYYYYYy         YYY    YY     YYy   YYYy      yYY   YYy             ")
            .addColors ("          GGGGGGGGGGG                          YY   YYy YYY        yYY     YY     YYy yYYYy       YYy yYYy              ")
            .addColors ("         GGGGGGGGGGG                           YY  YYy  yYYy      yYYy    yYY     YY yYYYy       yYY yYYy               ")
            .addColors ("        GGGGGGGGGGG                           yYY yYy    YYy      YYy     YYY     YYyYYYy        YYyyYYy                ")
            .addColors ("        GGGGGGGGGGG                           yYY YY     YYy     yYY     yYYY     YYYYYYy        YYYYY                  ")
            .addColors ("         GGGGGGGGGGG                          yYyyYy     YYY     YYy    yYYYY    yYYyyYYYy       YYYy     yY            ")
            .addColors ("          GGGGGGGGGGG               GGGGGGGG  yYyYY      YYY     YY    yYYyYY    YYy  yYYYy      YY       YY            ")
            .addColors ("             GGGGGGGGGGG          GGGGGGG     YYyYy      yYYy    YY   yYYy YYy   YY    yYYYy     YYy    yYYy            ")
            .addColors ("                 GGGGGGGGGGGGGGGGGGGGG        YYYY       yYYYYY  YYy yYYy  YYY   YY     yYYYy    YYYy yYYYy             ")
            .addColors ("                     GGGGGGGGGGGGGG           YYYy        yYYYy  YYYYYYy   yYYY  YY      yYYYYY  yYYYYYYYy              ")
            .addColors ("                         GGGGGGG              YYy                 YYYYy     YYy  YY       yYYYy   yYYYYy                ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ")
            .addColors ("                                                                                                                        ");
    logotype->setImage( &logo );
    logotype->setPosition(0, 0);

    root ->addChild( test = new lcg::Sprite("test") );
    test -> setPosition( 0, 0 );

    lcg::Image space(20, 10);
    space.beginSymbols().beginBgColors() // #000
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #001
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #002
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #003
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #004
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #005
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #006
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #007
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #008
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ")
            .addSymbols("                    ").addBgColors("                    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #009
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #010
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("    RR              ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #011
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("      RR            ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #012
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("        RR          ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #013
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("          RR        ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #014
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("            RR      ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #015
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("              RR    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #016
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                RR  ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #017
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                  RR");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #018
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                RR  ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #019
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("              RR    ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #020
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("            RR      ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #021
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("          RR        ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #022
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("        RR          ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #023
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("      RR            ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #024
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("    RR              ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #025
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("  RR                ");
    testAnim.addImage( space );
    space.beginSymbols().beginBgColors() // #026
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("                    ")
            .addSymbols("                    ").addBgColors("RR                  ");
    testAnim.addImage( space );
    testAnim.setSpeed( 14.0f );
    testAnim.setCycle( true );
    testAnim.setRestartFrame( 9 );

    root->addChild( conOut = new lcg::Text("conOut") );
    conOut -> setPosition( 30, 5 );

    root->addChild( invitation = new lcg::Sprite("invitation") );
    invitation -> setPosition( 44, 43 );

    lcg::Image invImg( std::string("PRESS (ENTER) KEY TO CONTINUE...").size(), 5 );
    invImg.beginSymbols().beginColors() // #000
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #001
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" RESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #002
            .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" R                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  ESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #003
            .addSymbols("PR                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("   SS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #004
            .addSymbols(" RE                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P  S                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("    S (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #005
            .addSymbols("  ES                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" R  S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P     (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #006
            .addSymbols("   SS                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" R    (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #007
            .addSymbols("    S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("   S  (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  E    ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" R                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #008
            .addSymbols("      (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("    S  E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("   S    NTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PR                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #009
            .addSymbols("      (E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("        N                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("    S    TER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P  S                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" RE                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #010
            .addSymbols("       EN                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("      (  T                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P         ER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" R  S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  ES                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #011
            .addSymbols("        NT                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P      E  E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" R    (    R) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("   SS                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #012
            .addSymbols("         TE                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PR      N  R                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  E    E    ) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("   S  (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("    S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #013
            .addSymbols("          ER                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols(" RE      T  )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("P  S    N     KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("    S  E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("      (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #014
            .addSymbols("           R)                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("  ES      E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PR  S    T    KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("        N                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("      (E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #015
            .addSymbols("            )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("   SS      R  K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRE       E    EY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("      (  T                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("       EN                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #016
            .addSymbols("              K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("    S       )  E                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRES  (    R    Y TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("       E  E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("        NT                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #017
            .addSymbols("              KE                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("      (         Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS  E    )     TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("        N  R                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("         TE                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #018
            .addSymbols("               EY               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("      (E      K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS   N         TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("         T  )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("          ER                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #019
            .addSymbols("                Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("       EN      E  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (  T    K    O CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("          E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("           R)                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #020
            .addSymbols("                  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("        NT      Y  O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (E  E    E     CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("           R  K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("            )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #021
            .addSymbols("                  TO            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("         TE                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (EN  R    Y    CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("            )  E                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("              K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #022
            .addSymbols("                   O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("          ER      T  C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENT  )         ONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("              KE                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #023
            .addSymbols("                     C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("           R)      O  O         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTE       T    NTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("              K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("               EY               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #024
            .addSymbols("                     CO         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("            )          N        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER  K    O    TINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("               E  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #025
            .addSymbols("                      ON        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("              K      C  T       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER)  E         INUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                Y  O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #026
            .addSymbols("                       NT       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("              KE      O  I      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER)   Y    C    NUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                  TO            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #027
            .addSymbols("                        TI      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("               EY      N  N     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) K       O    UE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                  T  C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                   O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #028
            .addSymbols("                         IN     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                Y       T  U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KE  T    N    E...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                   O  O         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                     C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #029
            .addSymbols("                          NU    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                  T      I  E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY  O    T    ...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                       N        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                     CO         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #030
            .addSymbols("                           UE   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                  TO      N  .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY        I    ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                     C  T       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                      ON        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #031
            .addSymbols("                            E.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                   O       U  . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY T  C    N    .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                      O  I      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                       NT       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #032
            .addSymbols("                             .. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                     C      E  .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO  O    U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                       N  N     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                        TI      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #033
            .addSymbols("                              ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                     CO      .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO   N    E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                        T  U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                         IN     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #034
            .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                      ON      . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO C  T    .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                         I  E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                          NU    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #035
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                       NT      .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CO  I    . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                          N  .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                           UE   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #036
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                        TI      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CON  N    .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                           U  . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                            E.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #037
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                         IN     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONT  U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                            E  .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                             .. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #038
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                          NU    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTI  E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                             .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                              ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #039
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                           UE   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTIN  .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                              . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #040
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                            E.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTINU  . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #041
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                             .. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTINUE  .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #042
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                              ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTINUE.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #043
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTINUE.. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invImg.beginSymbols().beginColors() // #044
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("PRESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
            .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    invitationAnim.addImage( invImg );
    invitationAnim.setSpeed( 12.0f );
    invitation->setImage( invitationAnim.getImage() );
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

    menuBackground = lcg::Image( 20, 11 );
    menuBackground.beginSymbols()
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
    menuBackground.beginColors()
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
    menuBgr->setImage( &menuBackground );
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
    testAnim.start();
    timeInvitation = 5.0f;
}
void Game::onProcess( float dt, DWORD delta, DWORD ticks )
{
    char str[100];

    state.refLevel( LevelID::startedMainMenu ).update( dt );
    testAnim.update( dt );
    if( nullptr != test )
        test ->setImage( testAnim.getImage() );

    sprintf( str, "dt = %f, delta = %d, ticks = %d, frame = %d(%d)", dt, delta, ticks, testAnim.getFrame(), testAnim.getImages().size() );
    conOut ->setString( std::string(str) );

    if( timeInvitation > 0.0f )
        timeInvitation -= dt;
    else if( !invitationAnim.getActive() )
        invitationAnim.start();
    else
    {
        invitationAnim.update( dt );
        invitation->setImage( invitationAnim.getImage() );
        if( !invitationAnim.getActive() )
            timeInvitation = 15.0f;
    }

    return;
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
