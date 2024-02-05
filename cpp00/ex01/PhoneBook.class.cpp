#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(int a1) : contact_count(a1)
{
	std::cout << "Welcome to my crappy awesome Phonebook" << std::endl;
};

PhoneBook::~PhoneBook( void )
{

};

int		PhoneBook::getContactCount( void ) const
{
	return (this->contact_count);
}


void	PhoneBook::increase_contact_count( void )
{
	this->contact_count++;
}

void	PhoneBook::decrease_contact_count( void )
{
	this->contact_count--;
}

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
	if (contact_count == 8)
	{
		this->contactList.pop_back();
		decrease_contact_count();
	}
	increase_contact_count();
}

void	PhoneBook::search()
{
	int 		index = 1;
	int			user_input_int;
	std::string userInput;

	if (this->contactList.empty())
	{
		std::cout << "The Phonebook is empty! Please use 'ADD' to add a Contact to this Phonebook" << std::endl;
		return ;
	}
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
	std::cout << "Please enter the index of the contact you wish to see more information on: ";
	std::getline(std::cin, userInput);
	try {
		user_input_int = std::stoi(userInput);
	} catch (const std::invalid_argument& err) {
		std::cerr << "Invalid argument" << std::endl;
		return ;
	} catch ( const std::out_of_range& err) {
		std::cerr << "Invalid argument" << std::endl;
		return ;
	}
	if (user_input_int < 1 || user_input_int > this->contact_count)
	{
		std::cout << "Not a valid index!" << std::endl;
		return ;
	}
	displayContact(user_input_int);
}

void	PhoneBook::clearContactList()
{
	this->contactList.clear();
}

void	PhoneBook::displayContact ( int i ) const
{
	int	x = 1;
	std::list<Contact>::const_iterator it;
	for (it = contactList.begin(); it != contactList.end() && x != i; it++)
		x++;
	
	std::cout << "--------------------------" << std::endl;
	std::cout << "First Name: " << it->getFirstName() << std::endl;
	std::cout << "Last Name: " << it->getLastName() << std::endl;
	std::cout << "Nickname: " << it->getNickName() << std::endl;
	std::cout << "Phonenumber: " << it->getPhoneNumber() << std::endl;
	std::cout << "Secret: " << it->getSecret() << std::endl;
	std::cout << "--------------------------" << std::endl;
}

std::string	PhoneBook::get_user_input( void ) const
{
	return (this->user_input);
}
