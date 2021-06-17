#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include <vector>
#include <string>
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

protected: // initialize
    virtual void onInit() override;

protected: // create & load scene
    virtual void onBuild() override;

private:
    class Resources
    {
        static const unsigned int CURSOR_IMAGES = 6;
    private:
        lcg::Image _background;
        lcg::Image _cursor[CURSOR_IMAGES];
        lcg::Image _itemStart;
        lcg::Image _itemResume;
        lcg::Image _itemConfig;
        lcg::Image _itemExit;

    public:
        void load();
        const lcg::Image* background() const { return( &_background ); }
        const lcg::Image* cursor( unsigned int i ) const
        {
            if( i < CURSOR_IMAGES )
                return( &_cursor[i] );
            return( nullptr );
        }
        const lcg::Image* itemStart() const { return( &_itemStart ); }
        const lcg::Image* itemResume() const { return( &_itemResume ); }
        const lcg::Image* itemConfig() const { return( &_itemConfig ); }
        const lcg::Image* itemExit() const { return( &_itemExit ); }
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

public: // menu items
    static const int AMOUNT_MENUITEMS = 3;

private:
    lcg::Sprite* items[AMOUNT_MENUITEMS] = {nullptr};

    void loadItems();

private: // Advice
    const float TIME_HIDETIP = 0.200f; // sec
    const float TIME_SHOWTIP = 5.000f; // sec
    std::vector< std::string > tipStrings;
    int tipSelected = 0;
    lcg::Text* tip = nullptr;
    float timeShowTip = TIME_SHOWTIP;
    float timeHideTip = 0.0f;

    void initTips();
    void loadTips();
    void processTips( float );
    const std::string& getTip() const
    {
        if( static_cast<std::size_t>(tipSelected) < tipStrings.size() )
            return( tipStrings[tipSelected] );
        /// @todo: throw
    }

protected: // process animation of scene
    virtual void onProcess( float ) override;
};

#endif // SCENE_MENU_H
