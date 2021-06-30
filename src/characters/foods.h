#ifndef FOODS_H
#define FOODS_H

#include <vector>
#include <list>
#include "../../lib/engine.h"
#include "food.h"
#include "rabbit.h"
#include "apple.h"
#include "snake.h"

class Foods final
{
public:
    Foods();

    void init( int, int );
    void start();
    void process( float, const Snake& );
    void eat( const lcg::Position& );

private: // field size
    int widthField = 0;
    int heightField = 0;

private: // foods
    const int FOODS_MAX_AMOUNT = 4;
    std::list< Food* > foods;
    int idFood = 0;

    const float TIME_REBORN_FOOD = 2.0f; // sec
    float timeRebord = TIME_REBORN_FOOD;

    void processFoods( float );
    void logicFoods( float, const Snake& );
    bool giveFood( std::vector< lcg::Position >&, std::ofstream* file = nullptr );

public:
    const std::list< Food* >& getFoods() const { return( foods ); }

private: // apples
    std::vector< Apple > apples;

    bool giveApple();

private: // rabbits
    std::vector< Rabbit > rabbits;

    bool giveRabbit();

public: // callback
    class Callback
    {
    public:
        Callback(){}

        virtual void onFoodAdded() = 0;
        virtual void onFoodEaten( int, int, int ) = 0;
        virtual void onFoodEscaped( int ) = 0;
        virtual void onFoodChanged( int, float ) = 0;
    };

private:
    Callback* handler = nullptr;

public:
    void setCallback( Callback* h ){ handler = h; }
};

#endif // FOODS_H
