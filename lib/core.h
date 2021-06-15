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
#include "input/user_input.h"

namespace lcg
{
    class Core
    {
        HANDLE hConsole = nullptr;         // original active screen buffer
        CONSOLE_SCREEN_BUFFER_INFOEX info; // original screen buffer info
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
        bool inProcess() const { return( isStarted ); }
        void start();
        void process( float );
        void postProcess();

    protected:
        virtual void onStart(){}
        virtual void onProcess( float ){}
        virtual void onPostProcess(){}

    private: // rendering
        int countScenesRendered = 0;

    public:
        void draw();

    protected:
        virtual void onPrepareDraw(){}
        virtual const Scene* getScene() { return( nullptr ); }

    private: // user input
        UserInput input;

    protected:
        UserInput& refInput() { return( input ); }

    public:
        const UserInput& getInput() const { return( input ); }
    };
}

#endif // CORE_H
