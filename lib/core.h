/*
 * The Core class is the base class for building a game.
 * All interaction with the game engine is carried out
 * through this class.
 *
 * Author: Shulgin D.
 *
 * - After creating an instance of the game, you must
 *   first call the init method, which initializes the engine.
 */

#ifndef CORE_H
#define CORE_H

#include <windows.h>
#include "surface.h"
#include "render/scene.h"

namespace lcg
{
    class Core
    {
        HANDLE hConsole = nullptr;         // original active screen buffer
        CONSOLE_SCREEN_BUFFER_INFOEX info; // original scrteen buffer info
        int width = 0;  // default screen width
        int height = 0; // default screen height

    public:
        explicit Core( int width, int height );
        virtual ~Core();

        void init( SurfaceInitFlag );

    protected:
        virtual void onInit(){}

    private: // surface
        Surface surface;

        void swapBuffers();

    public:
        const Surface& getSurface() const { return( surface ); }

    private: // game loop
        bool isStarted = false;

    public:
        void start();
        bool inProcess() const { return( isStarted ); }
        void process();
        void postProcess();

    protected:
        virtual void onStart(){}
        virtual void onProcess(){}
        virtual void onPostProcess(){}

    private: // rendering
        Scene scene;

    public:
        void draw();
    };
}

#endif // CORE_H
