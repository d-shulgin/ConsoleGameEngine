#include "image.h"
#include "color.h"

namespace lcg
{
    Image::Image( short w, short h )
        : width( w )
        , height( h )
    {
        if( w > 0 && h > 0 )
            buffer.resize( w * h, {0, 0} );
    }
    Image& Image::beginSymbols()
    {
        cursorSymbol = 0;
        return( *this );
    }
    Image& Image::beginColors()
    {
        cursorColor = 0;
        return( *this );
    }
    Image&Image::beginBgColors()
    {
        cursorBgColor = 0;
        return( *this );
    }
    Image& Image::addSymbols( const std::string symbols )
    {
        if( buffer.size() > 0 )
        {
            for( auto ch: symbols )
                if( ch != '\n' )
                {
                    buffer[cursorSymbol].Char.UnicodeChar = 0;
                    buffer[cursorSymbol].Char.AsciiChar = ch;
                    ++cursorSymbol %= buffer.size();
                }
        }
        return( *this );
    }
    Image& Image::addColors( const std::string colors )
    {
        if( buffer.size() > 0 )
        {
            for( auto clr: colors )
            {
                if( clr != '\n' )
                {
                    WORD color = 0;
                    switch( static_cast<ImageLegend>(clr) )
                    {
                    case ImageLegend::black:        color = static_cast<WORD>(ColorID::black);        break;
                    case ImageLegend::dark_gray:    color = static_cast<WORD>(ColorID::dark_gray);    break;
                    case ImageLegend::gray:         color = static_cast<WORD>(ColorID::gray);         break;
                    case ImageLegend::white:        color = static_cast<WORD>(ColorID::white);        break;
                    case ImageLegend::red:          color = static_cast<WORD>(ColorID::red);          break;
                    case ImageLegend::green:        color = static_cast<WORD>(ColorID::green);        break;
                    case ImageLegend::blue:         color = static_cast<WORD>(ColorID::blue);         break;
                    case ImageLegend::yellow:       color = static_cast<WORD>(ColorID::yellow);       break;
                    case ImageLegend::pink:         color = static_cast<WORD>(ColorID::pink);         break;
                    case ImageLegend::sky:          color = static_cast<WORD>(ColorID::sky);          break;
                    case ImageLegend::light_red:    color = static_cast<WORD>(ColorID::light_red);    break;
                    case ImageLegend::light_green:  color = static_cast<WORD>(ColorID::light_green);  break;
                    case ImageLegend::light_blue:   color = static_cast<WORD>(ColorID::light_blue);   break;
                    case ImageLegend::light_yellow: color = static_cast<WORD>(ColorID::light_yellow); break;
                    case ImageLegend::light_pink:   color = static_cast<WORD>(ColorID::light_pink);   break;
                    case ImageLegend::light_sky:    color = static_cast<WORD>(ColorID::light_sky);    break;
                    default:
                        color = static_cast<WORD>(ColorID::black);
                        break;
                    }
                    buffer[cursorColor].Attributes = color | (buffer[cursorColor].Attributes & 0xFFF0);
                    ++cursorColor %= buffer.size();
                }
            }
        }
        return( *this );
    }
    Image& Image::addBgColors( const std::string colors )
    {
        if( buffer.size() > 0 )
        {
            for( auto clr: colors )
            {
                if( clr != '\n' )
                {
                    WORD color = 0;
                    switch( static_cast<ImageLegend>(clr) )
                    {
                    case ImageLegend::black:        color = static_cast<WORD>(ColorID::black);        break;
                    case ImageLegend::dark_gray:    color = static_cast<WORD>(ColorID::dark_gray);    break;
                    case ImageLegend::gray:         color = static_cast<WORD>(ColorID::gray);         break;
                    case ImageLegend::white:        color = static_cast<WORD>(ColorID::white);        break;
                    case ImageLegend::red:          color = static_cast<WORD>(ColorID::red);          break;
                    case ImageLegend::green:        color = static_cast<WORD>(ColorID::green);        break;
                    case ImageLegend::blue:         color = static_cast<WORD>(ColorID::blue);         break;
                    case ImageLegend::yellow:       color = static_cast<WORD>(ColorID::yellow);       break;
                    case ImageLegend::pink:         color = static_cast<WORD>(ColorID::pink);         break;
                    case ImageLegend::sky:          color = static_cast<WORD>(ColorID::sky);          break;
                    case ImageLegend::light_red:    color = static_cast<WORD>(ColorID::light_red);    break;
                    case ImageLegend::light_green:  color = static_cast<WORD>(ColorID::light_green);  break;
                    case ImageLegend::light_blue:   color = static_cast<WORD>(ColorID::light_blue);   break;
                    case ImageLegend::light_yellow: color = static_cast<WORD>(ColorID::light_yellow); break;
                    case ImageLegend::light_pink:   color = static_cast<WORD>(ColorID::light_pink);   break;
                    case ImageLegend::light_sky:    color = static_cast<WORD>(ColorID::light_sky);    break;
                    default:
                        color = static_cast<WORD>(ColorID::black);
                        break;
                    }
                    buffer[cursorBgColor].Attributes = (color << 4) | (buffer[cursorBgColor].Attributes & 0xFF0F);
                    ++cursorBgColor %= buffer.size();
                }
            }
        }
        return( *this );
    }
    Image::~Image()
    {
    }
}
