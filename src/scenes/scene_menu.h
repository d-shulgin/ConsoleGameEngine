#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "../../lib/engine.h"

class SceneMenu final : public lcg::SceneBuilder
{
    lcg::Scene _scene;

public:
    SceneMenu();
    virtual ~SceneMenu();

    virtual const lcg::Scene* scene() const override { return( &_scene ); }

public: // name
    static std::string class_name() { return("SceneMenu"); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // create & load scene
    virtual void onBuild() override;

private:
    class Resources
    {
        static const unsigned int CURSOR_IMAGES = 6;
    private:
        lcg::Image _background;
        lcg::Image _cursor[CURSOR_IMAGES];

    public:
        void load();
        const lcg::Image* background() const { return( &_background ); }
        const lcg::Image* cursor( unsigned int i ) const
        {
            if( i < CURSOR_IMAGES )
                return( &_cursor[i] );
            return( nullptr );
        }
    } rsc;

private: // background
    lcg::Sprite* background = nullptr;

    void loadBackground();

private: // cursor
    lcg::Sprite* cursor = nullptr;
    lcg::Animation cursorAnim;

    void loadCursor();

public:
    void selectMenuItem( int );

protected: // process animation of scene
    virtual void onProcess( float ) override;
};

#endif // SCENE_MENU_H
