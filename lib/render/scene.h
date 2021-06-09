#ifndef SCENE_H
#define SCENE_H

#include "../surface/screen_buffer.h"
#include "view.h"

namespace lcg
{
    class Scene final
    {
    public:
        Scene();
        ~Scene();

    private: // root view object
        View* root = nullptr;

        void releaseRoot();

    public:
        const View* getRoot() const { return( root ); }
        void setRoot( View* const v );

    public: // render
        void render( ScreenBuffer&, View::RenderFnPtr ) const;
    };
}

#endif // SCENE_H
