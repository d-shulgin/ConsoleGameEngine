#include "scene_start.h"

SceneStart::SceneStart()
    : lcg::SceneBuilder()
{
}
SceneStart::~SceneStart()
{
}

void SceneStart::onInit()
{
    timeInvitation = INVITATION_TIME__START;
}
void SceneStart::onBuild()
{
    rsc.load();

    lcg::Group* root = nullptr;
    _scene.setRoot( root = new lcg::Group("root") );
    if( nullptr != root )
    {
        root -> setPosition( 0, 0 );
        root -> addChild( logotype = new lcg::Sprite("logotype") );
        root -> addChild( invitation = new lcg::Sprite("invitation") );
        loadLogotype();
        loadInvitation();
    }
    return;
}
void SceneStart::loadLogotype()
{
    if( nullptr != logotype )
    {
        logotype -> setImage( rsc.logo() );
        logotype -> setPosition( 0, 0 );
    }
    return;
}
void SceneStart::loadInvitation()
{
    if( nullptr != invitation )
    {
        invitationAnim.addImage( rsc.invitation(0) );
        invitationAnim.addImage( rsc.invitation(1) );
        invitationAnim.addImage( rsc.invitation(2) );
        invitationAnim.addImage( rsc.invitation(3) );
        invitationAnim.addImage( rsc.invitation(4) );
        invitationAnim.addImage( rsc.invitation(5) );
        invitationAnim.addImage( rsc.invitation(6) );
        invitationAnim.addImage( rsc.invitation(7) );
        invitationAnim.addImage( rsc.invitation(8) );
        invitationAnim.addImage( rsc.invitation(9) );
        invitationAnim.addImage( rsc.invitation(10) );
        invitationAnim.addImage( rsc.invitation(11) );
        invitationAnim.addImage( rsc.invitation(12) );
        invitationAnim.addImage( rsc.invitation(13) );
        invitationAnim.addImage( rsc.invitation(14) );
        invitationAnim.addImage( rsc.invitation(15) );
        invitationAnim.addImage( rsc.invitation(16) );
        invitationAnim.addImage( rsc.invitation(17) );
        invitationAnim.addImage( rsc.invitation(18) );
        invitationAnim.addImage( rsc.invitation(19) );
        invitationAnim.addImage( rsc.invitation(20) );
        invitationAnim.addImage( rsc.invitation(21) );
        invitationAnim.addImage( rsc.invitation(22) );
        invitationAnim.addImage( rsc.invitation(23) );
        invitationAnim.addImage( rsc.invitation(24) );
        invitationAnim.addImage( rsc.invitation(25) );
        invitationAnim.addImage( rsc.invitation(26) );
        invitationAnim.addImage( rsc.invitation(27) );
        invitationAnim.addImage( rsc.invitation(28) );
        invitationAnim.addImage( rsc.invitation(29) );
        invitationAnim.addImage( rsc.invitation(30) );
        invitationAnim.addImage( rsc.invitation(31) );
        invitationAnim.addImage( rsc.invitation(32) );
        invitationAnim.addImage( rsc.invitation(33) );
        invitationAnim.addImage( rsc.invitation(34) );
        invitationAnim.addImage( rsc.invitation(35) );
        invitationAnim.addImage( rsc.invitation(36) );
        invitationAnim.addImage( rsc.invitation(37) );
        invitationAnim.addImage( rsc.invitation(38) );
        invitationAnim.addImage( rsc.invitation(39) );
        invitationAnim.addImage( rsc.invitation(40) );
        invitationAnim.addImage( rsc.invitation(41) );
        invitationAnim.addImage( rsc.invitation(42) );
        invitationAnim.addImage( rsc.invitation(43) );
        invitationAnim.addImage( rsc.invitation(0) );
        invitation -> setPosition( 44, 43 );
        invitation -> setImage( invitationAnim.getImage() );
    }
}
void SceneStart::processInvitation( float dt )
{
    if( nullptr != invitation && invitation->getVisible() )
    {
        if( timeInvitation > 0.0f )
            timeInvitation -= dt;
        else if( !invitationAnim.getActive() )
            invitationAnim.start();
        else
        {
            invitationAnim.process( dt );
            invitation->setImage( invitationAnim.getImage() );
            if( !invitationAnim.getActive() )
                timeInvitation = INVITATION_TIME__RESTART;
        }
    }
    return;
}
void SceneStart::hideInvitation()
{
    if( nullptr != invitation )
        invitation->setVisible( false );
    return;
}
void SceneStart::showInvitation()
{
    if( nullptr != invitation )
    {
        invitationAnim.reset();
        invitation->setVisible( true );
        invitation->setImage( invitationAnim.getImage() );
        timeInvitation = INVITATION_TIME__START;
    }
    return;
}
void SceneStart::onProcess( float dt )
{
    processInvitation( dt );
    return;
}


