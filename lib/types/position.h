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

        Position( const Position& cpy )
        {
            _x = cpy.x();
            _y = cpy.y();
        }
        Position& operator = ( const Position& cpy )
        {
            if( this != &cpy )
            {
                _x = cpy.x();
                _y = cpy.y();
            }
            return( *this );
        }
        Position( Position&& mv )
            : _x( mv._x )
            , _y( mv._y )
        {
        }
        Position& operator = ( Position&& mv )
        {
            if( this != &mv )
            {
                _x = mv._x;
                _y = mv._y;
            }
            return( *this );
        }

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
