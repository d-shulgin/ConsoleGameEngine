#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <vector>
#include "lib/engine.h"
#include "../characters/package.h"
#include "../actions/action_snake_move_up.h"
#include "../actions/action_snake_move_down.h"
#include "../actions/action_snake_move_left.h"
#include "../actions/action_snake_move_right.h"


class GameField final : public lcg::Level
{
public:
    GameField();
    virtual ~GameField();

protected:
    virtual void onInit( lcg::UserInput* ) override;
    virtual void onLogic( float ) override;

public: // name
    static std::string class_name() { return( "GameField" ); }
    virtual std::string getName() const override { return( class_name() ); }


protected: // choice
    virtual void onActivate() override;
    virtual void onDeactivate() override;


public: // prepare draw
    void prepareDraw();


private: // game
    bool _started = false;
    bool _gameOver = false;

    void logicGameOver();

public:
    bool started() const { return( _started ); }
    bool gameOver() const { return( _gameOver ); }


private: // field
    const int FIELD_MAXWIDTH = 16;
    const int FIELD_MAXHEIGHT = 14;


private: // scores
    int scores = 0;
    int incScores = 0;
    int growScores = 0;

private: // snake
    Snake snake;

    class Handler_SnakeEvents final : public Snake::Callback
    {
        GameField* obj = nullptr;
        std::function< void (GameField&, const lcg::Position&) > fnPosChanged;
        std::function< void (GameField&, Snake::MoveDirection) > fnDirChanged;
        std::function< void (GameField&) > fnShowChanged;
        std::function< void (GameField&) > fnLivesOver;
        std::function< void (GameField&) > fnDeathAnimationStarted;

    public:
        explicit Handler_SnakeEvents( GameField* ptr = nullptr )
            : obj( ptr )
        {}

        virtual void onPositionChanged( const lcg::Position& position ) override
        {
            if( nullptr != obj && fnPosChanged )
                fnPosChanged( *obj, position );
        }
        void eventPositionChanged( std::function< void (GameField&, const lcg::Position&) > fn )
        {
            fnPosChanged = fn;
        }

        virtual void onDirectionChanged( Snake::MoveDirection direction ) override
        {
            if( nullptr != obj && fnDirChanged )
                fnDirChanged( *obj, direction );
        }
        void eventDirectionChanged( std::function< void (GameField&, Snake::MoveDirection) > fn )
        {
            fnDirChanged = fn;
        }

        virtual void onLivesOver() override
        {
            if( nullptr != obj && fnLivesOver )
                fnLivesOver( *obj );
        }
        void eventLivesOver( std::function< void (GameField&) > fn )
        {
            fnLivesOver = fn;
        }

        virtual void onDeathAnimationStarted() override
        {
            if( nullptr != obj && fnDeathAnimationStarted )
                fnDeathAnimationStarted( *obj );
        }
        void eventDeathAnimationStarted( std::function< void (GameField&) > fn )
        {
            fnDeathAnimationStarted = fn;
        }

        virtual void onShowChanged() override
        {
            if( nullptr != obj && fnShowChanged )
                fnShowChanged( *obj );
        }
        void eventShowChanged( std::function< void (GameField&) > fn )
        {
            fnShowChanged = fn;
        }
    } handlerSnakeEvents;
    void snakeShowChanged();
    void snakePositionChanged( const lcg::Position& );
    void snakeDirectionChanged( Snake::MoveDirection );
    void snakeDie();
    void logicSnake();


private: // foods
    Foods foods;

    class Handler_FoodsEvents final : public Foods::Callback
    {
        GameField* obj = nullptr;
        std::function< void (GameField&) > fnFoodAdded;
        std::function< void (GameField&, int, int, int) > fnFoodEaten;
        std::function< void (GameField&, int) > fnFoodEscaped;
        std::function< void (GameField&, int, float) > fnFoodChanged;

    public:
        explicit Handler_FoodsEvents( GameField* ptr = nullptr )
            : obj( ptr )
        {}

        virtual void onFoodAdded() override
        {
            if( nullptr != obj && fnFoodAdded )
                fnFoodAdded( *obj );
        }
        void eventFoodAdded( std::function< void (GameField&) > fn )
        {
            fnFoodAdded = fn;
        }

        virtual void onFoodEaten( int idFood, int scores, int HP ) override
        {
            if( nullptr != obj && fnFoodEaten )
                fnFoodEaten( *obj, idFood, scores, HP );
        }
        void eventFoodEaten( std::function< void (GameField&, int, int, int) > fn )
        {
            fnFoodEaten = fn;
        }

        virtual void onFoodEscaped( int idFood ) override
        {
            if( nullptr != obj && fnFoodEscaped )
                fnFoodEscaped( *obj, idFood );
        }
        void eventFoodEscaped( std::function< void (GameField&, int) > fn )
        {
            fnFoodEscaped = fn;
        }

        virtual void onFoodChanged( int idFood, float dt ) override
        {
            if( nullptr != obj && fnFoodChanged )
                fnFoodChanged( *obj, idFood, dt );
        }
        void eventFoodChanged( std::function< void (GameField&, int, float) > fn )
        {
            fnFoodChanged = fn;
        }
    } handlerFoodsEvents;

    void foodAdded();
    void foodEaten( int, int, int );
    void foodEscaped( int );
    void foodChanged( int, float );
    void logicFoods();

protected: // scenes
    virtual bool onSceneShow( int ) override;

private: // actions
    Action_SnakeMoveUp    action_MoveUp;
    Action_SnakeMoveDown  action_MoveDown;
    Action_SnakeMoveLeft  action_MoveLeft;
    Action_SnakeMoveRight action_MoveRight;

    class Handler_MoveUp final : public lcg::Action::Callback
    {
        std::function<void (GameField&)> fnPress;
        GameField* obj = nullptr;

    public:
        Handler_MoveUp()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onPressed() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override
        {
        }
        void setFnPress( GameField* o, std::function<void(GameField&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerMoveUp;
    class Handler_MoveDown final : public lcg::Action::Callback
    {
        std::function<void (GameField&)> fnPress;
        GameField* obj = nullptr;

    public:
        Handler_MoveDown()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onPressed() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override
        {
        }
        void setFnPress( GameField* o, std::function<void(GameField&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerMoveDown;
    class Handler_MoveLeft final : public lcg::Action::Callback
    {
        std::function<void (GameField&)> fnPress;
        GameField* obj = nullptr;

    public:
        Handler_MoveLeft()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onPressed() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override
        {
        }
        void setFnPress( GameField* o, std::function<void(GameField&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerMoveLeft;
    class Handler_MoveRight final : public lcg::Action::Callback
    {
        std::function<void (GameField&)> fnPress;
        GameField* obj = nullptr;

    public:
        Handler_MoveRight()
            : lcg::Action::Callback()
        {}
        virtual void onPress() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onPressed() override
        {
            if( nullptr != obj )
                fnPress( *obj );
        }
        virtual void onRelease() override
        {
        }
        void setFnPress( GameField* o, std::function<void(GameField&)> fn )
        {
            obj = o;
            fnPress = fn;
        }
    } handlerMoveRight;

    void initActions( lcg::UserInput* );
    void moveUpSnake();
    void moveDownSnake();
    void moveLeftSnake();
    void moveRightSnake();
};

#endif // GAME_FIELD_H
