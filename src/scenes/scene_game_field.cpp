#include "scene_game_field.h"
#include <algorithm>
#include <string>
#include <sstream>

SceneGameField::SceneGameField()
    : lcg::SceneBuilder()
{
}
SceneGameField::~SceneGameField()
{
}

void SceneGameField::onBuild()
{
    rsc.load();

    lcg::Group* root = nullptr;
    _scene.setRoot( root = new lcg::Group("root") );
    if( root != nullptr )
    {
        root -> addChild( background      = new lcg::Sprite("bgr") );
        root -> addChild( applesGroup     = new lcg::Group ("apples") );
        root -> addChild( rabbitsGroup    = new lcg::Group ("rabbits") );
        root -> addChild( snakeGroup      = new lcg::Group ("snake") );
        root -> addChild( indicatorLive   = new lcg::Text  ("live_score") );
        root -> addChild( indicatorScores = new lcg::Text  ("score_points") );
        loadBackground();
        loadLiveScore();
        loadScorePoints();
    }
    return;
}
void SceneGameField::loadBackground()
{
    if( nullptr != background )
    {
        background -> setImage( rsc.background() );
        background -> setPosition(0, 0);
    }
    return;
}
void SceneGameField::loadLiveScore()
{
    if( nullptr != indicatorLive )
    {
        indicatorLive -> setColor( lcg::ColorID::light_red );
        indicatorLive -> setBackgroundColor( lcg::ColorID::blue );
        indicatorLive -> setPosition( 9, 4 );
        indicatorLive -> setVisible( false );
    }
    return;
}
void SceneGameField::setLiveScore( int liveScore, int maxScore )
{
    if( nullptr != indicatorLive )
    {
        std::string liveScale( liveScore, '@' );
        indicatorLive -> setString( liveScale );
        indicatorLive -> setPosition( 9 + maxScore - liveScore, 4 );
        indicatorLive -> setVisible( true );
    }
    return;
}
void SceneGameField::loadScorePoints()
{
    if( nullptr != indicatorScores )
    {
        indicatorScores -> setColor( lcg::ColorID::light_green );
        indicatorScores -> setBackgroundColor( lcg::ColorID::blue );
        indicatorScores -> setPosition( 39, 4 );
        indicatorScores -> setVisible( false );
    }
    return;
}
void SceneGameField::setScorePoints( const std::string& value )
{
    if( nullptr != indicatorScores )
    {
        indicatorScores -> setString( value );
        indicatorScores -> setPosition( 39 - value.length(), 4 );
        indicatorScores -> setVisible( true );
    }
    return;
}
void SceneGameField::setSnake( const Snake& snake )
{
    if( nullptr != snakeGroup )
    {
        std::size_t length = snake.getChainLinks().size() > chainLinks.size() ? snake.getChainLinks().size()
                                                                              : chainLinks.size();
        for( std::size_t i = 0; i < length; i++ )
        {
            std::stringstream ss;
            ss << i;
            lcg::Sprite* viewSnakePart = nullptr;
            if( i < chainLinks.size() )
                viewSnakePart = chainLinks[i];
            else
            {
                chainLinks.push_back( viewSnakePart = new lcg::Sprite("snake_"+ss.str()) );
                snakeGroup -> addChild( viewSnakePart );
            }
            if( nullptr != viewSnakePart )
            {
                if( i < snake.getChainLinks().size() )
                {
                    const ChainLink& link = snake.getChainLinks()[i];
                    int x = 4 + 7*( snake.getDeathAnimation() ? link.getLastPosition().x()
                                                              : link.getPosition().x() );
                    int y = 7 + 3*( snake.getDeathAnimation() ? link.getLastPosition().y()
                                                              : link.getPosition().y() );
                    if( 0 == i )
                        viewSnakePart -> setImage( rsc.snake(Resources::snakeHead) );
                    else
                        viewSnakePart -> setImage( rsc.snake(Resources::snakeBody) );
                    viewSnakePart -> setVisible( true );
                    viewSnakePart -> setPosition( x, y );
                }
                else
                    viewSnakePart -> setVisible( false );
            }
        }
        setLiveScore( snake.getLivePoints(), Snake::LIVE_POINTS_MAX );
        snakeGroup->setVisible( snake.checkShowed() );
    }
    return;
}
void SceneGameField::giveApple( const Apple* apple )
{
    auto it = std::find_if( apples.begin()
                            , apples.end()
                            , [&apple](AppleSprite a){ return( a.id() == apple->id() ); } );

    int x = 4 + apple->getPosition().x()*7;
    int y = 7 + apple->getPosition().y()*3;

    if( it != apples.end() )
    {
        (*it).show( x, y );
    }
    else
    {

        apples.push_back( AppleSprite(apple->id()) );
        apples.back().build( apples.size(), applesGroup, rsc );
        apples.back().show( x, y );
    }
    return;
}
void SceneGameField::giveRabbit( const Rabbit* rabbit )
{
    auto it = std::find_if( rabbits.begin()
                            , rabbits.end()
                            , [&rabbit](RabbitSprite r){ return( r.id() == rabbit->id() ); } );

    int x = 4 + rabbit->getPosition().x()*7;
    int y = 7 + rabbit->getPosition().y()*3;

    if( it != rabbits.end() )
    {
        (*it).show( x, y, rabbit->getTimeLive() );
    }
    else
    {
        rabbits.push_back( RabbitSprite(rabbit->id()) );
        rabbits.back().build( rabbits.size(), rabbitsGroup, rsc );
        rabbits.back().show( x, y, rabbit->getTimeLive() );
    }
    return;
}
//int SceneGameField::giveRabbit( int cl, int rw, float time )
//{
//    if( rw < 1 )
//        return( -1 );
//    int x = 4 + cl*7;
//    int y = 7 + rw*3;
//    if( !rabbits.empty() )
//    {
//        for( std::size_t i = 0; i < rabbits.size(); i++ )
//            if( rabbits[i].checkFree() )
//            {
//                rabbits[i].show(x, y, time);
//                return( static_cast<int>(i) );
//            }
//    }
//    if( rabbits.size() < 4 )
//    {
//        rabbits.push_back( RabbitSprite() );
//        rabbits.back().build( static_cast<int>(rabbits.size() - 1)
//                              , rabbitsGroup, rsc );
//        rabbits.back().show(x, y, time);
//        return( static_cast<int>(rabbits.size() - 1) );
//    }
//    return( -1 );
//}
void SceneGameField::setFoods( const Foods& foods )
{
    if( nullptr != applesGroup && nullptr != rabbitsGroup )
    {
        std::list< Food* >::const_iterator it = foods.getFoods().cbegin();
        while( it != foods.getFoods().cend() )
        {
            const Food* food = *it;
            if( food->as_const< Apple >() != nullptr )
                giveApple( food->as_const< Apple >() );
            else if( food->as_const< Rabbit >() != nullptr )
                giveRabbit( food->as_const< Rabbit >() );
            ++it;
        }
    }
    return;
}
void SceneGameField::changeFood( int idFood, float dt )
{
    for( std::size_t i = 0; i < rabbits.size(); ++i )
    {
        RabbitSprite& rabbit = rabbits[i];
        if( rabbit.id() == idFood )
        {
            rabbit.setElapsedTime( dt );
            break;
        }
    }
    return;
}
void SceneGameField::hideFood( int idFood )
{
    for( std::size_t i = 0; i < apples.size(); ++i )
    {
        AppleSprite& apple = apples[i];
        if( apple.id() == idFood )
        {
            apple.hide();
            break;
        }
    }
    for( std::size_t i = 0; i < rabbits.size(); ++i )
    {
        RabbitSprite& rabbit = rabbits[i];
        if( rabbit.id() == idFood )
        {
            rabbit.hide();
            break;
        }
    }
    return;
}
void SceneGameField::onProcess( float dt )
{
    if( getPaused() )
        return;
    return;
}
void SceneGameField::restart()
{
    for( std::size_t i = 0; i < apples.size(); ++i )
    {
        AppleSprite& apple = apples[i];
        apple.hide();
    }
    for( std::size_t i = 0; i < rabbits.size(); ++i )
    {
        RabbitSprite& rabbit = rabbits[i];
        rabbit.hide();
    }
    return;
}


