#ifndef GAME_H
#define GAME_H

#include "../lib/engine.h"
#include "snake_state.h"
#include "scenes/package.h"

class Game final : public lcg::Core
{
    typedef lcg::Position Pos;
public:
    explicit Game( int = 0, int = 0 );

private:
    lcg::FPSCounter fps;

protected: // initialize
    virtual void onInit() override;

protected: // prepare before main game loop
    virtual void onStart() override;

protected: // scene process logic (before Draw)
    virtual void onProcess( float ) override;

protected: // draw
    virtual void onPrepareDraw() override;
    virtual const lcg::Scene* getScene() override;

protected: // after draw process
    virtual void onPostProcess() override;

private: // state
    SnakeState state;

private: // scenes
    SceneStart _scene_startApp;




    /// @deprecated: test
#ifdef DEPRECATED
private: // scene app started
    lcg::Scene sceneStartApp;
    lcg::Image logo;
    lcg::Sprite* test = nullptr;
    lcg::Animation testAnim;
    lcg::Text* conOut = nullptr;
    lcg::Sprite* invitation = nullptr;
    lcg::Animation invitationAnim;
    float timeInvitation = 0.0f;
    void initStartApp();
private: // scene menu
    lcg::Scene sceneMenu;
    lcg::Text* mainMenu[3] = {nullptr};
    lcg::Image menuBackground;
    void initMainMenu();
protected:
#endif // DEPRECATED

};

#endif // GAME_H
