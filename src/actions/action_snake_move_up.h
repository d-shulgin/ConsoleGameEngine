#ifndef ACTION_SNAKE_MOVE_UP_H
#define ACTION_SNAKE_MOVE_UP_H

#include "../../lib/engine.h"

class Action_SnakeMoveUp final : public lcg::Action
{
public:
    Action_SnakeMoveUp();
    virtual ~Action_SnakeMoveUp();

public: // name
    static std::string class_name() { return( "Action_SnakeMoveUp" ); }
    virtual std::string getName() const override { return( class_name() ); }
    virtual std::string getDescription() const override
    {
        return( "Move up" );
    }
};

#endif // ACTION_SNAKE_MOVE_UP_H
