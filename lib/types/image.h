#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include <windows.h>

namespace lcg
{
    enum class ImageLegend
    {
        black = ' '
        , dark_gray = 'a'
        , gray = 'w'
        , white = 'W'
        , red = 'r'
        , green = 'g'
        , blue = 'b'
        , yellow = 'y'
        , pink = 'p'
        , sky = 's'
        , light_red = 'R'
        , light_green = 'G'
        , light_blue = 'B'
        , light_yellow = 'Y'
        , light_pink = 'P'
        , light_sky = 'S'
    };

    class Image final
    {
        short width = 0;
        short height = 0;

    public:
        explicit Image( short w = 0, short h = 0 );
        ~Image();

        short getWidth() const { return( width ); }
        short getHeight() const { return( height ); }

    private: // buffer
        std::vector<CHAR_INFO> buffer;
        int cursorSymbol  = 0;
        int cursorColor   = 0;
        int cursorBgColor = 0;

    public:
        const std::vector<CHAR_INFO>& getBuffer() const { return( buffer ); }
        Image& beginSymbols();
        Image& beginColors();
        Image& beginBgColors();
        Image& addSymbols ( const std::string );
        Image& addColors( const std::string );
        Image& addBgColors( const std::string );
    };
}

#endif // IMAGE_H
