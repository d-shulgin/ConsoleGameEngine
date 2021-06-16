#include "level.h"
#include <algorithm>
#include "../input/user_input.h"

namespace lcg
{
    Level::Level()
    {
    }
    void Level::init( lcg::UserInput* ui )
    {
        onInit( ui );
    }
    void Level::process( float dt )
    {
        processActivate( dt );
        if( getActive() )
        {
            for( auto scene: _scenes )
                if( nullptr != scene )
                    scene->process( dt );
            onProcess( dt );
        }
        return;
    }
    void Level::processActivate( float dt )
    {
        if( getWorksToActivate() || getWorksToDeactivate() )
        {
            if( worksActivate() )
                onProcessActivate( dt );
            else
            {
                if( getWorksToActivate() )
                {
                    active = true;
                    worksToActivate = false;
                    onActivated();
                }
                else if( getWorksToDeactivate() )
                {
                    active = false;
                    worksToDeactivate = false;
                    onDeactivated();
                }
            }
        }
        return;
    }
    void Level::activate()
    {
        if( getWorksToActivate() )
            return;
        if( getWorksToDeactivate() )
            onDeactivated();
        worksToActivate = true;
        onActivate();
        return;
    }
    void Level::deactivate()
    {
        if( getWorksToDeactivate() )
            return;
        if( getWorksToActivate() )
            onActivated();
        worksToDeactivate = true;
        onDeactivate();
        return;
    }
    Level& Level::attach( SceneBuilder* scene )
    {
        if( nullptr == scene )
            return( *this );
        auto it = std::find_if( _scenes.begin()
                                , _scenes.end()
                                ,[&scene](const SceneBuilder* i)->bool{ return(i->getName() == scene->getName()); } );
        if( it != _scenes.end() )
            *it = scene;
        else
            _scenes.push_back( scene );
        return( *this );
    }
    const SceneBuilder* Level::getScene()
    {
        if( showScene < static_cast<int>(getScenes().size()) )
        {
            int showId = showScene;
            showScene ++;
            return( getScenes()[showId] );
        }
        return( nullptr );
    }
    void Level::beginScene()
    {
        showScene = 0;
    }
    Level::~Level()
    {
    }
}
