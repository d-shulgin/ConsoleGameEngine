#include "keyboard_shortcut.h"
#include <algorithm>

namespace lcg
{
    KeyboardShortcut::KeyboardShortcut()
    {
    }
    KeyboardShortcut::KeyboardShortcut( const std::vector<VKey>& keys )
        : _keys( keys )
    {
    }
    KeyboardShortcut& KeyboardShortcut::attach( const VKey& vkey )
    {
        if( vkey.id() > 0 )
        {
            auto it = std::find_if( _keys.begin()
                                    , _keys.end()
                                    , [&vkey](VKey k)->bool{ return(k.id() == vkey.id()); } );
            if( it != _keys.end() )
                *it = vkey;
            else
                _keys.push_back( vkey );
        }
        return( *this );
    }
    bool KeyboardShortcut::pressed() const
    {
        if( getKeys().empty() )
            return( false );
        bool result = true;
        for( std::size_t i = 0; i < _keys.size() && result; ++i )
            result = result && _keys[i].pressed();
        return( result );
    }
    bool KeyboardShortcut::released() const
    {
        return( !pressed() );
    }
    KeyboardShortcut::~KeyboardShortcut()
    {
    }
}
