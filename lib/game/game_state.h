#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include "level.h"

namespace lcg
{
    class GameState
    {
    public:
        GameState();
        virtual ~GameState();

        void init();

    protected:
        virtual void onInit(){}

    private: // levels
        std::vector< Level* > levels;

    protected:
        void attach( Level* );
        Level* currentLevel();
        const Level* getCurrentLevel() const;

    public: // current scene
        virtual const SceneBuilder* getScene() = 0;

    public: // prepare draw
        void prepareDraw();

    protected:
        virtual void onPrepareDraw(){}


        /// @deprecated:
#ifdef DEPRECATED
    private: // scenes
        std::map< std::string, const Level* > levels;

    public:
        Level& refLevel( const LevelID& id )
        {
            return( levels[id] );
        }
        const Level& crefLevel( const LevelID& id ) const;
#endif // DEPRECATED
    };
}

#endif // GAME_STATE_H
