#include <iostream>
#include <iomanip>

#include <process.h>
#include <windows.h>
#include <windowsx.h>

#include "src/game.h"

float dt_from( DWORD& );

int main()
{
    system( "chcp 65001" );
    setlocale( LC_ALL, "Russian" );

//    SetConsoleCP(65001);
//    SetConsoleOutputCP(65001);
//    LCID locale = GetSystemDefaultLCID();
//    SetLocaleInfoA(locale, LOCALE_SLOCALIZEDCOUNTRYNAME, "ru-Ru" );

    // launch Game
    try
    {
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
    }
    catch( std::exception& e )
    {
        std::cout << "[Ooops... ] " << e.what() << std::endl;
    }
    std::cout << "Game completed..." << std::endl;
    Sleep( 1000 );

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
