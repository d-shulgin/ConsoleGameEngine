#include "view.h"
#include <iostream>

namespace lcg
{
    View::View( const std::string& namae )
        : name( namae )
    {
        std::cout << "con... View(" << getName() << ")" << std::endl;
    }
    void View::setGlobalPosition( const Position& p )
    {
        if( p != getGlobalPosition() )
            onGlobalPositionChanged( p );
        globalPosition = p;
    }
    void View::setPosition( const Position& p )
    {
        if( p != getPosition() )
            onPositionChanged( p );
        position = p;
        return;
    }
    void View::setPosition( short x, short y )
    {
        setPosition( Position(x, y) );
        return;
    }
    View::~View()
    {
        std::cout << "des... View(" << getName() << ")" << std::endl;
    }
}
