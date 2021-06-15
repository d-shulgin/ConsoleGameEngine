#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <vector>
#include "../game/action.h"

namespace lcg
{
    class UserInput final
    {
    public:
        UserInput();
        ~UserInput();

        void postProcess();

    private: // actions
        std::vector< Action* > _actions;

    public:
        UserInput& attach( Action* );
    };
}

#endif // USER_INPUT_H
