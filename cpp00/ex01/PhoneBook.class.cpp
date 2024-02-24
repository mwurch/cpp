#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(int a1) : contact_count(a1)
{
	std::cout << "Welcome to my crappy awesome Phonebook" << std::endl;
}

PhoneBook::~PhoneBook( void )
{
}

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

void			PhoneBook::add_front(Contact & newContact)
{	
	int count = getContactCount();

	for (int i = 6; i >= 0; i--)
	{
		if (i > count - 1)
			continue;
		this->contactList[i + 1] = this->contactList[i]; 
	}
	this->contactList[0]= newContact;
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

	if (secret.empty() || firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty())
	{
		std::cout << "Please fill all the contacts with information" << std::endl;
		return ;
	}
	
	Contact newContact(firstName, lastName, phoneNumber, nickName, secret);
	add_front(newContact);
	if (contact_count != 8)
		increase_contact_count();
}

void	PhoneBook::search()
{
	int 		index;;
	int			user_input_int;
	std::string userInput;

	if (getContactCount() == 0)
	{
		std::cout << "The Phonebook is empty! Please use 'ADD' to add a Contact to this Phonebook" << std::endl;
		return ;
	}
	for (index = 0; index < getContactCount(); index++)
	{
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << index + 1;
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contactList[index].getString(FIRST);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contactList[index].getString(LAST);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contactList[index].getString(NICK);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contactList[index].getString(NUMBER);
		std::cout << " | ";
		std::cout << std::endl;
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
	std::cout << "--------------------------" << std::endl;
	std::cout << "First Name: " << contactList[i - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << contactList[i - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << contactList[i - 1].getNickName() << std::endl;
	std::cout << "Phonenumber: " << contactList[i - 1].getPhoneNumber() << std::endl;
	std::cout << "Secret: " << contactList[i - 1].getSecret() << std::endl;
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