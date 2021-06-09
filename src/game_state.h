#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <map>
#include "../lib/engine.h"
#include "level.h"

class GameState final
{
public:
    GameState();

private:
    LevelID id = LevelID::startedMainMenu;

private: // scenes
    std::map< LevelID, Level > levels;

public:
    Level& refLevel( const LevelID& id )
    {
        return( levels[id] );
    }
    const Level& crefLevel( const LevelID& id ) const;
};

#endif // GAME_STATE_H
