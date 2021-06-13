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
    DWORD lastTicks = GetTickCount(); // milliseconds
    while( game.inProcess() )
    {
        DWORD ticks = GetTickCount(); // milliseconds
        DWORD delta = 0;
        if( ticks < lastTicks )
            delta = (0xffffffff - lastTicks) + ticks;
        else
            delta = ticks - lastTicks;
        DWORD lT = lastTicks;
        lastTicks = ticks;
        float dt = static_cast<float>(delta)/1000.0f; // sec

        game.process( dt, lT, ticks );
        game.draw();
        game.postProcess();
        Sleep( 10 );
    }
    return 0;
}

