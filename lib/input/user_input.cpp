#include "user_input.h"
#include <algorithm>

namespace lcg
{
    UserInput::UserInput()
    {
    }
    void UserInput::postProcess()
    {
        for( Action* action: _actions )
        {
            if( action->getActive() && action->getKeyboardShortcut().pressed() && !action->getProcessed() )
                action->process();
            else if( action->getActive() && action->getKeyboardShortcut().released() && action->getProcessed() )
                action->process();
        }
    }
    UserInput&UserInput::attach( Action* action )
    {
        if( nullptr != action )
        {
            auto it = std::find_if( _actions.begin()
                                    , _actions.end()
                                    , [&action]( Action* item )->bool{
                      if( action->getLevel() == nullptr && item->getLevel() == nullptr )
                          return( action->getName() == item->getName() );
                      else if( action->getLevel() != nullptr && item->getLevel() != nullptr )
                          return( action->getLevel()->getName() == item->getLevel()->getName()
                                  && action->getName() == item->getName() );
                      return(false); } );
            if( it != _actions.end() )
            {
                /// @todo: throw
            }
            else
                _actions.push_back( action );
        }
        return( *this );
    }
    UserInput::~UserInput()
    {
    }
}
