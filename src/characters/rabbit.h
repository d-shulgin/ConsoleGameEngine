#ifndef RABBIT_H
#define RABBIT_H

#include "food.h"

class Rabbit final : public Food
{
public:
    explicit Rabbit( int = 0 );
    virtual ~Rabbit();

public: // score
    virtual int getScore() const override { return( 200 ); }
};

#endif // RABBIT_H
