#include <iostream>
#include <iomanip> 
#include <list>
#include "Contact.class.hpp"

class PhoneBook
{
	
	private:
	
	std::list <Contact>	contactList;
	std::string 		user_input;

	public:

	PhoneBook();
	~PhoneBook();

	void	promptUser();
	void	add();
	void	search();
	void	clearContactList();
	void	displayContact() const;
};