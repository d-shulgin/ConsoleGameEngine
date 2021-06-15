#include <iostream>
#include <iomanip>

#include <windows.h>
#include <windowsx.h>

#include "src/game.h"

float dt_from( DWORD& );

int main()
{
    //setlocale( LC_ALL, "Russian" );

    Game game( 120, 50 );
    game.init( lcg::SurfaceInitFlag::withDoubleBuffer );
    game.start();
    DWORD ticks = GetTickCount(); // milliseconds
    while( game.inProcess() ) // main game loop
    {
        game.process( dt_from(ticks) );
        game.draw();
        game.postProcess();
    }
    return 0;
}

float dt_from( DWORD& lastTicks )
{
    DWORD ticks = GetTickCount(); // milliseconds
    DWORD delta = 0;
    if( ticks < lastTicks )
        delta = (0xffffffff - lastTicks) + ticks;
    else
        delta = ticks - lastTicks;
    lastTicks = ticks;
    return( static_cast<float>(delta)/1000.0f ); // sec
}
