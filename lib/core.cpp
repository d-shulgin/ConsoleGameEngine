#include "core.h"
#include <iostream>
#include <iomanip>

namespace lcg
{
    Core::Core( int w, int h )
        : width( w )
        , height( h )
    {
    }
    void Core::init( SurfaceInitFlag initFlag )
    {
        hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        if( nullptr == hConsole || INVALID_HANDLE_VALUE == hConsole )
        {
            /// @todo: need throw
        }
        else
        {
            GetConsoleScreenBufferInfoEx( hConsole, &info );
            surface.init( hConsole, initFlag, width, height );
        }
        onInit();
        return;
    }
    void Core::swapBuffers()
    {
        surface.swapBuffers();
        return;
    }
    void Core::start()
    {
        isStarted = true;
        onStart();
        return;
    }
    void Core::process()
    {
        onProcess();
        return;
    }
    void Core::postProcess()
    {
        onPostProcess();
        return;
    }
    void Core::draw()
    {
        /// @todo: need set scene
        surface.render( nullptr );
        swapBuffers();
        return;
    }
    Core::~Core()
    {
        if( nullptr != hConsole )
        {
            SetConsoleActiveScreenBuffer( hConsole );
        }
    }
}
