#ifndef ACTION_SNAKE_MOVE_RIGHT_H
#define ACTION_SNAKE_MOVE_RIGHT_H

#include "../../lib/engine.h"

class Action_SnakeMoveRight final : public lcg::Action
{
public:
    Action_SnakeMoveRight();
    virtual ~Action_SnakeMoveRight();

public: // name
    static std::string class_name() { return( "Action_SnakeMoveRight" ); }
    virtual std::string getName() const override { return( class_name() ); }
    virtual std::string getDescription() const override
    {
        return( "Move right" );
    }
};

#endif // ACTION_SNAKE_MOVE_RIGHT_H
