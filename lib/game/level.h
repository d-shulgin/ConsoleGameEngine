#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <functional>
#include "scene_builder.h"

namespace lcg
{
    class Level
    {
    public:
        Level();
        virtual ~Level();

        void process( float );

    protected:
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


        /// @deprecated:
#ifdef DEPRECATED
        void update( float );

    private: // scenes
        std::vector< const lcg::Scene* > scenes;
        int showScene = 0;

    public:
        void beginScene();
        void nextScene();
        const lcg::Scene* getScene() const;
        Level& attachScene( const lcg::Scene* const );
#endif // DEPRECATED
    };
}

#endif // LEVEL_H
