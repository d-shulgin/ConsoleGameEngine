#ifndef POSITION_H
#define POSITION_H

#include <windows.h>

namespace lcg
{
    class Position final
    {
        short int _x = 0;
        short int _y = 0;

    public:
        explicit Position( short int = 0, short int = 0 );
        ~Position();

        bool operator == ( const Position& p ) const
        {
            return( x() == p.x() && y() == p.y() );
        }
        bool operator != ( const Position& p ) const
        {
            return( !operator ==(p) );
        }

        Position operator + ( const Position& p ) const
        {
            return( Position(x() + p.x(), y() + p.y()) );
        }

    public:
        short int x() const { return( _x ); }
        short int y() const { return( _y ); }
        COORD asCOORD() const
        {
            COORD result{ x(), y() };
            return( result );
        }
    };
}

#endif // POSITION_H
