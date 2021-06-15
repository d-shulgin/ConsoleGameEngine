#include "sprite.h"

namespace lcg
{
    Sprite::Sprite( const std::string& name )
        : View( name )
    {
    }
    void Sprite::render( ScreenBuffer& obj, View::RenderFnPtr fn ) const
    {
        if( getVisible() )
        {
            if( nullptr != image && image->getBuffer().size() > 0 )
            {
                Position pos = getGlobalPosition() + getPosition();
                fn( obj
                    , &image->getBuffer()[0]
                        , {image->getWidth(), image->getHeight()}
                , pos.asCOORD() );
            }
        }
        return;
    }
    Sprite::~Sprite()
    {
    }
}
