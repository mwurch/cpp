#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
    int a;
    int b;
}Data;

class Serializer
{
    private:

        Serializer();
        Serializer(Serializer const & src);
        ~Serializer();
        Serializer &operator=(Serializer const & src);

    public:

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif