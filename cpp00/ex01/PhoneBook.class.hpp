#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>
#include "Contact.class.hpp"

class PhoneBook
{
	
	private:
	
	Contact				contactList[8];
	std::string 		user_input;
	int					contact_count;
	int				getContactCount( void ) const;
	void			increase_contact_count( void );
	void			decrease_contact_count( void );
	void			displayContact(int i) const;
	void			add_front(Contact & newContact);
	int				get_data(std::string str);
	
	
	public:

	PhoneBook(int a1);
	~PhoneBook();


	void			promptUser();
	void			add();
	void			search();
	std::string 	get_user_input( void ) const;

};