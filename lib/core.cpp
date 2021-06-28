#include "core.h"
#include <iostream>
#include <iomanip>
#include "utils/exception_engine.h"

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
            throw( ExceptionEngine(Error::_invalid_handle_StdOutputDevide) );
            return;
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
    void Core::stop()
    {
        isStarted = false;
        return;
    }
    void Core::process( float dt )
    {
        onProcess( dt );
        return;
    }
    void Core::postProcess()
    {
        refInput().postProcess();
        onPostProcess();
        return;
    }
    void Core::draw()
    {
        const int MAX_COUNT_RENDERED_SCREENS = 1000;
        onPrepareDraw();
        countScenesRendered = 0;
        while( surface.render(getScene()) )
        {
            countScenesRendered++;
            if( countScenesRendered > MAX_COUNT_RENDERED_SCREENS )
            {
                throw( ExceptionEngine(Error::_limit_rendering_scenes) );
                break;
            }
        }
        Sleep( 10 ); // sleep on 10 milliseconds
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
