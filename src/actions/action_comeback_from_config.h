#ifndef ACTION_COMEBACK_FROM_CONFIG_H
#define ACTION_COMEBACK_FROM_CONFIG_H

#include "../../lib/engine.h"

class Action_ComebackFromConfig final : public lcg::Action
{
public:
    Action_ComebackFromConfig();
    virtual ~Action_ComebackFromConfig();

public: // name
    static std::string class_name() { return( "Action_ComebackFromConfig" ); }
    virtual std::string getName() const override { return( class_name() ); }
};

#endif // ACTION_COMEBACK_FROM_CONFIG_H
