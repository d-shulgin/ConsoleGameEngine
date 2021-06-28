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
#include "utils/exception_engine.h"

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
            if( static_cast<std::size_t>(activeIndex()) < buffers.size() )
                return( buffers[activeIndex()] );
            throw( ExceptionEngine(Error::_invalid_ref_ScreenBuffer) );
            return( buffers[0] );
        }
        void changeActiveBuffer();

    public:
        const ScreenBuffer& buffer() const
        {
            if( static_cast<std::size_t>(activeIndex()) < buffers.size() )
                return( buffers[activeIndex()] );
            throw( ExceptionEngine(Error::_invalid_ref_ScreenBuffer) );
            return( buffers[0] );
        }

    public:
        void swapBuffers();
        bool render( const Scene* const );

    };
}

#endif // SURFACE_H
