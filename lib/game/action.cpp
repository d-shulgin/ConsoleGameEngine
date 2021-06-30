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
    bool Action::getPressed() const
    {
        return( getKeyboardShortcut().getPressed() || getAltKeyboardShortcut().getPressed() );
    }
    bool Action::getReleased() const
    {
        return( getKeyboardShortcut().getReleased() && getAltKeyboardShortcut().getReleased() );
    }
    void Action::bind( const lcg::Level* level )
    {
        this -> level = level;
    }
    void Action::process()
    {
        if( getActive() )
        {
            if( nullptr != handler )
            {
                if( getPressed() )
                {
                    if( !getProcessed() )
                    {
                        processed = true;
                        handler -> onPress();
                    }
                    else
                        handler -> onPressed();
                }
                else
                {
                    if( getProcessed() )
                    {
                        processed = false;
                        handler -> onRelease();
                    }
                }
            }
        }

//        processed = getPressed();
//        if( !onProcess() )
//        {
//            if( nullptr != handler )
//            {
//                if( processed )
//                    handler -> onPress();
//                else
//                    handler -> onRelease();
//            }
//        }


//            if( action->getActive() && action->getPressed() && !action->getProcessed() )
//                action->process();
//            else if( action->getActive() && action->getReleased() && action->getProcessed() )
//                action->process();
        return;
    }
    Action::~Action()
    {
    }
}
