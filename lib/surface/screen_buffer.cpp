#include "screen_buffer.h"
#include <iostream>
#include "../utils/exception_engine.h"

namespace lcg
{
    ScreenBuffer::ScreenBuffer( int w, int h )
    {
        _scrSize.width  = w;
        _scrSize.height = h;
    }
    void ScreenBuffer::init( HANDLE buffer )
    {
        if( nullptr != buffer )
        {
            hScreenBuffer = buffer;
        }
        else
        {
            hScreenBuffer = CreateConsoleScreenBuffer(
                                GENERIC_READ | GENERIC_WRITE
                                , FILE_SHARE_READ | FILE_SHARE_WRITE
                                , nullptr
                                , CONSOLE_TEXTMODE_BUFFER
                                , nullptr );
        }
        if( nullptr == hScreenBuffer || INVALID_HANDLE_VALUE == hScreenBuffer )
        {
            throw( ExceptionEngine(Error::_invalid_handle_ScreenBuffer) );
            return;
        }
        if( screenSize().length() > 0 )
            changeBufferSize( screenSize() );
        else
            updateBufferInfo();
        return;
    }
    void ScreenBuffer::show()
    {
        if( nullptr != hScreenBuffer )
        {
            if( 0 == SetConsoleActiveScreenBuffer(hScreenBuffer) )
            {
                throw( ExceptionEngine(Error::_failure_activate_ScreenBuffer) );
                return;
            }
        }
        return;
    }
    void ScreenBuffer::changeBufferSize( const ScreenBufferSize& size )
    {
        if( 0 != SetConsoleScreenBufferSize( hScreenBuffer, size.asCOORD() ) )
        {
            updateBufferInfo();
            return;
        }
        throw( ExceptionEngine(Error::_failure_resize_ScreenBuffer) );
    }
    void ScreenBuffer::updateBufferInfo()
    {
        if( nullptr != hScreenBuffer )
        {
            CONSOLE_SCREEN_BUFFER_INFO info;
            GetConsoleScreenBufferInfo( hScreenBuffer, &info );
            _scrSize.width  = info.srWindow.Right - info.srWindow.Left + 1;
            _scrSize.height = info.srWindow.Bottom - info.srWindow.Top + 1;
            _maxSize.width  = info.dwMaximumWindowSize.X;
            _maxSize.height = info.dwMaximumWindowSize.Y;
            _size.width  = info.dwSize.X;
            _size.height = info.dwSize.Y;
            return;
        }
        throw( ExceptionEngine(Error::_invalid_handle_ScreenBuffer) );
    }
    void ScreenBuffer::put( const CHAR_INFO* buffer, COORD size, COORD pos )
    {
        if( nullptr != hScreenBuffer )
        {
            SMALL_RECT rect;
            rect.Left   = pos.X;
            rect.Right  = rect.Left + size.X - 1;
            rect.Top    = pos.Y;
            rect.Bottom = rect.Top + size.Y - 1;
            WriteConsoleOutput( hScreenBuffer, buffer, size, {0, 0}, &rect );
        }
        return;
    }
    ScreenBuffer::~ScreenBuffer()
    {
    }
}


/*
info:
dwSize              => console screen buffer: w(120) h(300)
dwCursorPosition    => coordinates of the cursor: x(0) y(0)
wAttributes         => attributes of the characters: 7
srWindow            => corners of the display window: (0..119) - (0..49)
dwMaximumWindowSize => maximum size of the console window: w(120) h(71)

info:
dwSize              => console screen buffer: w(120) h(50)
dwCursorPosition    => coordinates of the cursor: x(0) y(0)
wAttributes         => attributes of the characters: 7
srWindow            => corners of the display window: (0..119) - (0..49)
dwMaximumWindowSize => maximum size of the console window: w(120) h(50)
*/
