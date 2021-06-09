#include "scene.h"
#include <iostream>

namespace lcg
{
    Scene::Scene()
    {
        std::cout << "con... Scene" << std::endl;
    }
    void Scene::releaseRoot()
    {
        if( nullptr != root )
            delete root;
        return;
    }
    void Scene::setRoot(View* const v)
    {
        releaseRoot();
        root = v;
        return;
    }
    void Scene::render( ScreenBuffer& obj, View::RenderFnPtr fn ) const
    {
        if( nullptr != getRoot() )
            getRoot() -> render( obj, fn );
        return;
    }
    Scene::~Scene()
    {
        releaseRoot();
        std::cout << "des... Scene" << std::endl;
    }
}
