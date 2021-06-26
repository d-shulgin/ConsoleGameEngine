#include "snake.h"

Snake::Snake()
{
}
void Snake::init( const lcg::Position& position )
{
    restartPosition = position;
    show = checkShowed();
    initChain( position );
    return;
}
void Snake::process( float dt )
{
    logicMove( dt );
    logicDeathAnimation( dt );
    if( show != checkShowed() )
    {
        show = checkShowed();
        if( nullptr != handler )
            handler -> onShowChanged();
    }
    return;
}
void Snake::dieDieDie()
{
    initChain( restartPosition );
    setDirection( Stop );
    if( nullptr != handler )
        handler -> onLivesOver();
    return;
}
void Snake::die()
{
    livePoints --;
    startDeathAnimation();
    return;
}
void Snake::biteYourself()
{
    die();
}
void Snake::logicDeathAnimation( float dt )
{
    if( getDeathAnimation() )
    {
        timeBlink -= dt;
        if( timeBlink <= 0.0f )
        {
            blinkCount --;
            timeBlink = BLINK_PERIOD;
            if( !getDeathAnimation() )
            {
                if( 0 == livePoints )
                {
                    dieDieDie();
                    return;
                }
                timeToMove = TIME_MOVE_START;
                timeSpeed  = TIME_MOVE_START;
                initChain( restartPosition );
                setDirection( Stop );
                if( nullptr != handler )
                    handler -> onShowChanged();
            }
        }
    }
    return;
}
void Snake::startDeathAnimation()
{
    blinkCount = BLINK_MAX_COUNT;
    timeBlink = BLINK_PERIOD;
    if( nullptr != handler )
        handler -> onDeathAnimationStarted();
    return;
}
bool Snake::checkShowed() const
{
    return( !getDeathAnimation()
            || (getDeathAnimation() && timeBlink < BLINK_PERIOD/2.0f) );
}
void Snake::initChain( const lcg::Position& position )
{
    chainLinks.resize( 4 );
    for( std::size_t i = 0; i < chainLinks.size(); ++i )
    {
        ChainLink& link = chainLinks[i];
        link.setPosition( position.x() + i, position.y() );
        tailPosition = link.getPosition();
    }
    return;
}
void Snake::logicMove( float dt )
{
    if( getDirection() != Stop && !getDeathAnimation() )
    {
        timeToMove -= dt;
        if( timeToMove <= 0.0f )
        {
            timeToMove = timeSpeed;
            changeDirection();
            changePosition();
        }
    }
    return;
}
void Snake::changeDirection()
{
    MoveDirection lastDirection = direction;
    direction = desiredDirection;
    if( getDirection() != lastDirection )
    {
        if( nullptr != handler )
            handler -> onDirectionChanged( getDirection() );
    }
    return;
}
void Snake::changePosition()
{
    bool changed = true;
    switch( getDirection() )
    {
    case moveLeft : moveTo( lcg::Position(-1, 0) ); break;
    case moveRight: moveTo( lcg::Position(+1, 0) );  break;
    case moveUp   : moveTo( lcg::Position(0, -1) );  break;
    case moveDown : moveTo( lcg::Position(0, +1) );  break;
    case Stop:
    default:
        changed = false;
        break;
    }
    if( nullptr != handler
        && !chainLinks.empty()
        && changed )
    {
        const ChainLink& link = getChainLinks()[0];
        handler -> onPositionChanged( link.getPosition() );
    }
    return;
}
void Snake::moveTo( const lcg::Position& position )
{
    lcg::Position lastPosition;
    for( std::size_t i = 0; i < chainLinks.size(); ++i )
    {
        ChainLink& link = chainLinks[i];
        if( 0 == i )
        {
            tailPosition = link.getPosition();
            link.setPosition( link.getPosition() + position );
        }
        else
        {
            lastPosition = link.getPosition();
            link.setPosition( tailPosition );
            if( i < chainLinks.size() - 1 )
                tailPosition = lastPosition;
            lastTailPosition = lastPosition;
        }
    }
    return;
}
