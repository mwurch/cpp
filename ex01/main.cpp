#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main( void )
{
	PhoneBook myPhoneBook(0);
	std::string user_input;
   
	myPhoneBook.promptUser();
	user_input = myPhoneBook.get_user_input();
	while (user_input != "EXIT" && user_input != "exit")
	{
		if (user_input == "ADD" || user_input == "add")
			myPhoneBook.add();
		else if (user_input == "SEARCH" || user_input == "search")
			myPhoneBook.search();
		else
			std::cout << user_input << ": unknown command" << std::endl;
		myPhoneBook.promptUser();
		user_input = myPhoneBook.get_user_input();
	}
	return (0);
}