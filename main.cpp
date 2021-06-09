#include <iostream>
#include <iomanip>

#include <windows.h>
#include <windowsx.h>

#include "src/game.h"

int main()
{
    //setlocale( LC_ALL, "Russian" );
    Game game( 120, 50 );
    game.init( lcg::SurfaceInitFlag::withDoubleBuffer );
//    game.init( lcg::SurfaceInitFlag::withSingleBuffer );
    game.start();
    while( game.inProcess() )
    {
        game.process();
        game.draw();
        game.postProcess();
    }
    return 0;
}

