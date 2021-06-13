#ifndef LEVEL_H
#define LEVEL_H

#include "../lib/engine.h"
#include <vector>

enum class LevelID
{
    startedApp
    , startedMainMenu
    , startedSelectLoad
    , gameProcess
    , gameMainMenu
};

class Level
{
public:
    Level();

    void update( float );

private: // scenes
    std::vector< const lcg::Scene* > scenes;
    int showScene = 0;

public:
    void beginScene();
    void nextScene();
    const lcg::Scene* getScene() const;
    Level& attachScene( const lcg::Scene* const );
};

#endif // LEVEL_H
