#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>
#include "Contact.class.hpp"
#include "linkedList.hpp"

class PhoneBook
{
	
	private:
	
	list_element				*list;
	std::string 		user_input;
	int					contact_count;
	int				getContactCount( void ) const;
	void			increase_contact_count( void );
	void			decrease_contact_count( void );
	void			displayContact(int i) const;
	list_element 	*create_element (Contact data);
	void			add_front( list_element *element);
	void			pop_back( void );
	int				get_data(std::string str);
	bool			isNumeric(std::string& str);
	
	public:

	PhoneBook(int a1);
	~PhoneBook();

	
	void			promptUser();
	void			add();
	void			search();
	std::string 	get_user_input( void ) const;
	void			delete_list( void );

};