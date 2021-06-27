#ifndef FOOD_H
#define FOOD_H

#include "../../lib/engine.h"

class Food
{
    int _id;
public:
    explicit Food( int = 0 );
    virtual ~Food();

    int id() const { return( _id ); }
    void process( float );

protected:
    virtual void onProcess( float ){ return; }

public:
    template< typename T >
    T* as()
    {
        if( typeid(T).before(typeid(*this)) || typeid(T) == typeid(*this) )
        {
            return( dynamic_cast<T*>(this) );
        }
        return( nullptr );
    }
    template< typename T >
    const T* as_const() const
    {
        if( typeid(T).before(typeid(*this)) || typeid(T) == typeid(*this) )
        {
            return( dynamic_cast<const T*>(this) );
        }
        return( nullptr );
    }

private: // active
    bool active = false;

public:
    bool getActive() const { return( active ); }
    void setActive( bool activate )
    {
        active = activate;
        onActivated();
    }

protected:
    virtual void onActivated(){}

private: // position
    lcg::Position position;

public:
    const lcg::Position& getPosition() const { return( position ); }
    void setPosition( const lcg::Position& p ){ position = p; }
    void setPosition( short int x, short int y )
    {
        setPosition( lcg::Position(x, y) );
        return;
    }

public: // score
    virtual int getScore() const { return( 0 ); }
    virtual int getHP() const { return( 0 ); }
};

#endif // FOOD_H
