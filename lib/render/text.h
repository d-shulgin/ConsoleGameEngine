#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "view.h"
#include "../types/color.h"

namespace lcg
{
    class Text final : public View
    {
    public:
        explicit Text( const std::string& = "" );
        ~Text();

        void setData( const Position&, const std::string&, const ColorID&, const ColorID& );
        void setData( const Position&, const std::string&, const ColorID& );
        void setData( const Position&, const std::string& );
        void setData( const std::string& );

    private: // data of text
        std::string str;

    public:
        const std::string& getString() const { return( str ); }
        void setString( const std::string& v );

    private: // color
        ColorID color = ColorID::white;

    public:
        const ColorID& getColor() const { return( color ); }
        void setColor( const ColorID& c ){ color = c; }

    private: // background color
        ColorID bgColor = ColorID::black;

    public:
        const ColorID& getBackgroundColor() const { return( bgColor ); }
        void setBackgroundColor( const ColorID& c ){ bgColor = c; }

    private: // render
        CHAR_INFO* buffer = nullptr;
        COORD bufferSize = {0, 0};

    public:
        virtual void render( ScreenBuffer&, RenderFnPtr ) const override;
    };
}

#endif // TEXT_H
