/*
 *
 *
 */

#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <windows.h>
#include <windowsx.h>

#include "../types/color.h"

namespace lcg
{
    struct ScreenBufferSize
    {
        int width  = 0;
        int height = 0;

        COORD asCOORD() const
        {
            COORD result = {(SHORT)width, (SHORT)height};
            return( result );
        }
        int length() const
        {
            return( width * height );
        }
    };
    struct BufferSize
    {
        int width = 0;
        int height = 0;

        COORD asCOORD() const
        {
            COORD result = {(SHORT)width, (SHORT)height};
            return( result );
        }
    };
    class ScreenBuffer final
    {
        HANDLE hScreenBuffer = nullptr;
        ScreenBufferSize _scrSize;

    public:
        explicit ScreenBuffer( int = 0, int = 0 );
        ~ScreenBuffer();

        void init( HANDLE = nullptr );
        void show();
        void changeBufferSize( const ScreenBufferSize& );

    public:
        const ScreenBufferSize& screenSize() const { return( _scrSize ); }

    private: // maximum screen size
        ScreenBufferSize _maxSize;

    public:
        const ScreenBufferSize& screenMaxSize() const { return( _maxSize ); }

    private: // maximum buffr size
        BufferSize _size;

    public:
        const BufferSize& maxSize() const { return( _size ); }

    private:
        void updateBufferInfo();

    public: // render functions
        void put( const CHAR_INFO* buffer, COORD size, COORD pos );
    };
}

#endif // SCREEN_BUFFER_H
