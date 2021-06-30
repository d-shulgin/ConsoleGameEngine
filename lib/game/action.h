#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "level.h"
#include "../input/keyboard_shortcut.h"

namespace lcg
{
    class Action
    {
    public:
        Action();
        virtual ~Action();

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

    public:
        virtual std::string getName() const = 0;
        virtual std::string getDescription() const { return(""); }

    private: // active
        bool active = false;

    public:
        bool getActive() const;
        void setActive( bool flg ){ active = flg; }

    private: // keyboard shortcut
        KeyboardShortcut kbShortcut;

    public:
        const KeyboardShortcut& getKeyboardShortcut() const { return( kbShortcut ); }
        void setKeyboardShortcut( const KeyboardShortcut& v ){ kbShortcut = v; }

    private: // alternate keyboard shortcut
        KeyboardShortcut akbShortcut;

    public:
        const KeyboardShortcut& getAltKeyboardShortcut() const { return( akbShortcut ); }
        void setAltKeyboardShortcut( const KeyboardShortcut& v ){ akbShortcut = v; }

    public: // check state
        bool getPressed() const;
        bool getReleased() const;

    private: // level
        const Level* level = nullptr;

    public:
        void bind( const Level* );
        const Level* getLevel() const { return( level ); }

    private: // process
        bool processed = false;

    public:
        bool getProcessed() const { return( processed ); }
        void process();

    protected:
        virtual bool onProcess(){ return( false ); }

    public: // callback
        class Callback
        {
        public:
            Callback(){}

            virtual void onPress() = 0;
            virtual void onRelease() = 0;
            virtual void onPressed(){}
        };

    private:
        Callback* handler = nullptr;

    public:
        void setCallback( Callback* h ){ handler = h; }
    };
}

#endif // ACTION_H
