#include "fps_counter.h"

namespace lcg
{
    FPSCounter::FPSCounter( unsigned int bufferSize )
        : maxBufferSize( bufferSize )
    {
    }
    void FPSCounter::update( float dt )
    {
        counterFrames ++;
        elapsedTime += dt;
        if( elapsedTime >= 1000.0f )
        {
            float time = elapsedTime / 1000.0f;
            storeFrames( static_cast<float>(counterFrames)/time );
            counterFrames = 0;
            elapsedTime = 0.0f;
        }
        active = true;
        return;
    }
    void FPSCounter::reset()
    {
        active = false;
        elapsedTime = 0.0f;
        counterFrames = 0;
        bufferFPS.clear();
        bufferFPS.reserve( getMaxBufferSize() );
        return;
    }
    void FPSCounter::storeFrames( float framesVal )
    {
        if( frames().size() < getMaxBufferSize() )
            bufferFPS.push_back( 0.0f );
        for( std::size_t i = bufferFPS.size() - 1; i > 0; --i )
                bufferFPS[i] = bufferFPS[i - 1];
        bufferFPS[0] = framesVal;
        return;
    }
    float FPSCounter::getCurrent() const
    {
        if( getActive() )
        {
            if( !frames().empty() )
                return( frames()[0] );
            float time = elapsedTime / 1000.0f;
            return( static_cast<float>(counterFrames)/time );
        }
        return( 0.0f );
    }
    FPSCounter::~FPSCounter()
    {
    }
}
