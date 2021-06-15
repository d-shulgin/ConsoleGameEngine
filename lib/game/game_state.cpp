#include "game_state.h"
#include <algorithm>

namespace lcg
{
    GameState::GameState()
    {
    }
    void GameState::init()
    {
        levels.clear();
        onInit();
        return;
    }
    void GameState::attach( Level* level )
    {
        if( nullptr == level )
            return;
        auto it = std::find_if( levels.begin()
                                , levels.end()
                                , [&level](Level* i)->bool{ return(i->getName() == level->getName()); } );
        if( it != levels.end() )
            *it = level;
        else
        {
            if( levels.empty() )
                level -> activate();
            levels.push_back( level );
        }
        return;
    }
    Level* GameState::currentLevel()
    {
        /// @todo: need logic choices level
        if( !levels.empty() )
            return( levels[0] );
        /// @todo: throw
        return( nullptr );
    }
    const Level* GameState::getCurrentLevel() const
    {
        /// @todo: need logic choices level
        if( !levels.empty() )
            return( levels[0] );
        /// @todo: throw
        return( nullptr );
    }
    void GameState::prepareDraw()
    {
        onPrepareDraw();
    }
#ifdef DEPRECATED
    const Level& GameState::crefLevel(const LevelID& id) const
    {
        auto it = std::find_if( levels.cbegin()
                                , levels.cend()
                                , [&id](std::pair<LevelID, Level> i)->bool{ return(i.first == id); } );
        if( it != levels.cend() )
            return( it -> second );
        /// @todo: need throw
    }
#endif // DEPRECATED
    GameState::~GameState()
    {
    }
}
