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

        void process( float );
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
        std::vector< const Image* > images;
        size_t frame = 0;

    public:
        const std::vector< const Image* >& getImages() const { return( images ); }
        size_t getFrame() const { return( frame ); }
        const Image* getImage() const;
        Animation& addImage( const Image* const );

    public: // callback
        class Callback
        {
        public:
            Callback(){}

            virtual void onPlayedOnce() = 0;
            virtual void onStoped() = 0;
        };

    private:
        Callback* handler = nullptr;

    public:
        void setCallback( Callback* v ){ handler = v; }
    };
}

#endif // ANIMATION_H
