#include "user_input.h"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "../utils/exception_engine.h"

namespace lcg
{
    UserInput::UserInput()
    {
    }
    void UserInput::postProcess()
    {
        for( Action* action: _actions )
        {
            if( action->getActive() && action->getPressed() && !action->getProcessed() )
                action->process();
            else if( action->getActive() && action->getReleased() && action->getProcessed() )
                action->process();
        }
        return;
    }
    UserInput& UserInput::attach( Action* action )
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
                throw( ExceptionEngine(Error::_action_already_exists) );
                return( *this );
            }
            else
                _actions.push_back( action );
        }
        return( *this );
    }
    std::string UserInput::getVKeyName( int code )
    {
        switch( code )
        {
        case VK_LBUTTON:    return( "Mouse LeftBtn" );
        case VK_RBUTTON:    return( "Mouse RightBtn" );
        case VK_BACK:       return( "Backspace" );
        case VK_TAB:        return( "Tab" );
        case VK_CLEAR:      return( "Clear" );
        case VK_RETURN:     return( "Enter" );
        case VK_SHIFT:      return( "Shift" );
        case VK_CONTROL:    return( "Ctrl" );
        case VK_MENU:       return( "Alt" );
        case VK_PAUSE:      return( "Pause" );
        case VK_CAPITAL:    return( "CapsLock" );
        case VK_ESCAPE:     return( "Esc" );
        case VK_SPACE:      return( "Space" );
        case VK_PRIOR:      return( "PageUp" );
        case VK_NEXT:       return( "PageDown" );
        case VK_END:        return( "End" );
        case VK_HOME:       return( "Home" );
        case VK_LEFT:       return( "Left" );
        case VK_UP:         return( "Up" );
        case VK_RIGHT:      return( "Right" );
        case VK_DOWN:       return( "Down" );
        case VK_SELECT:     return( "Select" );
        case VK_PRINT:      return( "Print" );
        case VK_EXECUTE:    return( "Execute" );
        case VK_SNAPSHOT:   return( "PrintScr" );
        case VK_INSERT:     return( "Ins" );
        case VK_DELETE:     return( "Del" );
        case VK_HELP:       return( "Help" );
        case 0x30:          return( "0" );
        case 0x31:          return( "1" );
        case 0x32:          return( "2" );
        case 0x33:          return( "3" );
        case 0x34:          return( "4" );
        case 0x35:          return( "5" );
        case 0x36:          return( "6" );
        case 0x37:          return( "7" );
        case 0x38:          return( "8" );
        case 0x39:          return( "9" );
        case 0x41:          return( "A" );
        case 0x42:          return( "B" );
        case 0x43:          return( "C" );
        case 0x44:          return( "D" );
        case 0x45:          return( "E" );
        case 0x46:          return( "F" );
        case 0x47:          return( "G" );
        case 0x48:          return( "H" );
        case 0x49:          return( "I" );
        case 0x4A:          return( "J" );
        case 0x4B:          return( "K" );
        case 0x4C:          return( "L" );
        case 0x4D:          return( "M" );
        case 0x4E:          return( "N" );
        case 0x4F:          return( "O" );
        case 0x50:          return( "P" );
        case 0x51:          return( "Q" );
        case 0x52:          return( "R" );
        case 0x53:          return( "S" );
        case 0x54:          return( "T" );
        case 0x55:          return( "U" );
        case 0x56:          return( "V" );
        case 0x57:          return( "W" );
        case 0x58:          return( "X" );
        case 0x59:          return( "Y" );
        case 0x5A:          return( "Z" );
        case VK_LWIN:       return( "LeftWin" );
        case VK_RWIN:       return( "RightWin" );
        case VK_APPS:       return( "App" );
        case VK_SLEEP:      return( "Sleep" );
        case VK_NUMPAD0:    return( "Num0" );
        case VK_NUMPAD1:    return( "Num1" );
        case VK_NUMPAD2:    return( "Num2" );
        case VK_NUMPAD3:    return( "Num3" );
        case VK_NUMPAD4:    return( "Num4" );
        case VK_NUMPAD5:    return( "Num5" );
        case VK_NUMPAD6:    return( "Num6" );
        case VK_NUMPAD7:    return( "Num7" );
        case VK_NUMPAD8:    return( "Num8" );
        case VK_NUMPAD9:    return( "Num9" );
        case VK_MULTIPLY:   return( "Num*" );
        case VK_ADD:        return( "Num+" );
        case VK_SEPARATOR:  return( "Separator" );
        case VK_SUBTRACT:   return( "Num-" );
        case VK_DECIMAL:    return( "Num," );
        case VK_DIVIDE:     return( "Num/" );
        case VK_F1:         return( "F1" );
        case VK_F2:         return( "F2" );
        case VK_F3:         return( "F3" );
        case VK_F4:         return( "F4" );
        case VK_F5:         return( "F5" );
        case VK_F6:         return( "F6" );
        case VK_F7:         return( "F7" );
        case VK_F8:         return( "F8" );
        case VK_F9:         return( "F9" );
        case VK_F10:        return( "F10" );
        case VK_F11:        return( "F11" );
        case VK_F12:        return( "F12" );
        case VK_F13:        return( "F13" );
        case VK_F14:        return( "F14" );
        case VK_F15:        return( "F15" );
        case VK_F16:        return( "F16" );
        case VK_F17:        return( "F17" );
        case VK_F18:        return( "F18" );
        case VK_F19:        return( "F19" );
        case VK_F20:        return( "F20" );
        case VK_F21:        return( "F21" );
        case VK_F22:        return( "F22" );
        case VK_F23:        return( "F23" );
        case VK_F24:        return( "F24" );
        case VK_NUMLOCK:    return( "NumLock" );
        case VK_SCROLL:     return( "ScrollLock" );
        case VK_LSHIFT:     return( "LeftShift" );
        case VK_RSHIFT:     return( "RightShift" );
        case VK_LCONTROL:   return( "LeftCtrl" );
        case VK_RCONTROL:   return( "RightCtrl" );
        case VK_LMENU:      return( "LeftMenu" );
        case VK_RMENU:      return( "RightMenu" );
        default: break;
        }
        std::stringstream ss;
        ss << std::hex << code << std::dec;
        return( "Unknown: 0x" + ss.str() );
    }
    UserInput::~UserInput()
    {
    }
}
