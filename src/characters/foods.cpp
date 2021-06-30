#include "foods.h"
#include <chrono>
#include <random>
#include <algorithm>

#include <fstream>
#include <iomanip>

Foods::Foods()
{
}
void Foods::init( int w, int h )
{
    widthField = w;
    heightField = h;
    apples.clear();
    apples.reserve( FOODS_MAX_AMOUNT );
    rabbits.clear();
    rabbits.reserve( FOODS_MAX_AMOUNT );
}
void Foods::start()
{
    foods.clear();
    timeRebord = TIME_REBORN_FOOD;
    for( std::size_t i = 0; i < apples.size(); ++i )
        apples[i].setActive( false );
    for( std::size_t i = 0; i < rabbits.size(); ++i )
        rabbits[i].setActive( false );
    return;
}
void Foods::process( float dt, const Snake& snake )
{
    processFoods( dt );
    logicFoods( dt, snake );
    return;
}
void Foods::eat( const lcg::Position& snakePosition )
{
    Food* food = nullptr;
    std::list<Food*>::iterator it = foods.begin();
    while( it != foods.end() )
    {
        food = *it;
        if( nullptr != food && food->getPosition() == snakePosition )
        {
            it = foods.erase( it );
            break;
        }
        ++it;
        food = nullptr;
    }
    if( nullptr != food )
    {
        food -> setActive( false );
        if( nullptr != handler )
            handler -> onFoodEaten( food->id(), food->getScore(), food->getHP() );
    }
    return;
}
void Foods::processFoods( float dt )
{
    std::list<Food*>::iterator it = foods.begin();
    while( it != foods.end() )
    {
        Food* food = *it;
        if( nullptr != food )
        {
            if( food -> getActive() )
            {
                food -> process( dt );
                if( food->as_const<Rabbit>() != nullptr && nullptr != handler )
                {
                    handler -> onFoodChanged( food->id(), dt );
                }
            }
            if( !food -> getActive() )
            {
                it = foods.erase( it );
                if( nullptr != handler )
                    handler -> onFoodEscaped( food->id() );
            }
        }
        if( it != foods.end() )
            ++it;
    }
    return;
}
void Foods::logicFoods( float dt, const Snake& snake )
{
    timeRebord -= dt;
    if( timeRebord <= 0.0f )
    {
        std::ofstream file( "log.txt", std::ofstream::ate | std::ofstream::app );
        file << std::endl << std::endl << "---------------- Log opened" << std::endl;
        file << "Field size: (" << widthField << " x " << heightField << ")" << std::endl;

        std::vector< lcg::Position > busyPosition;
        busyPosition.reserve( snake.getLength() + 1 + foods.size() );
        file << "Snake: ";
        for( std::size_t i = 0; i < snake.getChainLinks().size(); ++i )
        {
            const ChainLink& link = snake.getChainLinks()[i];
            busyPosition.push_back( link.getPosition() );
            file << "(" << link.getPosition().x() << "; " << link.getPosition().y() << ")";
        }
        file << std::endl;
        file << "Snake last tail: (" << snake.getLastTailPosition().x() << ";"
             << snake.getLastTailPosition().y() << ")" << std::endl;
        busyPosition.push_back( snake.getLastTailPosition() );
        file << "Foods ("  << foods.size() << "): " << std::endl;
        for( std::list<Food*>::const_iterator it = foods.cbegin(); it != foods.cend(); ++it )
        {
            const Food* food = *it;
            if( nullptr != food )
            {
                busyPosition.push_back( food->getPosition() );
                file << (food->as_const<Apple>() != nullptr ? "Apple"
                                                            : food->as_const<Rabbit>() != nullptr ? "Rabbit"
                                                                                                  : "Unknown");
                file << " (" << food->getPosition().x() << "; "
                     << food->getPosition().y() << ")";
                file << " active = " << (food->getActive() ? "true" : "false")
                     << " score = " << food->getScore();
                file << " HP = " << food->getHP() << std::endl;
            }
        }
        if( giveFood(busyPosition, &file) )
        {
            timeRebord = TIME_REBORN_FOOD;
            if( nullptr != handler )
                handler -> onFoodAdded();
        }

        file << "---------------- Log closed" << std::endl;
        file.close();

        /// @deprecated : need delete (test)
        timeRebord = TIME_REBORN_FOOD;
    }
    return;
}
bool Foods::giveFood( std::vector< lcg::Position >& busy, std::ofstream* file )
{
    if( static_cast<int>(foods.size()) < FOODS_MAX_AMOUNT )
    {
        unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937_64 gen(seed);

        if( file != nullptr )
        {
            (*file) << "Foods: " << foods.size()
                    << "; Apples: " << apples.size()
                    << "; Rabbits: " << rabbits.size() << std::endl;
        }

        if( (gen() % 4 < 3 && giveApple()) || giveRabbit() )
        {
            if( file != nullptr )
            {
                (*file) << "============= give me any food ================" << std::endl;
                (*file) << "Foods: " << foods.size()
                        << "; Apples: " << apples.size()
                        << "; Rabbits: " << rabbits.size() << std::endl;
            }

            Food* food = foods.back();
            if( nullptr != food )
            {
                short x, y;
                std::sort( busy.begin()
                           , busy.end()
                           , [this](lcg::Position a, lcg::Position b){
                    return((a.x()+a.y()*widthField) < (b.x()+b.y()*widthField)); } );

                std::vector< short int > free;
                free.reserve( widthField*heightField );
                busy.push_back( lcg::Position(0, heightField) );

                if( file != nullptr )
                {
                    (*file) << "After sort:" << std::endl;
                    for( std::size_t i = 0; i < busy.size(); ++i )
                    {
                        lcg::Position p = busy[i];
                        (*file) << "(" << p.x() << "; " << p.y() << ")";
                        if( (i+1)%5 == 0 || i == busy.size()-1 )
                            (*file) << std::endl;
                    }
                }

                short int index = (food->as<Rabbit>() != nullptr ? (short int)widthField : 0);
                if( nullptr != file )
                {
                    (*file) << "create free block..." << std::endl;
                    (*file) << "Start index = " << index << std::endl;
                }
                for( std::size_t i = 0; i < busy.size(); ++i )
                {
                    if( nullptr != file )
                    {
                        short xT = busy[i].x();
                        short yT = busy[i].y();
                        (*file) << "check busy(" << i
                                << ") => (" << xT << "; " << yT
                                << ") => max index = " << (xT+yT*widthField)
                                << " index = " << index << std::endl;
                    }
                    while( index < busy[i].x() + busy[i].y()*widthField
                           && index < widthField*heightField )
                    {
                        free.push_back( index );
                        if( nullptr != file)
                        {
                            short xT = index % widthField;
                            short yT = index / widthField;
                            (*file) << "push = " << index << "(" << xT << "; " << yT << ")";
                        }
                        index ++;
                        if( nullptr != file)
                        {
                            (*file) << ";    next index = " << index << std::endl;
                        }
                    }
                    index ++; // skip index, because 'while' found busy index (get next index)
                    if( nullptr != file)
                    {
                        (*file) << "...." << std::endl;
                    }
                }

                if( nullptr != file )
                {
                    (*file) << std::endl << "free (" << free.size() << "): " << std::endl;
                    for( size_t i = 0; i < free.size(); ++i )
                    {
                        short int xT = free[i]%widthField;
                        short int yT = free[i]/widthField;
                        (*file) << "(" << std::setw(2) << std::setfill(' ') << xT
                                << "; " << std::setw(2) << std::setfill(' ') << yT << ") ";
                        if( (i+1)%widthField == 0 || i == free.size()-1 )
                            (*file) << std::endl;
                    }
                }

                std::size_t i = gen() % free.size();

                if( nullptr != file )
                {
                    short int xT = free[i]%widthField;
                    short int yT = free[i]/widthField;
                    (*file) << "Random index = " << i
                            << " ( " << xT << "; " << yT << " )" << std::endl;
                }

                x = free[i]%widthField;
                y = free[i]/widthField;

                food -> setActive( true );
                food -> setPosition( x, y );
            }
            return( true );
        }
    }
    return( false );
}
bool Foods::giveApple()
{
    auto it = std::find_if( apples.begin()
                            , apples.end()
                            , [](Apple& apple){return(!apple.getActive());} );
    if( it != apples.end() )
    {
        Apple& apple = (*it);
        foods.push_back( &apple );
    }
    else if( static_cast<int>(apples.size()) < FOODS_MAX_AMOUNT )
    {
        apples.push_back( Apple( ++idFood ) );
        foods.push_back( &apples.back() );
    }
    else
        return( false );
    return( true );
}
bool Foods::giveRabbit()
{
    auto it = std::find_if( rabbits.begin()
                            , rabbits.end()
                            , [](Rabbit& rabbit){return(!rabbit.getActive());} );
    if( it != rabbits.end() )
    {
        Rabbit& rabbit = (*it);
        foods.push_back( &rabbit );
    }
    else if( static_cast<int>(rabbits.size()) < FOODS_MAX_AMOUNT )
    {
        rabbits.push_back( Rabbit( ++idFood ) );
        foods.push_back( &rabbits.back() );
    }
    else
        return( false );
    return( true );
}
