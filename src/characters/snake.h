#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "../../lib/engine.h"

class ChainLink final
{
public:
    ChainLink(){}

private: // position
    lcg::Position position;
    lcg::Position lastPosition;

public:
    const lcg::Position& getPosition() const { return( position ); }
    const lcg::Position& getLastPosition() const { return( lastPosition ); }
    void setPosition( const lcg::Position& p )
    {
        lastPosition = position;
        position = p;
    }
    void setPosition( short int x, short int y ){ setPosition( lcg::Position(x, y) ); }
};

class Snake final
{
public:
    Snake();

    void init( const lcg::Position& );
    void process( float );

public: // live points
    static const int LIVE_POINTS_MAX = 7;

private:
    const int LIVE_POINTS_START = 3;
    int livePoints = LIVE_POINTS_START;

    void dieDieDie();

public:
    int getLivePoints() const { return( livePoints ); }
    void die();
    void biteYourself();

private: // die animation
    const int BLINK_MAX_COUNT = 3;
    const float BLINK_PERIOD = 1.0f;
    int blinkCount = 0;
    float timeBlink = BLINK_PERIOD;
    bool show = true;

    void logicDeathAnimation( float );
    void startDeathAnimation();

public:
    bool getDeathAnimation() const { return( blinkCount > 0 ); }
    bool checkShowed() const;

private: // length
    const int LENGTH_START = 4;
    const int LENGTH_MAX = 20;

private: // chain
    std::vector< ChainLink > chainLinks;
    lcg::Position restartPosition;
    lcg::Position tailPosition;
    lcg::Position lastTailPosition;

    void initChain( const lcg::Position& );
public:
    const std::vector< ChainLink >& getChainLinks() const { return( chainLinks ); }
    lcg::Position getPosition() const
    {
        if( getLength() > 0 )
            return( chainLinks[0].getPosition() );
        return( lcg::Position() );
    }
    const lcg::Position& getLastTailPosition() const { return( lastTailPosition ); }
    int getLength() const { return( chainLinks.size() ); }

public: // move control
    enum MoveDirection
    {
        Stop
        , moveLeft
        , moveRight
        , moveUp
        , moveDown
    };

private:
    const float TIME_MOVE_START = 0.40f; // sec
    const float TIME_MOVE_MINIMAL = 0.0750f; // sec

    MoveDirection direction = Stop;
    MoveDirection desiredDirection = Stop;
    float timeToMove = TIME_MOVE_START;
    float timeSpeed = TIME_MOVE_START;

    void logicMove( float );
    void changeDirection();
    void changePosition();
    void moveTo( const lcg::Position& );

public:
    MoveDirection getDirection() const { return( direction ); }
    void setDirection( MoveDirection moveDirection )
    {
        desiredDirection = moveDirection;
        if( getDirection() == Stop
            || (getDirection() != Stop && moveDirection == Stop) )
            changeDirection();
        return;
    }

public: // callback
    class Callback
    {
    public:
        Callback(){}

        virtual void onDirectionChanged( MoveDirection ) = 0;
        virtual void onPositionChanged( const lcg::Position& ) = 0;
        virtual void onShowChanged() = 0;
        virtual void onLivesOver() = 0;
        virtual void onDeathAnimationStarted() = 0;
    };

private:
    Callback* handler = nullptr;

public:
    void setCallback( Callback* h ){ handler = h; }
};

#endif // SNAKE_H
