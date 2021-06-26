#ifndef ACTION_SNAKE_MOVE_LEFT_H
#define ACTION_SNAKE_MOVE_LEFT_H

#include "../../lib/engine.h"

class Action_SnakeMoveLeft final : public lcg::Action
{
public:
    Action_SnakeMoveLeft();
    virtual ~Action_SnakeMoveLeft();

public: // name
    static std::string class_name() { return( "Action_SnakeMoveLeft" ); }
    virtual std::string getName() const override { return( class_name() ); }
    virtual std::string getDescription() const override
    {
        return( "Move left" );
    }
};

#endif // ACTION_SNAKE_MOVE_LEFT_H
