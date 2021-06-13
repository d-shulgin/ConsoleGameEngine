#ifndef GROUP_H
#define GROUP_H

#include <typeinfo>
#include <vector>
#include "view.h"

namespace lcg
{
    class Group : public View
    {
    public:
        explicit Group( const std::string& = "" );
        virtual ~Group();

    protected: // change position
        virtual void onPositionChanged( const Position& ) override;
        virtual void onGlobalPositionChanged( const Position& ) override;

    private: // children
        std::vector< View* > children;

        void removeChildren();
        std::vector< View* >& refChildren() { return( children ); }

    public:
        const std::vector< View* >& getChildren() const { return( children ); }
        const View* getChild( int ) const;
        const View* getChild( const std::string& ) const;
        void addChild( View* const );

    public: // render
        virtual void render( ScreenBuffer&, RenderFnPtr ) const override;
    };
}

#endif // GROUP_H
