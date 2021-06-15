#ifndef SCENE_BUILDER_H
#define SCENE_BUILDER_H

#include <string>
#include "../render/scene.h"

namespace lcg
{
    class SceneBuilder
    {
    public:
        SceneBuilder();
        virtual ~SceneBuilder();

        template< typename T >
        T* as()
        {
            if( typeid(T).before(typeid(*this)) || typeid(T) == typeid(*this) )
            {
                return( dynamic_cast<T*>(this) );
            }
            return( nullptr );
        }

        virtual const Scene* scene() const { return( nullptr ); }

    public: // name
        virtual std::string getName() const = 0;

    public:
        void init();
        void build();
        void process( float );

    protected:
        virtual void onInit(){}  // get setup data
        virtual void onBuild(){} // create & load scene
        virtual void onProcess( float ){}
    };
}

#endif // SCENE_BUILDER_H
