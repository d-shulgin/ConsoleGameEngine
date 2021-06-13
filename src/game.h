#ifndef GAME_H
#define GAME_H

#include "../lib/engine.h"
#include "game_state.h"

class Game final : public lcg::Core
{
    typedef lcg::Position Pos;
public:
    explicit Game( int = 0, int = 0 );

private: // state
    GameState state;

protected: // initialize
    virtual void onInit() override;

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
    virtual void onStart() override;
    virtual void onProcess( float, DWORD, DWORD ) override;
    virtual void onPostProcess() override;
    virtual void onPrepareDraw() override;
    virtual const lcg::Scene* getScene() const override;
    virtual void nextScene() override;
};

#endif // GAME_H
