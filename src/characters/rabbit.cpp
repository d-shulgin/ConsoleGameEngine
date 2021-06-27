#include "rabbit.h"
#include <chrono>
#include <random>

Rabbit::Rabbit( int id )
    : Food( id )
{
}
Rabbit::~Rabbit()
{
}

void Rabbit::onProcess( float dt )
{
    timeLive -= dt;
    if( timeLive <= 0.0f )
        setActive( false );
    return;
}
void Rabbit::onActivated()
{
    if( getActive() )
    {
        unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937_64 gen(seed);
        timeLive = TIME_LIVE_MAX;
        health = (gen() % 5 == 0 ? 1 : 0);
    }
    return;
}
