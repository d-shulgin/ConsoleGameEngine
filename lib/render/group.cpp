#include "group.h"
#include <iostream>
#include <algorithm>
#include "../utils/exception_engine.h"

namespace lcg
{
    Group::Group( const std::string& name )
        : View( name )
    {
        std::cout << "con... Group(" << getName() << ")" << std::endl;
    }
    void Group::onPositionChanged( const Position& p )
    {
        for( auto child: refChildren() )
            if( nullptr != child )
                child -> setGlobalPosition( getGlobalPosition() + p );
        return;
    }
    void Group::onGlobalPositionChanged( const Position& p )
    {
        for( auto child: refChildren() )
            if( nullptr != child )
                child -> setGlobalPosition( getPosition() + p );
        return;
    }
    void Group::removeChildren()
    {
        for( int i = 0; i < children.size(); ++i )
            if( nullptr != children[i] )
                delete children[i];
        children.clear();
        return;
    }
    const View* Group::getChild( int index ) const
    {
        if( index < getChildren().size() )
            return( getChildren().at( index ) );
        throw( ExceptionEngine(Error::_child_not_found) );
        return( nullptr );
    }
    const View* Group::getChild( const std::string& name ) const
    {
        auto it = std::find_if( getChildren().begin()
                                , getChildren().end()
                                , [&name](View* item)->bool{ return( item->getName() == name ); } );
        if( it != getChildren().end() )
            return( *it );
        throw( ExceptionEngine(Error::_child_not_found) );
        return( nullptr );
    }
    void Group::addChild( View* const child )
    {
        children.push_back( child );
        child -> setGlobalPosition( getGlobalPosition() + getPosition() );
        return;
    }
    void Group::render( ScreenBuffer& obj, RenderFnPtr fn ) const
    {
        if( getVisible() )
        {
            for( auto child: getChildren() )
                if( nullptr != child )
                    child -> render( obj, fn );
        }
        return;
    }
    Group::~Group()
    {
        removeChildren();
        std::cout << "des... Group(" << getName() << ")" << std::endl;
    }


}
