#include <iostream>
#include <iomanip> 
#include <list>
#include "Contact.class.hpp"

class PhoneBook
{
	
	private:
	
	std::list <Contact>	contactList;
	std::string 		user_input;
	int					contact_count;
	int		getContactCount( void ) const;
	void	increase_contact_count( void );
	void	decrease_contact_count( void );
	void	clearContactList();
	void	displayContact(int i) const;
	
	public:

	PhoneBook(int a1);
	~PhoneBook();

	
	void	promptUser();
	void	add();
	void	search();
	std::string get_user_input( void ) const;

};