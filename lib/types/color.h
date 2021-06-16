#ifndef COLOR_H
#define COLOR_H

#include <windows.h>

namespace lcg
{
    enum class ColorID
    {
        black = 0
        , dark_gray    = FOREGROUND_INTENSITY
        , gray         = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
        , white        = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
        , red          = FOREGROUND_RED
        , green        = FOREGROUND_GREEN
        , blue         = FOREGROUND_BLUE
        , yellow       = FOREGROUND_RED | FOREGROUND_GREEN
        , pink         = FOREGROUND_RED | FOREGROUND_BLUE
        , sky          = FOREGROUND_GREEN | FOREGROUND_BLUE
        , light_red    = FOREGROUND_RED | FOREGROUND_INTENSITY
        , light_green  = FOREGROUND_GREEN | FOREGROUND_INTENSITY
        , light_blue   = FOREGROUND_BLUE | FOREGROUND_INTENSITY
        , light_yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
        , light_pink   = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY
        , light_sky    = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
    };
}

#endif // COLOR_H
