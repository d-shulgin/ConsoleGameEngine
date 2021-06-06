#ifndef GAME_H
#define GAME_H

#include "../lib/engine.h"

class Game final : public lcg::Core
{
public:
    explicit Game( int = 0, int = 0 );

protected:
    virtual void onInit() override;
    virtual void onStart() override;
    virtual void onProcess() override;
    virtual void onPostProcess() override;
};

#endif // GAME_H
