#ifndef APPLE_H
#define APPLE_H

#include "food.h"

class Apple final : public Food
{
public:
    explicit Apple( int = 0 );
    virtual ~Apple();

public: // score
    virtual int getScore() const override { return( 10 ); }
};

#endif // APPLE_H
