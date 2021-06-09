#include "game_state.h"
#include <algorithm>

GameState::GameState()
{
}
const Level& GameState::crefLevel(const LevelID& id) const
{
    auto it = std::find_if( levels.cbegin()
                            , levels.cend()
                            , [&id](std::pair<LevelID, Level> i)->bool{ return(i.first == id); } );
    if( it != levels.cend() )
        return( it -> second );
    /// @todo: need throw
}