void SceneGameField::Resources::load()
{
    // background |
    {
        _background = lcg::Image( 120, 50 );
        _background.beginSymbols().beginColors().beginBgColors()
                .addSymbols( "========================================================================================================================" )
                .addSymbols( "|                                                                                                                      |" )
                .addSymbols( "|                                                                                                                      |" )
                .addSymbols( "|      -----------         --------------                                                                              |" )
                .addSymbols( "| Live | @@@@@@@ |   Score | 0000000000 |                                                                              |" )
                .addSymbols( "========================================================================================================================" )
                .addSymbols( "|======================================================================================================================|" )
                .addSymbols( "|1 |1234567       1234567       1234567       1234567       1234567       1234567       1234567       1234567       |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|1 |                                                                                                                |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|1 |                                                                                                                |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|1 |                                                                                                                |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|1 |                                                                                                                |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|1 |                                                                                                                |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|1 |                                                                                                                |  |" )
                .addSymbols( "|2 |                                                                                                                |  |" )
                .addSymbols( "|3 |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|  |                                                                                                                |  |" )
                .addSymbols( "|======================================================================================================================|" )

                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "BbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbB" )
                .addColors( "BbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbB" )
                .addColors( "BbbbbbbBBBBBBBBBBBbbbbbbbbbBBBBBBBBBBBBBBbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbB" )
                .addColors( "BbYYYYbBbaaaaaaabBbbbYYYYYbBaaaaaaaaaaaaBbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbB" )
                .addColors( "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" )
                .addColors( "bbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbB                                                                                                                Bbbb" )
                .addColors( "bbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbb" )

                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbb                                                                                                                bbbb" )
                .addBgColors( "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" );
    }
    // rabbit     |
    {
        _rabbit[0] = lcg::Image( 7, 3 );
        _rabbit[0].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[1] = lcg::Image( 7, 3 );
        _rabbit[1].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[2] = lcg::Image( 7, 3 );
        _rabbit[2].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[3] = lcg::Image( 7, 3 );
        _rabbit[3].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[4] = lcg::Image( 7, 3 );
        _rabbit[4].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[5] = lcg::Image( 7, 3 );
        _rabbit[5].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[6] = lcg::Image( 7, 3 );
        _rabbit[6].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[7] = lcg::Image( 7, 3 );
        _rabbit[7].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[8] = lcg::Image( 7, 3 );
        _rabbit[8].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[9] = lcg::Image( 7, 3 );
        _rabbit[9].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(=-.-=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[10] = lcg::Image( 7, 3 );
        _rabbit[10].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='o'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[11] = lcg::Image( 7, 3 );
        _rabbit[11].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='-'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[12] = lcg::Image( 7, 3 );
        _rabbit[12].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='-'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[13] = lcg::Image( 7, 3 );
        _rabbit[13].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='-'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[14] = lcg::Image( 7, 3 );
        _rabbit[14].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='o'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[15] = lcg::Image( 7, 3 );
        _rabbit[15].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='-'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
        _rabbit[16] = lcg::Image( 7, 3 );
        _rabbit[16].beginSymbols().beginColors()
                .addSymbols("(\\__/) ")
                .addSymbols("(='-'=)")
                .addSymbols("(\")_(\")")
                .addColors ("WWWWWWW")
                .addColors ("WWGaGWW")
                .addColors ("WRWWWRW");
    }
    // think      |
    {
        _think[0] = lcg::Image( 7, 3 );
        _think[0].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_Zzz_)")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[1] = lcg::Image( 7, 3 );
        _think[1].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_9_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[2] = lcg::Image( 7, 3 );
        _think[2].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_8_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[3] = lcg::Image( 7, 3 );
        _think[3].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_7_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[4] = lcg::Image( 7, 3 );
        _think[4].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_6_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[5] = lcg::Image( 7, 3 );
        _think[5].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_5_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[6] = lcg::Image( 7, 3 );
        _think[6].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_4_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[7] = lcg::Image( 7, 3 );
        _think[7].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_3_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[8] = lcg::Image( 7, 3 );
        _think[8].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_2_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[9] = lcg::Image( 7, 3 );
        _think[9].beginSymbols().beginColors()
                .addSymbols(" ___   ")
                .addSymbols("(_1_)  ")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[10] = lcg::Image( 7, 3 );
        _think[10].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_Aaa_)")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[11] = lcg::Image( 7, 3 );
        _think[11].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_???_)")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[12] = lcg::Image( 7, 3 );
        _think[12].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_???_)")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[13] = lcg::Image( 7, 3 );
        _think[13].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_Bye_)")
                .addSymbols("  V    ")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
        _think[14] = lcg::Image( 7, 3 );
        _think[14].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_Bye_)")
                .addSymbols("  V    ")
                .addColors ("wwwwwww")
                .addColors ("wwwwwww")
                .addColors ("wwwwwww");
        _think[15] = lcg::Image( 7, 3 );
        _think[15].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_Bye_)")
                .addSymbols("  V    ")
                .addColors ("aaaaaaa")
                .addColors ("aaaaaaa")
                .addColors ("aaaaaaa");
        _think[16] = lcg::Image( 7, 3 );
        _think[16].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_Bye_)")
                .addSymbols("  V    ")
                .addColors ("       ")
                .addColors ("       ")
                .addColors ("       ");
    }
    // snake      |
    {
        _snake[snakeHead] = lcg::Image( 7, 3 );
        _snake[snakeHead].beginSymbols().beginColors()
                .addSymbols("(o)_(o)")
                .addSymbols("(_____)")
                .addSymbols("(__S__)")
                .addColors ("WYWWWYW")
                .addColors ("WWWWWWW")
                .addColors ("WWWRWWW");
        _snake[snakeBody] = lcg::Image( 7, 3 );
        _snake[snakeBody].beginSymbols().beginColors()
                .addSymbols(" _____ ")
                .addSymbols("(_____)")
                .addSymbols("(_____)")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW")
                .addColors ("WWWWWWW");
    }
    // apple      |
    {
        _apple = lcg::Image( 7, 3 );
        _apple .beginSymbols().beginColors()
                .addSymbols(" __?__ ")
                .addSymbols("(     )")
                .addSymbols(" \\_A_/ ")
                .addColors ("WRRGRRW")
                .addColors ("RRRRRRR")
                .addColors ("RRRRRRR");
    }
    //
    {



//        " _____ "
//        "(_Bye_)"
//        "  V    "
//        "(\__/)"
//        "(=o.o=)"
//        "\"()_(\")"
    }
    return;
}


