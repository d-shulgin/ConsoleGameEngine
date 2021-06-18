#ifndef SHOW_CONFIG_H
#define SHOW_CONFIG_H

#include "lib/engine.h"

class ShowConfig final : public lcg::Level
{
public:
    ShowConfig();
    virtual ~ShowConfig();

protected:
    virtual void onInit( lcg::UserInput* ) override;

public: // name
    static std::string class_name() { return( "ShowConfig" ); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // choice
    virtual void onActivate() override;

public: // prepare draw
    void prepareDraw();

private: //
    std::string backLevelName;

public:
    const std::string& getBack() const { return( backLevelName ); }
    void setBack( const std::string& v ){ backLevelName = v; }
};

#endif // SHOW_CONFIG_H
