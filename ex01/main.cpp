#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main( void )
{
    PhoneBook myPhoneBook;

    myPhoneBook.add();
    myPhoneBook.add();
    myPhoneBook.search();
    myPhoneBook.clearContactList();
    return (0);
}