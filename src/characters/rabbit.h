#ifndef RABBIT_H
#define RABBIT_H

#include "food.h"

class Rabbit final : public Food
{
public:
    explicit Rabbit( int = 0 );
    virtual ~Rabbit();

protected:
    virtual void onProcess( float ) override;
    virtual void onActivated() override;

public: // time live
    static constexpr float TIME_LIVE_MAX = 6.0f;

private:
    float timeLive = TIME_LIVE_MAX;

public:
    float getTimeLive() const { return( timeLive ); }

public: // health
    int health = 0;

public: // score
    virtual int getScore() const override { return( 200 ); }
    virtual int getHP() const override { return( health ); }
};

#endif // RABBIT_H
