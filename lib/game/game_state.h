#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include "level.h"
#include "../input/user_input.h"

namespace lcg
{
    class GameState
    {
    public:
        GameState();
        virtual ~GameState();

        void init( UserInput& );

    protected:
        virtual void onInit(){}

    private: // user input
        UserInput* input = nullptr;

    protected:
        UserInput* getInput(){ return( input ); }

    private: // levels
        std::vector< Level* > levels;
        Level* _activeLevel = nullptr;
        Level* _deactiveLevel = nullptr;

    protected:
        void attach( Level* );
        Level* currentLevel();
        Level* deactiveLevel();

    public:
        const Level* getCurrentLevel() const;

    public:
        void launch( const std::string& );

    public: // current scene
        virtual const SceneBuilder* getScene() = 0;

    public: // prepare draw
        void prepareDraw();

    protected:
        virtual void onPrepareDraw(){}
    };
}

#endif // GAME_STATE_H
