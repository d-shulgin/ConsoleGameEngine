#include "text.h"
#include <iostream>

namespace lcg
{
    Text::Text( const std::string& name )
        : View( name )
    {
        std::cout << "con... Text(" << getName() << ")" << std::endl;
    }
    void Text::setData( const Position& coord
                        , const std::string& str
                        , const ColorID& foreground
                        , const ColorID& background )
    {
        setPosition( coord );
        setColor( foreground );
        setBackgroundColor( background );
        setString( str );
        return;
    }
    void Text::setData( const Position& coord
                        , const std::string& str
                        , const ColorID& foreground )
    {
        setData( coord, str, foreground, lcg::ColorID::black );
    }
    void Text::setData( const Position& coord
                        , const std::string& str )
    {
        setData( coord, str, lcg::ColorID::white, lcg::ColorID::black );
    }
    void Text::setData( const std::string& str )
    {
        setData( Position(0, 0), str, lcg::ColorID::white, lcg::ColorID::black );
    }
    void Text::setString( const std::string& v )
    {
        str = v;
        short rows = 1;
        short cols = 0, cl = 0;
        for( auto ch: v )
        {
            if( ch == '\n' )
            {
                cols = (cl > cols ? cl : cols);
                rows ++;
                cl = 0;
            }
            else if( ch == 0 )
                break;
            else if( cl < 0x7ffff )
                cl++;
        }
        if( 0 == cl )
            rows --;
        cols = (cl > cols ? cl : cols);
        if( nullptr != buffer )
        {
            delete[] buffer;
            buffer = nullptr;
            bufferSize = {0, 0};
        }
        if( cols > 0 && rows > 0 )
        {
            buffer = new CHAR_INFO[cols*rows];
            bufferSize = {cols, rows};

            // copy str to buffer
            int k = 0;
            WORD clr = static_cast<WORD>(getColor()) | (static_cast<WORD>(getBackgroundColor()) << 4);
            for( int j = 0; j < rows; ++j )
            {
                for( int i = 0; i < cols; ++i )
                {
                    if( k < v.size() && v[k] != '\n' )
                    {
                        buffer[i+j*cols].Char.UnicodeChar = 0;
                        buffer[i+j*cols].Char.AsciiChar = v[k];
                        buffer[i+j*cols].Attributes = clr;
                        k++;
                    }
                    else
                    {
                        buffer[i+j*cols].Char.UnicodeChar = 0;
                        buffer[i+j*cols].Char.AsciiChar = ' ';
                        buffer[i+j*cols].Attributes = clr;
                    }
                }
                k++;
            }
        }
        return;
    }
    void Text::render( ScreenBuffer& obj, RenderFnPtr fn ) const
    {
        if( nullptr != buffer )
        {
            Position pos = getGlobalPosition() + getPosition();
            fn( obj, buffer, bufferSize, pos.asCOORD() );
        }
        return;
    }
    Text::~Text()
    {
        if( nullptr != buffer )
        {
            delete[] buffer;
            buffer = nullptr;
            bufferSize = {0, 0};
        }
        std::cout << "des... Text(" << getName() << ")" << std::endl;
    }
}
