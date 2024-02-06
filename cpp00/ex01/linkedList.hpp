#ifndef LINKED_LIST_HPP
# define LINKED_LIST_HPP

#include "Contact.class.hpp"
typedef struct list_element
{
	Contact			contact;
	list_element	*next;

	list_element(Contact a1) : contact(a1)
	{
		this->next = NULL;
	};
	~list_element()
	{
		
	};
} list_element;

#endif