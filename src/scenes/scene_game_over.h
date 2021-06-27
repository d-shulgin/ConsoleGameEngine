#ifndef SCENE_GAME_OVER_H
#define SCENE_GAME_OVER_H

#include "../../lib/engine.h"

class SceneGameOver final : public lcg::SceneBuilder
{
    lcg::Scene _scene;

public:
    SceneGameOver();
    virtual ~SceneGameOver();

    virtual const lcg::Scene* scene() const override { return( &_scene ); }

public: // name
    static std::string class_name() { return("SceneGameOver"); }
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
};

#endif // SCENE_GAME_OVER_H
