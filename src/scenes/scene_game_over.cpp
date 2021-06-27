#include "scene_game_over.h"

SceneGameOver::SceneGameOver()
    : lcg::SceneBuilder()
{
}
SceneGameOver::~SceneGameOver()
{
}

void SceneGameOver::onBuild()
{
    rsc.load();

    lcg::Group* root = nullptr;

    _scene.setRoot( root = new lcg::Group("root") );
    if( nullptr != root )
    {
        root -> setPosition( 20, 20 );
        root -> addChild( background = new lcg::Sprite("background") );
        loadBackground();
    }
}
void SceneGameOver::loadBackground()
{
    if( nullptr != background )
    {
        background->setImage( rsc.background() );
        background->setPosition(0, 0);
    }
    return;
}


void SceneGameOver::Resources::load()
{
    _background = lcg::Image( 80, 12 );
    _background.beginSymbols().beginColors().beginBgColors()
            //           0         1         2         3         4         5         6         7
            //           01234567890123456789012345678901234567890123456789012345678901234567890123456789
            .addSymbols("================================================================================")
            .addSymbols("|                                                                              |")
            .addSymbols("|  @@@@@      @@  @@       @@ @@@@@@@          @@@   @       @ @@@@@@@ @@@@    |")
            .addSymbols("| @     @    @  @ @ @     @ @ @               @   @  @       @ @       @   @   |")
            .addSymbols("| @          @  @ @ @     @ @ @               @   @   @     @  @       @    @  |")
            .addSymbols("| @         @   @ @  @   @  @ @@@@@          @     @  @     @  @@@@@   @   @   |")
            .addSymbols("| @         @@@@@ @  @   @  @ @@@@@          @     @   @   @   @@@@@   @@@@    |")
            .addSymbols("| @     @  @    @ @   @ @   @ @               @   @    @   @   @       @   @   |")
            .addSymbols("| @    @@  @    @ @    @    @ @               @   @     @ @    @       @    @  |")
            .addSymbols("|  @@@@ @ @     @ @         @ @@@@@@@          @@@       @     @@@@@@@ @     @ |")
            .addSymbols("|                                                                              |")
            .addSymbols("================================================================================")

            .addColors("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRB")
            .addColors("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB")

            .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
            .addBgColors("b                                                                              b")
            .addBgColors("b  RRRRR      RR  RR       RR RRRRRRR          RRR   R       R RRRRRRR RRRR    b")
            .addBgColors("b R     R    R  R R R     R R R               R   R  R       R R       R   R   b")
            .addBgColors("b R          R  R R R     R R R               R   R   R     R  R       R    R  b")
            .addBgColors("b R         R   R R  R   R  R RRRRR          R     R  R     R  RRRRR   R   R   b")
            .addBgColors("b R         RRRRR R  R   R  R RRRRR          R     R   R   R   RRRRR   RRRR    b")
            .addBgColors("b R     R  R    R R   R R   R R               R   R    R   R   R       R   R   b")
            .addBgColors("b R    RR  R    R R    R    R R               R   R     R R    R       R    R  b")
            .addBgColors("b  RRRR R R     R R         R RRRRRRR          RRR       R     RRRRRRR R     R b")
            .addBgColors("b                                                                              b")
            .addBgColors("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
}