void SceneGameField::RabbitSprite::build( int index, lcg::Group* root, const Resources& rsc )
{
    if( nullptr != root )
    {
        std::stringstream ss;
        ss << index;
        root -> addChild( body = new lcg::Sprite("rabbit_" + ss.str()) );
        root -> addChild( think = new lcg::Sprite("think_"+ss.str()) );
        if( nullptr != body )
        {
            int i = 0;
            const lcg::Image* image = rsc.rabbit(i++);
            while( nullptr != image )
            {
                bodyAnim.addImage( image );
                image = rsc.rabbit(i++);
            }
            bodyAnim.setCycle( false );
            body -> setVisible( false );
            body -> setImage( bodyAnim.getImage() );
        }
        if( nullptr != think )
        {
            int i = 0;
            const lcg::Image* image = rsc.think(i++);
            while( nullptr != image )
            {
                thinkAnim.addImage( image );
                image = rsc.think(i++);
            }
            thinkAnim.setCycle( false );
            think -> setVisible( false );
            think -> setImage( thinkAnim.getImage() );
        }
    }
    return;
}
void SceneGameField::RabbitSprite::show( short int x, short int y, float time )
{
    float speed = static_cast<float>(bodyAnim.getImages().size()) / time;
    bodyAnim.setSpeed( speed );
    bodyAnim.start();
    thinkAnim.setSpeed( speed );
    thinkAnim.start();
    if( nullptr != body )
    {
        body -> setImage( bodyAnim.getImage() );
        body -> setPosition( x, y );
        body -> setVisible( true );
    }
    if( nullptr != think )
    {
        think -> setImage( thinkAnim.getImage() );
        think -> setPosition( x, y - 3 );
        think -> setVisible( true );
    }
    return;
}
void SceneGameField::RabbitSprite::hide()
{
    bodyAnim.stop();
    thinkAnim.stop();
    if( nullptr != body )
    {
        body -> setVisible( false );
    }
    if( nullptr != think )
    {
        think -> setVisible( false );
    }
    return;
}
void SceneGameField::RabbitSprite::setElapsedTime( float dt )
{
    if( nullptr != body && nullptr != think )
    {
        bodyAnim.process( dt );
        thinkAnim.process( dt );
        body -> setImage( bodyAnim.getImage() );
        think -> setImage( thinkAnim.getImage() );
    }
    return;
}
//void SceneGameField::RabbitSprite::process( float dt )
//{
//    if( !checkFree() && nullptr != body && nullptr != think )
//    {
//        bodyAnim.process( dt );
//        thinkAnim.process( dt );
//        body -> setImage( bodyAnim.getImage() );
//        think -> setImage( thinkAnim.getImage() );
//        if( !bodyAnim.getActive() )
//        {
//            _free = true;
//            body -> setVisible( false );
//            think -> setVisible( false );
//        }
//    }
//    return;
//}


void SceneGameField::AppleSprite::build( int index, lcg::Group* root, const Resources& rsc )
{
    if( nullptr != root )
    {
        std::stringstream ss;
        ss << index;
        root -> addChild( apple = new lcg::Sprite("apple_" + ss.str()) );
        if( nullptr != apple )
        {
            apple -> setImage( rsc.apple() );
            apple -> setVisible( false );
        }
    }
    return;
}
void SceneGameField::AppleSprite::show( short x, short y )
{
    if( nullptr != apple )
    {
        apple -> setVisible( true );
        apple -> setPosition( x, y );
    }
    return;
}
void SceneGameField::AppleSprite::hide()
{
    if( nullptr != apple )
    {
        apple -> setVisible( false );
    }
    return;
}
