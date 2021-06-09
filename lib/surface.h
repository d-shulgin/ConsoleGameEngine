/*
 *
 *
 */

#ifndef SURFACE_H
#define SURFACE_H

#include <vector>
#include <windows.h>
#include <windowsx.h>
#include "surface/screen_buffer.h"
#include "render/scene.h"

namespace lcg
{
    enum class SurfaceInitFlag
    {
        withSingleBuffer = 0x00000000
        , withDoubleBuffer = 0x00000001
    };

    class Surface final
    {
        enum
        {
            MAX_BUFFERS_AMOUNT = 2
        };

    public:
        Surface();
        ~Surface();

        void init( HANDLE, SurfaceInitFlag, int, int );

    private: // double screen buffers
        std::vector< ScreenBuffer > buffers;
        int showBufferIndex = 0;
        int activeBufferIndex = 0;

        int showIndex() const { return( showBufferIndex ); }
        int activeIndex() const { return( activeBufferIndex ); }

        ScreenBuffer& refBuffer()
        {
            if( activeIndex() < buffers.size() )
                return( buffers[activeIndex()] );
            /// @todo: need throw
        }
        void changeActiveBuffer();

    public:
        const ScreenBuffer& buffer() const
        {
            if( activeIndex() < buffers.size() )
                return( buffers[activeIndex()] );
            /// @todo: need throw
        }

    public:
        void swapBuffers();
        bool render( const Scene* const );









//    public: // current screen size
//        const ScreenBufferSize& size() const
//        {
//            return( buffer().screenSize() );
//        }
//    private: // color
//        ColorID foregroundColor = ColorID::black; /// @todo: need Pen class
//        ColorID backgroundColor = ColorID::black; /// @todo: need Background class
//    public:
//        const ColorID& fgColor() const { return( foregroundColor ); }
//        const ColorID& bgColor() const { return( backgroundColor ); }
//        void setFgColor( ColorID color ){ foregroundColor = color; }
//        void setBgColor( ColorID color ){ backgroundColor = color; }
//    public: // draw
//        void putText( int, int, const char* );
    };
}

#endif // SURFACE_H
