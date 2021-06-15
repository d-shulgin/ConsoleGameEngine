#include "action.h"

namespace lcg
{
    Action::Action()
    {
    }
    bool Action::getActive() const
    {
        if( getLevel() != nullptr )
            return( getLevel()->getActive() && active );
        return( active );
    }
    void Action::bind( const lcg::Level* level )
    {
        this -> level = level;
    }
    void Action::process()
    {
        processed = getKeyboardShortcut().pressed();
        if( !onProcess() )
        {
            if( nullptr != handler )
            {
                if( processed )
                    handler -> onPress();
                else
                    handler -> onRelease();
            }
        }
        return;
    }
    Action::~Action()
    {
    }
}
