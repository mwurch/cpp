#include "Serializer.hpp"

int main(void)
{
    Data data;
    Data* ptr;
    uintptr_t a;

    data.a=1;
    data.b=2;
    ptr = &data;

    a = Serializer::serialize(ptr);
    std::cout << a << std::endl;
    ptr = Serializer::deserialize(a);
    std::cout << ptr->a << " " << ptr->b << std::endl;
    


}