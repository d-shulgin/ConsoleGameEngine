#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <vector>

namespace lcg
{
    class FPSCounter final
    {
        float elapsedTime = 0.0f;
        int counterFrames = 0;

    public:
        static const unsigned int DEFAULT_BUFFER_SIZE = 10;

        explicit FPSCounter( unsigned int = DEFAULT_BUFFER_SIZE );
        ~FPSCounter();

        void update( float );
        void reset();

    private:
        bool active = false;

    public:
        bool getActive() const { return( active ); }

    private:
        std::vector< float > bufferFPS;
        unsigned int maxBufferSize = DEFAULT_BUFFER_SIZE;

        void storeFrames( float );

    public:
        float getCurrent() const;
        const std::vector< float >& frames() const { return( bufferFPS ); }
        std::size_t getMaxBufferSize() const { return( maxBufferSize ); }
    };
}

#endif // FPS_COUNTER_H
