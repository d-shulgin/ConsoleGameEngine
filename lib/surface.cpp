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
    void Surface::render(const Scene* const) const
    {
    }







//    void Surface::putText( int x, int y, const char* text )
//    {
//        int w = buffer().screenSize().width - x;
//        int l = static_cast<int>(strlen(text));
//        int offset = y*buffer().screenSize().width;
//        if( ( x >= 0 && x < buffer().screenSize().width )
//            && ( y >= 0 && y < buffer().screenSize().height ) )
//        {
//            int k = 0;
//            while( k < l && k < w )
//            {
//                char ch = *(text + k);
//                int i = x + k + offset;
//                refBuffer().put( i, ch, fgColor(), bgColor() );
//                k++;
//            }
//        }
//        return;
//    }
    Surface::~Surface()
    {
    }
}
