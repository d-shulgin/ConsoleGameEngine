#ifndef VKEY_H
#define VKEY_H

namespace lcg
{
    class VKey final
    {
        int _id = 0;

    public:
        explicit VKey( int = 0 );
        ~VKey();

        int id() const { return( _id ); }
        bool pressed() const;
        bool released() const;
    };
}

#endif // VKEY_H
