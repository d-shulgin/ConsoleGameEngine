#ifndef SCENE_START_H
#define SCENE_START_H

#include "../../lib/engine.h"

class SceneStart final : public lcg::SceneBuilder
{
    lcg::Scene _scene;

public:
    SceneStart();
    virtual ~SceneStart();

    virtual const lcg::Scene* scene() const override { return( &_scene ); }

public: // name
    static std::string class_name() { return("SceneStart"); }
    virtual std::string getName() const override { return( class_name() ); }

protected: // initialize
    virtual void onInit() override;

protected: // create & load scene
    virtual void onBuild() override;

private:
    class Resources
    {
        static const unsigned int INVITATION_IMAGES = 44;
    private:
        lcg::Image _logo;
        lcg::Image _invitation[INVITATION_IMAGES];

    public:
        void load();
        const lcg::Image* logo() const { return( &_logo ); }
        const lcg::Image* invitation( unsigned int i ) const
        {
            if( i < INVITATION_IMAGES )
                return( &_invitation[i] );
            return( nullptr );
        }
    } rsc;

private: // logotype
    lcg::Sprite* logotype = nullptr;

    void loadLogotype();

private: // invitation
    const float INVITATION_TIME__START = 5.0f; // sec
    const float INVITATION_TIME__RESTART = 15.0f; // sec
    lcg::Sprite* invitation = nullptr;
    lcg::Animation invitationAnim;
    float timeInvitation = INVITATION_TIME__START;

    void loadInvitation();
    void processInvitation( float );

public:
    void hideInvitation();
    void showInvitation();

protected: // process animation of scene
    virtual void onProcess( float ) override;
};

#endif // SCENE_START_H
