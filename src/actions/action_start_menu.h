#ifndef ACTION_START_MENU_H
#define ACTION_START_MENU_H

#include "../../lib/engine.h"

class Action_StartMenu final : public lcg::Action
{
public:
    Action_StartMenu();
    virtual ~Action_StartMenu();

public: // name
    static std::string class_name() { return( "Action_StartMenu" ); }
    virtual std::string getName() const override { return( class_name() ); }
};

#endif // ACTION_START_MENU_H
