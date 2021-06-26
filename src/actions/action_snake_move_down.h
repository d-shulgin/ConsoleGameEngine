#ifndef ACTION_SNAKE_MOVE_DOWN_H
#define ACTION_SNAKE_MOVE_DOWN_H

#include "../../lib/engine.h"

class Action_SnakeMoveDown final : public lcg::Action
{
public:
    Action_SnakeMoveDown();
    virtual ~Action_SnakeMoveDown();

public: // name
    static std::string class_name() { return( "Action_SnakeMoveDown" ); }
    virtual std::string getName() const override { return( class_name() ); }
    virtual std::string getDescription() const override
    {
        return( "Move down" );
    }
};

#endif // ACTION_SNAKE_MOVE_DOWN_H
