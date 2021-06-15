#ifndef START_APP_H
#define START_APP_H

#include "lib/engine.h"

class StartApp final : public lcg::Level
{
public:
    StartApp();
    virtual ~StartApp();

public: // name
    static std::string class_name() { return( "StartApp" ); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // choice
    virtual void onActivate() override;
    virtual void onDeactivate() override;

public: // prepare draw
    void prepareDraw();
};

#endif // START_APP_H
