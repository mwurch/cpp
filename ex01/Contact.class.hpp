#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

typedef enum
{
	FIRST,
	LAST,
	NICK,
	NUMBER,
	SECRET
} info;

class Contact  
{
	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	secret;
		std::string	phoneNumber;

	public:

		Contact(std::string f, std::string l, std::string nbr, std::string n, std::string s);
		~Contact();
		std::string	getFirstName( void ) const;
		std::string getLastName( void ) const;
		std::string getNickName( void ) const;
		std::string getPhoneNumber( void ) const;
		std::string getSecret( void ) const;
		std::string getString( info type) const;
		
};

#endif