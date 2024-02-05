#include <iostream>
#include "Contact.class.hpp"


Contact::Contact(std::string f, std::string l, std::string nbr, std::string n, std::string s)
: firstName(f), lastName(l), nickName(n), secret(s), phoneNumber(nbr)
{
    std::cout << "Contact OBJ is created" << std::endl;
}

Contact::~Contact()
{
    std::cout << "Contact OBJ is deleted" << std::endl;
}

std::string Contact::getFirstName( void ) const
{
    return (this->firstName);
}

std::string Contact::getLastName( void ) const
{
    return (this->lastName);
}

std::string Contact::getNickName( void ) const
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber( void ) const
{
    return (this->phoneNumber);
}

std::string Contact::getSecret( void ) const
{
    return (this->secret);
}

std::string Contact::getString(info type) const
{
    std::string ret;

    switch (type) {

        case FIRST:
            ret = this->firstName;
            break ;
        case LAST:
            ret = this->lastName;
            break ;
        case NICK:
            ret = this->nickName;
            break ;
        case NUMBER:
            ret = this->phoneNumber;
            break ;
        case SECRET:
            ret = this->secret;
            break ; 
        default:
            ret = "Error";
    }
    if (ret.size() > 10)
    {
        while (ret.size() > 10)
            ret.pop_back();
        ret[9] = '.';
    }
    return (ret);
}