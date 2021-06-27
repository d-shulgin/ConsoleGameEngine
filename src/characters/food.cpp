#include "food.h"

Food::Food( int id )
    : _id( id )
{
}
void Food::process( float dt )
{
    if( getActive() )
        onProcess( dt );
    return;
}
Food::~Food()
{
}
