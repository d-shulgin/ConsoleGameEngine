#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "scene_builder.h"
//#include "../input/user_input.h"

namespace lcg
{
    class UserInput;

    class Level
    {
    public:
        Level();
        virtual ~Level();

        void init( lcg::UserInput* );
        void process( float );

    protected:
        virtual void onInit( lcg::UserInput* ){}
        virtual void onLogic( float ){}
        virtual void onProcess( float ){}

    public:
        virtual std::string getName() const = 0;

    private: // active
        bool active = false;

    public:
        bool getActive() const { return( active ); }

    private: // chioce
        bool worksToActivate = false;
        bool worksToDeactivate = false;

        void processActivate( float );

    public:
        void activate();
        void deactivate();
        bool getWorksToActivate() const { return( worksToActivate ); }
        bool getWorksToDeactivate() const { return( worksToDeactivate ); }

    protected:
        virtual bool worksActivate() const { return( false ); }
        virtual void onActivate(){}
        virtual void onDeactivate(){}
        virtual void onActivated(){}
        virtual void onDeactivated(){}
        virtual void onProcessActivate( float ){}

    private: // scenes
        std::vector< SceneBuilder* > _scenes;
        int showScene = 0;

    public:
        Level& attach( SceneBuilder* );
        const std::vector< SceneBuilder* >& getScenes() const { return( _scenes ); }
        const lcg::SceneBuilder* getScene();

    protected:
        std::vector< SceneBuilder* >& refScenes(){ return( _scenes ); }
        void beginScene();
        virtual bool onSceneShow( int ){ return( true ); }
    };
}

#endif // LEVEL_H
