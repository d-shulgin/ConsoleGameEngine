#include "animation.h"
#include "../utils/exception_engine.h"

namespace lcg
{
    Animation::Animation()
    {
    }
    void Animation::process( float dt )
    {
        if( getActive() )
        {
            bool onPlayedOnce = false;
            bool onStoped = false;
            time += dt;
            size_t dFrame = static_cast<size_t>(getSpeed()*time);
            if( dFrame > 0 )
            {
                time -= static_cast<float>(dFrame)/getSpeed();
                frame += dFrame;
                if( !playOnce && frame >= getImages().size() )
                {
                    playOnce = true;
                    onPlayedOnce = true;
                }
                if( getCycle() )
                {
                    while( frame >= getImages().size() )
                    {
                        if( getRestartFrame() > 0
                            && getRestartFrame() < getImages().size() )
                            frame -= getImages().size() - getRestartFrame();
                        else
                            frame %= getImages().size();
                    }
                }
                else if( getImages().size() > 0 && frame >= getImages().size() )
                {
                    frame = getImages().size() - 1;
                    stop();
                    onStoped = true;
                }
                else if( getImages().empty() )
                    frame = 0;
            }
            if( nullptr != handler && onPlayedOnce )
                handler -> onPlayedOnce();
            if( nullptr != handler && onStoped )
                handler -> onStoped();
        }
        return;
    }
    void Animation::reset()
    {
        time = 0.0f;
        frame = 0;
        playOnce = false;
        active = false;
        started = false;
        return;
    }
    void Animation::start()
    {
        reset();
        active = true;
        started = getActive();
        return;
    }
    void Animation::stop()
    {
        if( getStarted() )
            active = false;
        return;
    }
    void Animation::resume()
    {
        if( getStarted() )
            active = true;
        return;
    }
    const Image* Animation::getImage() const
    {
        if( getFrame() < getImages().size() )
            return( getImages()[getFrame()] );
        throw( ExceptionEngine(Error::_invalid_frame_animation) );
        return( nullptr );
    }
    Animation& Animation::addImage( const Image* const image )
    {
        images.push_back( image );
    }
    Animation::~Animation()
    {
    }
}
