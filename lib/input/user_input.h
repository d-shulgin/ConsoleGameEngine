#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <vector>
#include <string>
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

    public: // Virtual-Key Codes
        static std::string getVKeyName( int );
    };
}

#endif // USER_INPUT_H
