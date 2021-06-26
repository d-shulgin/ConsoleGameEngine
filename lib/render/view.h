#ifndef VIEW_H
#define VIEW_H

#include <typeinfo>
#include <string>
#include <functional>
#include "../types/position.h"
#include "../surface/screen_buffer.h"

namespace lcg
{
    class View
    {
    public:
        explicit View( const std::string& = "" );
        virtual ~View();

        template< typename T >
        T* as()
        {
            if( typeid(T).before(typeid(*this)) || typeid(T) == typeid(*this) )
            {
                return( dynamic_cast<T*>(this) );
            }
            return( nullptr );
        }
        template< typename T >
        const T* as_const() const
        {
            if( typeid(T).before(typeid(*this)) || typeid(T) == typeid(*this) )
            {
                return( dynamic_cast<const T*>(this) );
            }
            return( nullptr );
        }

    private: // name
        std::string name;

    public:
        const std::string& getName() const { return( name ); }
        void setName( const std::string& namae ){ name = namae; }

    private: // visibility
        bool visible = true;

    public:
        bool getVisible() const { return( visible ); }
        void setVisible( bool v ){ visible = v; }

    private: // global transformation
        Position globalPosition;

    public:
        const Position& getGlobalPosition() const { return( globalPosition ); }
        void setGlobalPosition( const Position& p );

    protected:
        virtual void onGlobalPositionChanged( const Position& ){}

    private: // trnasformation
        Position position;

    public:
        const Position& getPosition() const { return( position ); }
        void setPosition( const Position& p );
        void setPosition( short x, short y );

    protected:
        virtual void onPositionChanged( const Position& ){}

    public: // render
        typedef std::function<void(ScreenBuffer&, const CHAR_INFO*, COORD, COORD)> RenderFnPtr;
        virtual void render( ScreenBuffer&, RenderFnPtr ) const {}
    };
}

#endif // VIEW_H
