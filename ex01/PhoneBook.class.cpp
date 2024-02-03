#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Welcome to my crappy awesome Phonebook" << std::endl;
};

PhoneBook::~PhoneBook( void )
{

};


void	PhoneBook::promptUser()
{
	std::cout << "Please enter one of the following commands --> \"ADD\" \"SEARCH\" \"EXIT\": ";
	std::getline(std::cin, this->user_input);
}

void	PhoneBook::add()
{
	std::string firstName, lastName, nickName, secret, phoneNumber;

	std::cout << "Please enter First Name: ";
	std::getline(std::cin, firstName);

	std::cout << "Please enter Last Name: ";
	std::getline(std::cin, lastName);

	std::cout << "Please enter Nickname: ";
	std::getline(std::cin, nickName);

	std::cout << "Please enter Phonenumber: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Please enter Secret: ";
	std::getline(std::cin, secret);

	Contact newContact(firstName, lastName, phoneNumber, nickName, secret);
	this->contactList.push_front(newContact);
}

void	PhoneBook::search()
{
	int index = 1;

	for (const auto &contact : this->contactList)
	{
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << index++;
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contact.getString(FIRST);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contact.getString(LAST);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contact.getString(NICK);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contact.getString(NUMBER);
		std::cout << " | ";
		std::cout << std::endl;
	}
}

void	PhoneBook::clearContactList()
{
	this->contactList.clear();
}

void	PhoneBook::displayContact ( void ) const
{
	for (const auto &contact : this->contactList)
	{
        std::cout << "--------------------------" << std::endl;
		std::cout << "First Name: " << contact.getString(FIRST) << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickName() << std::endl;
        std::cout << "Phonenumber: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Secret: " << contact.getSecret() << std::endl;
        std::cout << "--------------------------" << std::endl;
	}
}


