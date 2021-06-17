#ifndef ACTION_CHOICE_ITEM_H
#define ACTION_CHOICE_ITEM_H

#include "../../lib/engine.h"

class Action_ChoiceItem final : public lcg::Action
{
public:
    Action_ChoiceItem();
    virtual ~Action_ChoiceItem();

public: // name
    static std::string class_name() { return( "Action_ChoiceItem" ); }
    virtual std::string getName() const override { return( class_name() ); }
    virtual std::string getDescription() const override
    {
        return( "Select a menu item" );
    }
};

#endif // ACTION_CHOICE_ITEM_H
