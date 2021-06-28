#ifndef EXCEPTION_ENGINE_H
#define EXCEPTION_ENGINE_H

#include <string>
#include <exception>
#include <stdio.h>

namespace lcg
{
    class Error
    {
    public:
        enum Code
        {
            none
            , _invalid_ref_ScreenBuffer
            , _invalid_handle_ScreenBuffer
            , _failure_activate_ScreenBuffer
            , _failure_resize_ScreenBuffer
            , _invalid_handle_StdOutputDevide
            , _limit_rendering_scenes
            , _action_already_exists
            , _invalid_frame_animation
            , _invalid_ptr_level
            , _child_not_found
        };

    public:
        explicit Error( Code value )
            : _id( value )
        {}

        std::string to_string() const
        {
            switch( id() )
            {
            case _invalid_ref_ScreenBuffer      : return( std::string("invalid screen buffer reference") ); break;
            case _invalid_handle_ScreenBuffer   : return( std::string("invalid screen buffer handle") ); break;
            case _failure_activate_ScreenBuffer : return( std::string("unsuccessful attempt to make the screen buffer active") ); break;
            case _failure_resize_ScreenBuffer   : return( std::string("unsuccessful attempt to resize the screen buffer") ); break;
            case _invalid_handle_StdOutputDevide: return( std::string("invalid handle to the specified standard device (standard output device)") ); break;
            case _limit_rendering_scenes        : return( std::string("the limit of the possibility of simultaneous rendering of scenes has been reached") ); break;
            case _action_already_exists         : return( std::string("action already exists") ); break;
            case _invalid_frame_animation       : return( std::string("invalid animation frame index") ); break;
            case _invalid_ptr_level             : return( std::string("invalid value of a pointer to a level object") ); break;
            case _child_not_found               : return( std::string("child not found in group") ); break;
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
    class ExceptionEngine final : public std::exception
    {
        static const short int SIZE = 256;
        char  _desc[SIZE] = {0};
        Error _error;

    public:
        explicit ExceptionEngine( Error::Code code ) throw()
            : _error( code )
        {
            ::snprintf( _desc, SIZE, "%s", error().to_string().c_str() );
        }

        const Error& error() const throw() { return( _error ); }
        virtual const char* what() const throw() override { return( _desc ); }
    };
}

#endif // EXCEPTION_ENGINE_H
