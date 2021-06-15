#include "vkey.h"
#include <windows.h>

namespace lcg
{
    VKey::VKey( int id )
        : _id( id )
    {
    }
    bool VKey::pressed() const
    {
        return( id() > 0 && GetKeyState(id())&0x8000 );
    }
    bool VKey::released() const
    {
        return( !pressed() );
    }
    VKey::~VKey()
    {
    }
}
