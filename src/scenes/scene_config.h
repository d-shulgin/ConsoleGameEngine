#ifndef SCENE_CONFIG_H
#define SCENE_CONFIG_H

#include "../../lib/engine.h"

class SceneConfig final : public lcg::SceneBuilder
{
    lcg::Scene _scene;

public:
    SceneConfig();
    virtual ~SceneConfig();

    virtual const lcg::Scene* scene() const override { return( &_scene ); }

public: // name
    static std::string class_name() { return("SceneConfig"); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // create & load scene
    virtual void onBuild() override;

private:
    class Resources
    {
    private:
        lcg::Image _background;

    public:
        void load();
        const lcg::Image* background() const { return( &_background ); }
    } rsc;

private: // background
    lcg::Sprite* background = nullptr;

    void loadBackground();

protected: // process animation of scene
    virtual void onProcess( float ) override;
};

#endif // SCENE_CONFIG_H
