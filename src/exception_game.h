#ifndef EXCEPTION_GAME_H
#define EXCEPTION_GAME_H

#include <string>
#include <exception>
#include <stdio.h>

namespace snake
{
    class Error
    {
    public:
        enum Code
        {
            none
            , _tips_not_found
        };

    public:
        explicit Error( Code value )
            : _id( value )
        {}

        std::string to_string() const
        {
            switch( id() )
            {
            case _tips_not_found : return( std::string("tip not found") ); break;
            default:
                break;
            }
            return( std::string("") );
        }

    private:
        Code _id = none;

    public:
        Code id() const throw() { return( _id ); }
    };
    class Exception final : public std::exception
    {
        static const short int SIZE = 256;
        char  _desc[SIZE] = {0};
        Error _error;

    public:
        explicit Exception ( Error::Code code ) throw()
            : _error( code )
        {
            ::snprintf( _desc, SIZE, "%s", error().to_string().c_str() );
        }

        const Error& error() const throw() { return( _error ); }
        virtual const char* what() const throw() override { return( _desc ); }
    };
}

#endif // EXCEPTION_GAME_H
