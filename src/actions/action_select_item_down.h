#ifndef ACTION_SELECT_ITEM_DOWN_H
#define ACTION_SELECT_ITEM_DOWN_H

#include "../../lib/engine.h"

class Action_SelectItemDown final : public lcg::Action
{
public:
    Action_SelectItemDown();
    virtual ~Action_SelectItemDown();

public: // name
    static std::string class_name() { return( "Action_SelectItemDown" ); }
    virtual std::string getName() const override { return( class_name() ); }
};

#endif // ACTION_SELECT_ITEM_DOWN_H
