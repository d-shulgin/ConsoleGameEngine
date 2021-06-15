#ifndef SCENE_DEBUG_H
#define SCENE_DEBUG_H

#include <string>
#include "../../lib/engine.h"

class SceneDebug final : public lcg::SceneBuilder
{
    lcg::Scene _scene;

public:
    SceneDebug();
    virtual ~SceneDebug();

    virtual const lcg::Scene* scene() const override { return( &_scene ); }

public: // name
    static std::string class_name() { return("SceneDebug"); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // create & load scene
    virtual void onBuild() override;

private: // text
    lcg::Text* root = nullptr;

public:
    void setText( const std::string& );
};

#endif // SCENE_DEBUG_H
