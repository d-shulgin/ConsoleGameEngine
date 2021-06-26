#ifndef ACTION_MAIN_MENU_H
#define ACTION_MAIN_MENU_H

#include "../../lib/engine.h"

class Action_MainMenu final : public lcg::Action
{
public:
    Action_MainMenu();
    virtual ~Action_MainMenu();

public: // name
    static std::string class_name() { return( "Action_MainMenu" ); }
    virtual std::string getName() const override { return( class_name() ); }
    virtual std::string getDescription() const override
    {
        return( "Show main menu" );
    }
};

#endif // ACTION_MAIN_MENU_H
