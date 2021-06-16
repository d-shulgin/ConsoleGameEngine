#ifndef ACTION_SELECT_ITEM_UP_H
#define ACTION_SELECT_ITEM_UP_H

#include "../../lib/engine.h"

class Action_SelectItemUp final : public lcg::Action
{
public:
    Action_SelectItemUp();
    virtual ~Action_SelectItemUp();

public: // name
    static std::string class_name() { return( "Action_SelectItemUp" ); }
    virtual std::string getName() const override { return( class_name() ); }
};

#endif // ACTION_SELECT_ITEM_UP_H
