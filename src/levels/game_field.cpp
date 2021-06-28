#include "game_field.h"
#include <algorithm>
#include <sstream>
#include "../scenes/scene_game_field.h"
#include "../scenes/scene_game_over.h"
#include "../scenes/scene_debug.h"

GameField::GameField()
{
    // snake
    handlerSnakeEvents = Handler_SnakeEvents( this );
    handlerSnakeEvents.eventShowChanged( &GameField::snakeShowChanged );
    handlerSnakeEvents.eventPositionChanged( &GameField::snakePositionChanged );
    handlerSnakeEvents.eventDirectionChanged( &GameField::snakeDirectionChanged );
    handlerSnakeEvents.eventDeathAnimationStarted( &GameField::snakeDie );
    handlerSnakeEvents.eventLivesOver( &GameField::logicGameOver );
    // foods
    handlerFoodsEvents = Handler_FoodsEvents( this );
    handlerFoodsEvents.eventFoodAdded( &GameField::foodAdded );
    handlerFoodsEvents.eventFoodEaten( &GameField::foodEaten );
    handlerFoodsEvents.eventFoodEscaped( &GameField::foodEscaped );
    handlerFoodsEvents.eventFoodChanged( &GameField::foodChanged );
    // actions
    handlerMoveUp.setFnPress   ( this, &GameField::moveUpSnake    );
    handlerMoveDown.setFnPress ( this, &GameField::moveDownSnake  );
    handlerMoveLeft.setFnPress ( this, &GameField::moveLeftSnake  );
    handlerMoveRight.setFnPress( this, &GameField::moveRightSnake );
}
void GameField::onInit( lcg::UserInput* input )
{
    snake.init( lcg::Position(FIELD_MAXWIDTH/2, FIELD_MAXHEIGHT/2) );
    snake.setCallback( &handlerSnakeEvents );
    foods.init( FIELD_MAXWIDTH, FIELD_MAXHEIGHT );
    foods.setCallback( &handlerFoodsEvents );
    initActions( input );
    return;
}
void GameField::onLogic( float dt )
{
    if( getActive() && !getWorksToDeactivate() )
    {
        snake.process( dt );
        foods.process( dt, snake );
//        if( !started() )
//        {
//            _started = true;
//            logicSnake();
//            logicFoods();
//        }

//        SceneGameField* sc_GF = nullptr;
//        auto it = std::find_if( refScenes().begin()
//                                , refScenes().end()
//                                , [](lcg::SceneBuilder* scene){
//                  return(scene->getName() == SceneGameField::class_name()); } );
//        if( it != refScenes().end() )
//        {
//            sc_GF = (*it)->as<SceneGameField>();
//        }
//        auto itD = std::find_if( refScenes().begin()
//                                , refScenes().end()
//                                , [](lcg::SceneBuilder* scene){
//                  return(scene->getName() == SceneDebug::class_name()); } );
//        if( itD != refScenes().end() )
//        {
//            std::stringstream ss;
//            SceneDebug* scene = (*itD)->as<SceneDebug>();
//            if( nullptr != scene )
//            {
//                ss << "   snake.size: " << snake.getChainLinks().size()
//                   << ";   view snake.size: " << sc_GF->getSnakeLength() << std::endl;
//                scene -> setConsole( ss.str() );
//            }
//        }
    }
    return;
}
// choice
void GameField::onActivate()
{
    bool restarted = false;
    if( !started() || gameOver() )
    {
        if( gameOver() )
            restarted = true;
        _started = true;
        _gameOver = false;
        scores = 0;
        incScores = 0;
        growScores = 0;
        snake.start();
        foods.start();
        snake.process( 0.0f );
        foods.process( 0.0f, snake );
        logicSnake();
        logicFoods();
        if( restarted )
            snakeDirectionChanged( snake.getDirection() );
    }
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        SceneGameField* scene = (*it)->as<SceneGameField>();
        if( nullptr != scene )
        {
            scene -> setPause( false );
            if( restarted )
            {
                std::stringstream ss;
                ss << scores;
                scene -> restart();
                scene -> setScorePoints( "" );
            }
        }
    }
    return;
}
void GameField::onDeactivate()
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        (*it)->as<SceneGameField>()->setPause( true );
    }
    return;
}
// prepare draw
void GameField::prepareDraw()
{
    beginScene();
    return;
}
// game
void GameField::logicGameOver()
{
    _gameOver = true;
    snakeDie();
    return;
}
// snake
void GameField::snakeShowChanged()
{
    logicSnake();
}
void GameField::snakePositionChanged( const lcg::Position& position )
{
    logicSnake();
    short int column = position.x();
    short int row = position.y();
    if( column < 0 || column >= FIELD_MAXWIDTH
        || row < 0 || row >= FIELD_MAXHEIGHT )
    {
        snake.die();
        return;
    }
    foods.eat( snake.getPosition() );
    return;
}
void GameField::snakeDirectionChanged( Snake::MoveDirection direction )
{
    switch( direction )
    {
    case Snake::moveUp :
        action_MoveDown.setActive( false );
        action_MoveUp.setActive( true );
        action_MoveLeft.setActive( true );
        action_MoveRight.setActive( true );
        break;
    case Snake::moveDown :
        action_MoveUp.setActive( false );
        action_MoveDown.setActive( true );
        action_MoveLeft.setActive( true );
        action_MoveRight.setActive( true );
        break;
    case Snake::moveLeft :
    case Snake::Stop:
        action_MoveRight.setActive( false );
        action_MoveUp.setActive( true );
        action_MoveDown.setActive( true );
        action_MoveLeft.setActive( true );
        break;
    case Snake::moveRight :
        action_MoveLeft.setActive( false );
        action_MoveUp.setActive( true );
        action_MoveDown.setActive( true );
        action_MoveRight.setActive( true );
        break;
    default:
        break;
    }
    return;
}
void GameField::snakeDie()
{
    action_MoveLeft.setActive( false );
    action_MoveUp.setActive( false );
    action_MoveDown.setActive( false );
    action_MoveRight.setActive( false );
    incScores = 0;
    growScores = 0;
    return;
}
void GameField::logicSnake()
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        SceneGameField* scene = (*it)->as<SceneGameField>();
        if( nullptr != scene )
            scene -> setSnake( snake );
    }
    return;
}
// foods
void GameField::foodAdded()
{
    logicFoods();
    return;
}
void GameField::foodEaten( int idFood, int points, int health )
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        SceneGameField* scene = (*it)->as<SceneGameField>();
        if( nullptr != scene )
        {
            scene -> hideFood( idFood );
            scores += points;
            incScores += points;
            if( incScores > 200 )
            {
                incScores = 0;
                snake.increaseSpeed();
            }
            growScores += points;
            if( growScores > 300 )
            {
                growScores = 0;
                snake.grow();
            }
            std::stringstream ss;
            ss << scores;
            scene -> setScorePoints( ss.str() );
            snake.healing( health );
            scene -> setLiveScore( snake.getLivePoints(), Snake::LIVE_POINTS_MAX );
        }
    }

