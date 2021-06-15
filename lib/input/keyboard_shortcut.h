#ifndef KEYBOARD_SHORTCUT_H
#define KEYBOARD_SHORTCUT_H

#include <vector>
#include "vkey.h"

namespace lcg
{
    class KeyboardShortcut final
    {
    public:
        KeyboardShortcut();
        explicit KeyboardShortcut( const std::vector<VKey>& );
        ~KeyboardShortcut();

    private:
        std::vector< VKey > _keys;

    public:
        KeyboardShortcut& attach( const VKey& );
        const std::vector< VKey >& getKeys() const { return( _keys ); }
        bool pressed() const;
        bool released() const;
    };
}

#endif // KEYBOARD_SHORTCUT_H
