#include "game_state.h"
#include <algorithm>

namespace lcg
{
    GameState::GameState()
    {
    }
    void GameState::init( UserInput& ui )
    {
        levels.clear();
        input = &ui;
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
            {
                _activeLevel = level;
                level -> activate();
            }
            levels.push_back( level );
        }
        return;
    }
    Level* GameState::currentLevel()
    {
        if( nullptr != _activeLevel )
            return( _activeLevel );
        /// @todo: throw
        return( nullptr );
    }
    const Level* GameState::getCurrentLevel() const
    {
        if( nullptr != _activeLevel )
            return( _activeLevel );
        /// @todo: throw
        return( nullptr );
    }
    void GameState::launch( const std::string& nameLevel )
    {
        if( nameLevel.length() > 0
            && currentLevel()->getName() != nameLevel )
        {
            auto it = std::find_if( levels.begin()
                                    , levels.end()
                                    , [&nameLevel](Level* i)->bool{ return(i->getName() == nameLevel); } );
            if( it != levels.end() )
            {
                currentLevel()->deactivate();
                _activeLevel = *it;
                currentLevel()->activate();
            }
        }
        return;
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