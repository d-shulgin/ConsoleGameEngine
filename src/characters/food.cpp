#include "food.h"

Food::Food( int id )
    : _id( id )
{
}
void Food::process( float dt )
{
    onProcess( dt );
}
Food::~Food()
{
}