//    auto itD = std::find_if( refScenes().begin()
//                            , refScenes().end()
//                            , [](lcg::SceneBuilder* scene){
//              return(scene->getName() == SceneDebug::class_name()); } );
//    if( itD != refScenes().end() )
//    {
//        std::stringstream ss;
//        ss << "GameField::foodEaten: idFood = " << idFood << "; scores = " << scores << std::endl;
//        ss << "foods: " << foods.getFoods().size() << std::endl;
//        std::list< Food* >::const_iterator itFood = foods.getFoods().cbegin();
//        while( itFood != foods.getFoods().cend() )
//        {
//            const Food* food = *itFood;
//            if( food->as_const<Apple>() != nullptr )
//                ss << "apple: id = " << food->id() << "; active:" << (food->getActive()?"True":"False") << std::endl;
//            else if( food->as_const<Rabbit>() != nullptr )
//                ss << "rabbit: id = " << food->id() << "; active:" << (food->getActive()?"True":"False") << std::endl;
//            ++itFood;
//        }
//        SceneDebug* scene = (*itD)->as<SceneDebug>();
//        if( nullptr != scene )
//            scene -> setConsole( ss.str() );
//    }

    return;
}
void GameField::foodEscaped( int idFood )
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        SceneGameField* scene = (*it)->as<SceneGameField>();
        if( nullptr != scene )
        {
            scene -> hideFood( idFood );
        }
    }
    return;
}
void GameField::foodChanged( int idFood, float dt )
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        SceneGameField* scene = (*it)->as<SceneGameField>();
        if( nullptr != scene )
        {
            scene -> changeFood( idFood, dt );
        }
    }
}
void GameField::logicFoods()
{
    auto it = std::find_if( refScenes().begin()
                            , refScenes().end()
                            , [](lcg::SceneBuilder* scene){
              return(scene->getName() == SceneGameField::class_name()); } );
    if( it != refScenes().end() )
    {
        SceneGameField* scene = (*it)->as<SceneGameField>();
        if( nullptr != scene )
            scene -> setFoods( foods );
    }
}
// scenes
bool GameField::onSceneShow( int index )
{
    if( static_cast<std::size_t>(index) < getScenes().size()
        && getScenes()[index]->getName() == SceneGameOver::class_name()
        && !gameOver() )
        return( false );
    return( true );
}
// actions
void GameField::initActions( lcg::UserInput* input )
{
    action_MoveUp.bind( this );
    action_MoveUp.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(0x57 /*W key*/)}) );
    action_MoveUp.setAltKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_UP)}) );
    action_MoveUp.setCallback( &handlerMoveUp );
    action_MoveUp.setActive( true );

    action_MoveDown.bind( this );
    action_MoveDown.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(0x53 /*S key*/)}) );
    action_MoveDown.setAltKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_DOWN)}) );
    action_MoveDown.setCallback( &handlerMoveDown );
    action_MoveDown.setActive( true );

    action_MoveLeft.bind( this );
    action_MoveLeft.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(0x41 /*A key*/)}) );
    action_MoveLeft.setAltKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_LEFT)}) );
    action_MoveLeft.setCallback( &handlerMoveLeft );
    action_MoveLeft.setActive( true );

    action_MoveRight.bind( this );
    action_MoveRight.setKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(0x44 /*D key*/)}) );
    action_MoveRight.setAltKeyboardShortcut( lcg::KeyboardShortcut({lcg::VKey(VK_RIGHT)}) );
    action_MoveRight.setCallback( &handlerMoveRight );
    action_MoveRight.setActive( true );

    if( nullptr != input )
    {
        input->attach( &action_MoveUp);
        input->attach( &action_MoveDown );
        input->attach( &action_MoveLeft );
        input->attach( &action_MoveRight );
    }
    snakeDirectionChanged( snake.getDirection() );
    return;
}
void GameField::moveUpSnake()
{
    snake.setDirection( Snake::moveUp );
    return;
}
void GameField::moveDownSnake()
{
    snake.setDirection( Snake::moveDown );
    return;
}
void GameField::moveLeftSnake()
{
    snake.setDirection( Snake::moveLeft );
    return;
}
void GameField::moveRightSnake()
{
    snake.setDirection( Snake::moveRight );
    return;
}
GameField::~GameField()
{
}
