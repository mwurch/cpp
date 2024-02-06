#include <iostream>
#include "PhoneBook.class.hpp"
#include "linkedList.hpp"

PhoneBook::PhoneBook(int a1) : contact_count(a1)
{
	std::cout << "Welcome to my crappy awesome Phonebook" << std::endl;
	this->list = NULL;
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
	add_front(create_element(newContact));
	if (contact_count == 8)
	{
		pop_back();
		decrease_contact_count();
	}
	increase_contact_count();
}

void	PhoneBook::search()
{
	int 		index;;
	int			user_input_int;
	std::string userInput;
	list_element *curr = this->list;

	if (getContactCount() == 0)
	{
		std::cout << "The Phonebook is empty! Please use 'ADD' to add a Contact to this Phonebook" << std::endl;
		return ;
	}
	for (index = 1; index <= getContactCount(); index++)
	{
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << index;
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << curr->contact.getString(FIRST);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << curr->contact.getString(LAST);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << curr->contact.getString(NICK);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << curr->contact.getString(NUMBER);
		std::cout << " | ";
		std::cout << std::endl;
		curr = curr->next;
	}
	std::cout << "Please enter the index of the contact you wish to see more information on: ";
	std::getline(std::cin, userInput);
	user_input_int = get_data(userInput);
	if (user_input_int < 1 || user_input_int > this->contact_count)
	{
		std::cout << "Not a valid index!" << std::endl;
		return ;
	}
	displayContact(user_input_int);
}

void	PhoneBook::displayContact ( int i ) const
{
	list_element	*curr = this->list;
	int				x = 0;
	while (curr->next != NULL && ++x != i)
		curr = curr->next;
	std::cout << "--------------------------" << std::endl;
	std::cout << "First Name: " << curr->contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << curr->contact.getLastName() << std::endl;
	std::cout << "Nickname: " << curr->contact.getNickName() << std::endl;
	std::cout << "Phonenumber: " << curr->contact.getPhoneNumber() << std::endl;
	std::cout << "Secret: " << curr->contact.getSecret() << std::endl;
	std::cout << "--------------------------" << std::endl;
}

std::string	PhoneBook::get_user_input( void ) const
{
	return (this->user_input);
}


int PhoneBook::get_data(std::string str)
{
	long	ret = 0;
	int		i = 0;
	
	while (str[i] && std::isdigit(str[i]))
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (-2);
	if (std::numeric_limits<int>::max() < ret)
		return (-2);
	return (static_cast<int>(ret));
}