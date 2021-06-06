#include "game.h"
#include <iostream>

Game::Game( int width, int height )
    : Core( width, height )
{
}
void Game::onInit()
{
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
void Game::onStart()
{
}
void Game::onProcess()
{
}
void Game::onPostProcess()
{
}
