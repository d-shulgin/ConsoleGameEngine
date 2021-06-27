#ifndef SCENE_GAME_FIELD_H
#define SCENE_GAME_FIELD_H

#include "../../lib/engine.h"
#include "../characters/snake.h"
#include "../characters/foods.h"

class SceneGameField final : public lcg::SceneBuilder
{
    lcg::Scene _scene;

public:
    SceneGameField();
    virtual ~SceneGameField();

    virtual const lcg::Scene* scene() const override { return( &_scene ); }

public: // name
    static std::string class_name() { return("SceneGameField"); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // create & load scene
    virtual void onBuild() override;

private:
    class Resources
    {
        static const int RABBIT_MAXFRAMES = 17;
    public:
        enum SnakeParts
        {
            snakeHead
            , snakeBody
            , snakePartsAmount
        };

    private:
        lcg::Image _background;
        lcg::Image _apple;
        lcg::Image _rabbit[RABBIT_MAXFRAMES];
        lcg::Image _think[RABBIT_MAXFRAMES];
        lcg::Image _snake[ snakePartsAmount ];

    public:
        void load();
        const lcg::Image* background() const { return( &_background ); }
        const lcg::Image* rabbit( int index ) const
        {
            if( index < RABBIT_MAXFRAMES )
                return( &_rabbit[index] );
            return( nullptr );
        }
        const lcg::Image* think( int index ) const
        {
            if( index < RABBIT_MAXFRAMES )
                return( &_think[index] );
            return( nullptr );
        }
        const lcg::Image* snake( SnakeParts part ) const
        {
            if( part < snakePartsAmount )
                return( &_snake[part] );
            return( nullptr );
        }
        const lcg::Image* apple() const { return( &_apple ); }
    } rsc;

private: // background
    lcg::Sprite* background = nullptr;

    void loadBackground();

private: // live indicator
    lcg::Text* indicatorLive = nullptr;

    void loadLiveScore();

public:
    void setLiveScore( int, int );

private: // scores indicator
    lcg::Text* indicatorScores = nullptr;

    void loadScorePoints();

public:
    void setScorePoints( const std::string& );

private: // snake
    lcg::Group* snakeGroup = nullptr;
    std::vector< lcg::Sprite* > chainLinks;

public:
    void setSnake( const Snake& );
    std::size_t getSnakeLength() const { return( chainLinks.size() ); }

private: // foods
    class AppleSprite
    {
        int _id = 0;
    public:
        explicit AppleSprite( int id = 0 )
            : _id( id )
        {}

        int id() const { return( _id ); }
        void build( int, lcg::Group*, const Resources& );
        void show( short int, short int );
        void hide();

    private:
        lcg::Sprite* apple = nullptr;
    };

    lcg::Group* applesGroup = nullptr;
    std::vector< AppleSprite > apples;

    void giveApple( const Apple* );

private: // rabbit
    class RabbitSprite
    {
        int _id = 0;
    public:
        explicit RabbitSprite( int id = 0 )
            : _id( id )
        {}

        int id() const { return( _id ); }
        void build( int, lcg::Group*, const Resources& );
        void show( short int, short int, float );
        void hide();

    private:
        lcg::Sprite* body  = nullptr;
        lcg::Sprite* think = nullptr;
        lcg::Animation bodyAnim;
        lcg::Animation thinkAnim;

    public:
        void setElapsedTime( float );
    };

    lcg::Group* rabbitsGroup = nullptr;
    std::vector< RabbitSprite > rabbits;

    void giveRabbit( const Rabbit* );

//public:
//    int giveRabbit( int, int, float );

public: // foods
    void setFoods( const Foods& );
    void changeFood( int, float );
    void hideFood( int );

protected: // process animation of scene
    bool active = true;
    virtual void onProcess( float ) override;

public:
    bool getActive() const { return( active ); }
    bool getPaused() const { return( !getActive() ); }
    void setPause( bool pause ){ active = !pause; }
    void restart();
};

#endif // SCENE_GAME_FIELD_H
