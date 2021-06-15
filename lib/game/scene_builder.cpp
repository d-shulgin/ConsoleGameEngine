#include "scene_builder.h"

namespace lcg
{
    SceneBuilder::SceneBuilder()
    {
    }
    SceneBuilder::~SceneBuilder()
    {
    }

    void SceneBuilder::init()
    {
        onInit();
    }
    void SceneBuilder::build()
    {
        onBuild();
    }
    void SceneBuilder::process( float dt )
    {
        onProcess( dt );
    }
}
