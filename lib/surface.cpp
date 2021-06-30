#include "surface.h"
#include <iostream>

namespace lcg
{
    Surface::Surface()
    {
        buffers.reserve( MAX_BUFFERS_AMOUNT );
    }
    void Surface::init( HANDLE hMainScreenBuffer
                        , SurfaceInitFlag initFlag
                        , int width, int height )
    {
        buffers.push_back( ScreenBuffer(width, height) );
        buffers[0].init( hMainScreenBuffer );
        if( (int)initFlag & (int)SurfaceInitFlag::withDoubleBuffer )
        {
            buffers.push_back( ScreenBuffer(width, height) );
            ++ activeBufferIndex;
            buffers[1].init();
        }
        return;
    }
    void Surface::changeActiveBuffer()
    {
        ++showBufferIndex   %= buffers.size();
        ++activeBufferIndex %= buffers.size();
    }
    void Surface::swapBuffers()
    {
        if( showIndex() != activeIndex() )
        {
            refBuffer().show();
        }
        changeActiveBuffer();
        return;
    }
    bool Surface::render( const Scene* const scene )
    {
        if( nullptr != scene )
        {
            scene -> render( refBuffer(), &ScreenBuffer::put );
            return( true );
        }
        return( false );
    }
    Surface::~Surface()
    {
    }
}
