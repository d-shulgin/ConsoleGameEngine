#ifndef SPRITE_H
#define SPRITE_H

#include "view.h"
#include "../types/image.h"

namespace lcg
{
    enum class SpriteAlign
    {
        alignTop             = 0x00000001
        , alignBottom        = 0x00000002
        , alignVCenter       = 0x00000003
        , alignLeft          = 0x00000004
        , alignRight         = 0x00000008
        , alignHCenter       = 0x0000000C
        // ------------------------------
        , alignLeftTop       = 0x00000005
        , alignLeftBottom    = 0x00000006
        , alignLeftVCenter   = 0x00000007
        , alignRightTop      = 0x00000009
        , alignRightBottom   = 0x0000000A
        , alignRightVCenter  = 0x0000000B
        , alignHCenterTop    = 0x0000000D
        , alignHCenterBottom = 0x0000000E
        , alignHVCentered    = 0x0000000F
    };

    class Sprite final : public View
    {
    public:
        explicit Sprite( const std::string& = "" );
        ~Sprite();

    private: // align
        SpriteAlign align = SpriteAlign::alignLeftTop;

    public:
        const SpriteAlign& getAlign() const { return( align ); }
        void setAlign( const SpriteAlign& a ){ align = a; }

    private: // image
        const Image* image = nullptr;

    public:
        void setImage( const Image* img ){ image = img; }

    public: // render
        virtual void render( ScreenBuffer&, RenderFnPtr ) const override;
    };
}

#endif // SPRITE_H