void SceneStart::Resources::load()
{
    // logo       |
    {
        _logo = lcg::Image( 120, 50 );

        /*
        |           SSSSSSSSSSSSSSSSSS        ||        SSSSSSSSSSSSSSSSSS           |o
        |         SSSSSSSSSSSSSSSSSSSSSSSS    ||    SSSSSSSSSSSSSSSSSSSSSSSS         |o
        |       SSSSSSSSSSSSSSSSSSSSSSSSSSSS  ||  SSSSSSSSSSSSSSSSSSSSSSSSSSSS       |o
        |     SSS$SSSSSS         SSSSSSSSSSSS || SSSSSSSSSSSS         SSSSSS$SSS     |o
        |     SS$S$SSSS              SSSSSSSSS||SSSSSSSSS              SSSS$S$SS     |o
        |    SS$SS$SSS                SSSSSSSS||SSSSSSSS                SSS$SS$SS    |o
        |   SS$SSSS$SSS               SSSSSSSS||SSSSSSSS               SSS$SSSS$SS   |o
        |  SS$SSSS$SSSS               SSSSSSSS||SSSSSSSS               SSSS$SSSS$SS  |o
        |  SSS$SS$SSSS               SSSSSSSSS||SSSSSSSSS               SSSS$SS$SSS  |o
        | (O)SS$SS(O)               SSSSSSSSS || SSSSSSSSS               (O)SS$SS(O) |o
        |  SSS$S$SSS               SSSSSSSSS  ||  SSSSSSSSS               SSS$S$SSS  |o
        |   SSSSSSS               SSSSSSSSS   ||   SSSSSSSSS               SSSSSSS   |o
        |  SSSSSSS               SSSSSSSSS    ||    SSSSSSSSS               SSSSSSS  |o
        |   SSSS               SSSSSSSSSS     ||     SSSSSSSSSS               SSSS   |o
        |    $               SSSSSSSSSSS      ||      SSSSSSSSSSS               $    |o
        |   $              SSSSSSSSSSS        ||        SSSSSSSSSSS              $   |o
        |   $            SSSSSSSSSSS          ||          SSSSSSSSSSS            $   |o
        |  $           SSSSSSSSSSS            ||            SSSSSSSSSSS           $  |o
        | $ $        SSSSSSSSSSS              ||              SSSSSSSSSSS        $ $ |o
        |          SSSSSSSSSSS                ||                SSSSSSSSSSS          |o
        |        SSSSSSSSSSS                  ||                  SSSSSSSSSSS        |o
        |      SSSSSSSSSSS                    ||                    SSSSSSSSSSS      |o
        |    SSSSSSSSSSS                      ||                      SSSSSSSSSSS    |o
        |  SSSSSSSSSSS                        ||                        SSSSSSSSSSS  |o
        | SSSSSSSSSSS                         ||                         SSSSSSSSSSS |o
        |SSSSSSSSSSS                          ||                          SSSSSSSSSSS|o
        |SSSSSSSSSSS                          ||                          SSSSSSSSSSS|o
        | SSSSSSSSSSS                         ||                         SSSSSSSSSSS |o
        |  SSSSSSSSSSS               SSSSSSSS || SSSSSSSS               SSSSSSSSSSS  |o
        |     SSSSSSSSSSS          SSSSSSS    ||    SSSSSSS          SSSSSSSSSSS     |o
        |         SSSSSSSSSSSSSSSSSSSSS       ||       SSSSSSSSSSSSSSSSSSSSS         |o
        |             SSSSSSSSSSSSSS          ||          SSSSSSSSSSSSSS             |o
        |                 SSSSSSS             ||             SSSSSSS                 |o

        |           GGGGGGGGGGGGGGGGGG        ||        GGGGGGGGGGGGGGGGGG           |o
        |         GGGGGGGGGGGGGGGGGGGGGGGG    ||    GGGGGGGGGGGGGGGGGGGGGGGG         |o
        |       GGGGGGGGGGGGGGGGGGGGGGGGGGGG  ||  GGGGGGGGGGGGGGGGGGGGGGGGGGGG       |o
        |     GGGGGGGGGG         GGGGGGGGGGGG || GGGGGGGGGGGG         GGGGGGgGGG     |o
        |     GGGGGGGGG              GGGGGGGGG||GGGGGGGGG              GGGGgGgGG     |o
        |    GGGGGGGGG                GGGGGGGG||GGGGGGGG                GGGgGGgGG    |o
        |   GGGGGGGGGGG               GGGGGGGG||GGGGGGGG               GGGgGGGGgGG   |o
        |  GGGGGGGGGGGG               GGGGGGGG||GGGGGGGG               GGGGgGGGGgGG  |o
        |  GGGGGGGGGGG               GGGGGGGGG||GGGGGGGGG               GGGGgGGgGGG  |o
        | YYYGGGGGYYY               GGGGGGGGG || GGGGGGGGG               YYYGGgGGYYY |o
        |  GGGGGGGGG               GGGGGGGGG  ||  GGGGGGGGG               GGGgGgGGG  |o
        |   GGGGGGG               GGGGGGGGG   ||   GGGGGGGGG               GGGGGGG   |o
        |  GGGGGGG               GGGGGGGGG    ||    GGGGGGGGG               GGGGGGG  |o
        |   GGGG               GGGGGGGGGG     ||     GGGGGGGGGG               GGGG   |o
        |    R               GGGGGGGGGGG      ||      GGGGGGGGGGG               R    |o
        |   R              GGGGGGGGGGG        ||        GGGGGGGGGGG              R   |o
        |   r            GGGGGGGGGGG          ||          GGGGGGGGGGG            r   |o
        |  r           GGGGGGGGGGG            ||            GGGGGGGGGGG           r  |o
        | r r        GGGGGGGGGGG              ||              GGGGGGGGGGG        r r |o
        |          GGGGGGGGGGG                ||                GGGGGGGGGGG          |o
        |        GGGGGGGGGGG                  ||                  GGGGGGGGGGG        |o
        |      GGGGGGGGGGG                    ||                    GGGGGGGGGGG      |o
        |    GGGGGGGGGGG                      ||                      GGGGGGGGGGG    |o
        |  GGGGGGGGGGG                        ||                        GGGGGGGGGGG  |o
        | GGGGGGGGGGG                         ||                         GGGGGGGGGGG |o
        |GGGGGGGGGGG                          ||                          GGGGGGGGGGG|o
        |GGGGGGGGGGG                          ||                          GGGGGGGGGGG|o
        | GGGGGGGGGGG                         ||                         GGGGGGGGGGG |o
        |  GGGGGGGGGGG               GGGGGGGG || GGGGGGGG               GGGGGGGGGGG  |o
        |     GGGGGGGGGGG          GGGGGGG    ||    GGGGGGG          GGGGGGGGGGG     |o
        |         GGGGGGGGGGGGGGGGGGGGG       ||       GGGGGGGGGGGGGGGGGGGGG         |o
        |             GGGGGGGGGGGGGG          ||          GGGGGGGGGGGGGG             |o
        |                 GGGGGGG             ||             GGGGGGG                 |o
        */
        _logo.beginSymbols()
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("       |        SSSSSSSSSSSSSSSSSS           |                                                                          ")
                .addSymbols("       |    SSSSSSSSSSSSSSSSSSSSSSSS         |                                                                          ")
                .addSymbols("       |  SSSSSSSSSSSSSSSSSSSSSSSSSSSS       |                                                                          ")
                .addSymbols("       | SSSSSSSSSSSS         SSSSSS$SSS     |                                                                          ")
                .addSymbols("       |SSSSSSSSS              SSSS$S$SS     |                                                                          ")
                .addSymbols("       |SSSSSSSS                SSS$SS$SS    |                                                                          ")
                .addSymbols("       |SSSSSSSS               SSS$SSSS$SS   |                                                                          ")
                .addSymbols("       |SSSSSSSS               SSSS$SSSS$SS  |                                                                          ")
                .addSymbols("       |SSSSSSSSS               SSSS$SS$SSS  |                                                                          ")
                .addSymbols("       | SSSSSSSSS               (O)SS$SS(O) |                                                                          ")
                .addSymbols("       |  SSSSSSSSS               SSS$S$SSS  |                                                                          ")
                .addSymbols("       |   SSSSSSSSS               SSSSSSS   |                                      KK                                  ")
                .addSymbols("       |    SSSSSSSSS               SSSSSSS  |                                     kKK                                  ")
                .addSymbols("       |     SSSSSSSSSS               SSSS   |                                     kKK                                  ")
                .addSymbols("       |      SSSSSSSSSSS               $    |                                     kKK                                  ")
                .addSymbols("       |        SSSSSSSSSSS              $   |                                     KKk                                  ")
                .addSymbols("       |          SSSSSSSSSSS            $   |                                     KKk                                  ")
                .addSymbols("       |            SSSSSSSSSSS           $  |                                    kKKk                                  ")
                .addSymbols("       |              SSSSSSSSSSS        $ $ |                                    kKK                 eEEEe             ")
                .addSymbols("       |                SSSSSSSSSSS          |                         aAAA       kKK      kKK       EEEEEE             ")
                .addSymbols("       |                  SSSSSSSSSSS        | NN                     AAAAAa      kKk     kKKK      EEEe EE             ")
                .addSymbols("       |                    SSSSSSSSSSS      | NN    nNNNn           AAAa aAA     kKk    KKKKk     EEe  eEE             ")
                .addSymbols("       |                      SSSSSSSSSSS    | NN   nNNNNNn         AAA    AA     KKk   KKKk      eEE   EEe             ")
                .addSymbols("       |                        SSSSSSSSSSS  | NN   NNn NNN        aAA     AA     KKk kKKKk       EEe eEEe              ")
                .addSymbols("       |                         SSSSSSSSSSS | NN  NNn  nNNn      aAAa    aAA     KK kKKKk       eEE eEEe               ")
                .addSymbols("       |                          SSSSSSSSSSS|nNN nNn    NNn      AAa     AAA     KKkKKKk        EEeeEEe                ")
                .addSymbols("       |                          SSSSSSSSSSS|nNN NN     NNn     aAA     aAAA     KKKKKKk        EEEEE                  ")
                .addSymbols("       |                         SSSSSSSSSSS |nNnnNn     NNN     AAa    aAAAA    kKKkkKKKk       EEEe     eE            ")
                .addSymbols("       | SSSSSSSS               SSSSSSSSSSS  |nNnNN      NNN     AA    aAAaAA    KKk  kKKKk      EE       EE            ")
                .addSymbols("       |    SSSSSSS          SSSSSSSSSSS     |NNnNn      nNNn    AA   aAAa AAa   KK    kKKKk     EEe    eEEe            ")
                .addSymbols("       |       SSSSSSSSSSSSSSSSSSSSS         |NNNN       nNNNNN  AAa aAAa  AAA   KK     kKKKk    EEEe eEEEe             ")
                .addSymbols("       |          SSSSSSSSSSSSSS             |NNNn        nNNNn  AAAAAAa   aAAA  KK      kKKKKK  eEEEEEEEe              ")
                .addSymbols("       |             SSSSSSS                 |NNn                 AAAAa     AAa  KK       kKKKk   eEEEEe                ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ")
                .addSymbols("                                                                                                                        ");
        _logo.beginColors()
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                GGGGGGGGGGGGGGGGGG                                                                                      ")
                .addColors ("            GGGGGGGGGGGGGGGGGGGGGGGG                                                                                    ")
                .addColors ("          GGGGGGGGGGGGGGGGGGGGGGGGGGGG                                                                                  ")
                .addColors ("         GGGGGGGGGGGG         GGGGGGgGGG                                                                                ")
                .addColors ("        GGGGGGGGG              GGGGgGgGG                                                                                ")
                .addColors ("        GGGGGGGG                GGGgGGgGG                                                                               ")
                .addColors ("        GGGGGGGG               GGGgGGGGgGG                                                                              ")
                .addColors ("        GGGGGGGG               GGGGgGGGGgGG                                                                             ")
                .addColors ("        GGGGGGGGG               GGGGgGGgGGG                                                                             ")
                .addColors ("         GGGGGGGGG               YYYGGgGGYYY                                                                            ")
                .addColors ("          GGGGGGGGG               GGGgGgGGG                                                                             ")
                .addColors ("           GGGGGGGGG               GGGGGGG                                          YY                                  ")
                .addColors ("            GGGGGGGGG               GGGGGGG                                        yYY                                  ")
                .addColors ("             GGGGGGGGGG               GGGG                                         yYY                                  ")
                .addColors ("              GGGGGGGGGGG               R                                          yYY                                  ")
                .addColors ("                GGGGGGGGGGG              R                                         YYy                                  ")
                .addColors ("                  GGGGGGGGGGG            r                                         YYy                                  ")
                .addColors ("                    GGGGGGGGGGG           r                                       yYYy                                  ")
                .addColors ("                      GGGGGGGGGGG        r r                                      yYY                 yYYYy             ")
                .addColors ("                        GGGGGGGGGGG                                    yYYY       yYY      yYY       YYYYYY             ")
                .addColors ("                          GGGGGGGGGGG          YY                     YYYYYy      yYy     yYYY      YYYy YY             ")
                .addColors ("                            GGGGGGGGGGG        YY    yYYYy           YYYy yYY     yYy    YYYYy     YYy  yYY             ")
                .addColors ("                              GGGGGGGGGGG      YY   yYYYYYy         YYY    YY     YYy   YYYy      yYY   YYy             ")
                .addColors ("                                GGGGGGGGGGG    YY   YYy YYY        yYY     YY     YYy yYYYy       YYy yYYy              ")
                .addColors ("                                 GGGGGGGGGGG   YY  YYy  yYYy      yYYy    yYY     YY yYYYy       yYY yYYy               ")
                .addColors ("                                  GGGGGGGGGGG yYY yYy    YYy      YYy     YYY     YYyYYYy        YYyyYYy                ")
                .addColors ("                                  GGGGGGGGGGG yYY YY     YYy     yYY     yYYY     YYYYYYy        YYYYY                  ")
                .addColors ("                                 GGGGGGGGGGG  yYyyYy     YYY     YYy    yYYYY    yYYyyYYYy       YYYy     yY            ")
                .addColors ("         GGGGGGGG               GGGGGGGGGGG   yYyYY      YYY     YY    yYYyYY    YYy  yYYYy      YY       YY            ")
                .addColors ("            GGGGGGG          GGGGGGGGGGG      YYyYy      yYYy    YY   yYYy YYy   YY    yYYYy     YYy    yYYy            ")
                .addColors ("               GGGGGGGGGGGGGGGGGGGGG          YYYY       yYYYYY  YYy yYYy  YYY   YY     yYYYy    YYYy yYYYy             ")
                .addColors ("                  GGGGGGGGGGGGGG              YYYy        yYYYy  YYYYYYy   yYYY  YY      yYYYYY  yYYYYYYYy              ")
                .addColors ("                     GGGGGGG                  YYy                 YYYYy     YYy  YY       yYYYy   yYYYYy                ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ")
                .addColors ("                                                                                                                        ");
    }
    // invitation |
    {
        short width = static_cast<short>(std::string("PRESS (ENTER) KEY TO CONTINUE...").size());
        _invitation[0] = lcg::Image( width, 5 );
        _invitation[0].beginSymbols().beginColors() // #000
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[1] = lcg::Image( width, 5 );
        _invitation[1].beginSymbols().beginColors() // #001
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" RESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[2] = lcg::Image( width, 5 );
        _invitation[2].beginSymbols().beginColors() // #002
                .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" R                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  ESS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[3] = lcg::Image( width, 5 );
        _invitation[3].beginSymbols().beginColors() // #003
                .addSymbols("PR                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("   SS (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[4] = lcg::Image( width, 5 );
        _invitation[4].beginSymbols().beginColors() // #004
                .addSymbols(" RE                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P  S                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("    S (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[5] = lcg::Image( width, 5 );
        _invitation[5].beginSymbols().beginColors() // #005
                .addSymbols("  ES                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" R  S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P     (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[6] = lcg::Image( width, 5 );
        _invitation[6].beginSymbols().beginColors() // #006
                .addSymbols("   SS                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" R    (ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[7] = lcg::Image( width, 5 );
        _invitation[7].beginSymbols().beginColors() // #007
                .addSymbols("    S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("   S  (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  E    ENTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" R                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P                               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[8] = lcg::Image( width, 5 );
        _invitation[8].beginSymbols().beginColors() // #008
                .addSymbols("      (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("    S  E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("   S    NTER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PR                              ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[9] = lcg::Image( width, 5 );
        _invitation[9].beginSymbols().beginColors() // #009
                .addSymbols("      (E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("        N                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("    S    TER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P  S                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" RE                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[10] = lcg::Image( width, 5 );
        _invitation[10].beginSymbols().beginColors() // #010
                .addSymbols("       EN                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("      (  T                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P         ER) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" R  S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  ES                            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[11] = lcg::Image( width, 5 );
        _invitation[11].beginSymbols().beginColors() // #011
                .addSymbols("        NT                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P      E  E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" R    (    R) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  E                             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("   SS                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[12] = lcg::Image( width, 5 );
        _invitation[12].beginSymbols().beginColors() // #012
                .addSymbols("         TE                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PR      N  R                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  E    E    ) KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("   S  (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("    S                           ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[13] = lcg::Image( width, 5 );
        _invitation[13].beginSymbols().beginColors() // #013
                .addSymbols("          ER                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols(" RE      T  )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("P  S    N     KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("    S  E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("      (                         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[14] = lcg::Image( width, 5 );
        _invitation[14].beginSymbols().beginColors() // #014
                .addSymbols("           R)                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("  ES      E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PR  S    T    KEY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("        N                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("      (E                        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[15] = lcg::Image( width, 5 );
        _invitation[15].beginSymbols().beginColors() // #015
                .addSymbols("            )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("   SS      R  K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRE       E    EY TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("      (  T                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("       EN                       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[16] = lcg::Image( width, 5 );
        _invitation[16].beginSymbols().beginColors() // #016
                .addSymbols("              K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("    S       )  E                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRES  (    R    Y TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("       E  E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("        NT                      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[17] = lcg::Image( width, 5 );
        _invitation[17].beginSymbols().beginColors() // #017
                .addSymbols("              KE                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("      (         Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS  E    )     TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("        N  R                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("         TE                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[18] = lcg::Image( width, 5 );
        _invitation[18].beginSymbols().beginColors() // #018
                .addSymbols("               EY               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("      (E      K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS   N         TO CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("         T  )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("          ER                    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[19] = lcg::Image( width, 5 );
        _invitation[19].beginSymbols().beginColors() // #019
                .addSymbols("                Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("       EN      E  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (  T    K    O CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("          E                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("           R)                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[20] = lcg::Image( width, 5 );
        _invitation[20].beginSymbols().beginColors() // #020
                .addSymbols("                  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("        NT      Y  O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (E  E    E     CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("           R  K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("            )                   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[21] = lcg::Image( width, 5 );
        _invitation[21].beginSymbols().beginColors() // #021
                .addSymbols("                  TO            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("         TE                     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (EN  R    Y    CONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("            )  E                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("              K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[22] = lcg::Image( width, 5 );
        _invitation[22].beginSymbols().beginColors() // #022
                .addSymbols("                   O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("          ER      T  C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENT  )         ONTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("              KE                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[23] = lcg::Image( width, 5 );
        _invitation[23].beginSymbols().beginColors() // #023
                .addSymbols("                     C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("           R)      O  O         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTE       T    NTINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("              K                 ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("               EY               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[24] = lcg::Image( width, 5 );
        _invitation[24].beginSymbols().beginColors() // #024
                .addSymbols("                     CO         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("            )          N        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER  K    O    TINUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("               E  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                Y               ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[25] = lcg::Image( width, 5 );
        _invitation[25].beginSymbols().beginColors() // #025
                .addSymbols("                      ON        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("              K      C  T       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER)  E         INUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                Y  O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                  T             ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[26] = lcg::Image( width, 5 );
        _invitation[26].beginSymbols().beginColors() // #026
                .addSymbols("                       NT       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("              KE      O  I      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER)   Y    C    NUE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                  TO            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[27] = lcg::Image( width, 5 );
        _invitation[27].beginSymbols().beginColors() // #027
                .addSymbols("                        TI      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("               EY      N  N     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) K       O    UE...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                  T  C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                   O            ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[28] = lcg::Image( width, 5 );
        _invitation[28].beginSymbols().beginColors() // #028
                .addSymbols("                         IN     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                Y       T  U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KE  T    N    E...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                   O  O         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                     C          ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[29] = lcg::Image( width, 5 );
        _invitation[29].beginSymbols().beginColors() // #029
                .addSymbols("                          NU    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                  T      I  E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY  O    T    ...").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                       N        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                     CO         ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[30] = lcg::Image( width, 5 );
        _invitation[30].beginSymbols().beginColors() // #030
                .addSymbols("                           UE   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                  TO      N  .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY        I    ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                     C  T       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                      ON        ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[31] = lcg::Image( width, 5 );
        _invitation[31].beginSymbols().beginColors() // #031
                .addSymbols("                            E.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                   O       U  . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY T  C    N    .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                      O  I      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                       NT       ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[32] = lcg::Image( width, 5 );
        _invitation[32].beginSymbols().beginColors() // #032
                .addSymbols("                             .. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                     C      E  .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO  O    U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                       N  N     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                        TI      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[33] = lcg::Image( width, 5 );
        _invitation[33].beginSymbols().beginColors() // #033
                .addSymbols("                              ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                     CO      .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO   N    E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                        T  U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                         IN     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[34] = lcg::Image( width, 5 );
        _invitation[34].beginSymbols().beginColors() // #034
                .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                      ON      . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO C  T    .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                         I  E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                          NU    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[35] = lcg::Image( width, 5 );
        _invitation[35].beginSymbols().beginColors() // #035
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                       NT      .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CO  I    . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                          N  .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                           UE   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[36] = lcg::Image( width, 5 );
        _invitation[36].beginSymbols().beginColors() // #036
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                        TI      ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CON  N    .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                           U  . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                            E.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[37] = lcg::Image( width, 5 );
        _invitation[37].beginSymbols().beginColors() // #037
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                         IN     ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONT  U    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                            E  .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                             .. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[38] = lcg::Image( width, 5 );
        _invitation[38].beginSymbols().beginColors() // #038
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                          NU    ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTI  E   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                             .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                              ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[39] = lcg::Image( width, 5 );
        _invitation[39].beginSymbols().beginColors() // #039
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                           UE   ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTIN  .  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                              . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[40] = lcg::Image( width, 5 );
        _invitation[40].beginSymbols().beginColors() // #040
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                            E.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTINU  . ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[41] = lcg::Image( width, 5 );
        _invitation[41].beginSymbols().beginColors() // #041
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                             .. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTINUE  .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[42] = lcg::Image( width, 5 );
        _invitation[42].beginSymbols().beginColors() // #042
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                              ..").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTINUE.  ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
        _invitation[43] = lcg::Image( width, 5 );
        _invitation[43].beginSymbols().beginColors() // #043
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                               .").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("PRESS (ENTER) KEY TO CONTINUE.. ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW")
                .addSymbols("                                ").addColors("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    }
    return;
}
