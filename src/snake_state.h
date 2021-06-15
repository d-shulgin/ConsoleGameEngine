#ifndef SNAKE_STATE_H
#define SNAKE_STATE_H

#include "lib/engine.h"
#include "levels/package.h"

enum class SnakeStateID
{
    level_StartApp
};

class SnakeState final : public lcg::GameState
{
public:
    SnakeState();
    virtual ~SnakeState();

protected:
    virtual void onInit() override;

private: // Level: start application
    StartApp _level_StartApp;

public:
    StartApp& level_StartApp(){ return( _level_StartApp ); }

public: // current scene
    virtual const lcg::SceneBuilder* getScene() override;

public: // current level
    void currentLevelProcess( float );

protected: // prepare draw
    virtual void onPrepareDraw() override;
};

#endif // SNAKE_STATE_H
