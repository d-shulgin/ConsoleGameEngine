#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "../types/image.h"

namespace lcg
{
    class Animation final
    {
        float time = 0.0f; // sec
    public:
        Animation();
        ~Animation();

        void update( float );
        void reset();
        void start();
        void stop();
        void resume();

    private: // active
        bool active = false;
        bool started = false;

    public:
        bool getActive() const { return( active && !getImages().empty() ); }
        bool getStarted() const { return( started ); }

    private: // speed
        float speed = 10.0f; // frame per sec

    public:
        float getSpeed() const { return( speed ); }
        void setSpeed( float v ){ speed = v; }

    private: // cycle
        bool cycle = false;
        bool playOnce = false;

    public:
        bool getCycle() const { return( cycle ); }
        void setCycle( bool flg ) { cycle = flg; }

    private: // cycle restart frame
        size_t restartFrame = 0;

    public:
        size_t getRestartFrame() const { return( restartFrame ); }
        void setRestartFrame( size_t v ) { restartFrame = v % getImages().size(); }

    private: // images
        std::vector< Image > images;
        size_t frame = 0;

    public:
        const std::vector< Image >& getImages() const { return( images ); }
        size_t getFrame() const { return( frame ); }
        const Image* getImage() const;
        Animation& addImage( const Image& );
    };
}

#endif // ANIMATION_H
