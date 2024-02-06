#include <iostream>
#include "PhoneBook.class.hpp"

list_element    *PhoneBook::create_element (Contact data)
{
	return (new list_element(data));
}

void	PhoneBook::add_front( list_element *element)
{
	if (this->getContactCount() == 0)
		this->list = element;
	else
	{
		element->next = this->list;
		this->list = element;
	}
}

void	PhoneBook::pop_back( void )
{
	list_element	*curr = this->list;
	list_element	*tmp = NULL;

	if (getContactCount() < 1)
		return ;
	while (curr->next != NULL)
	{
		tmp = curr;
		curr = curr->next;
	}
	if (tmp == NULL)
	{
		delete this->list;
		this->list = NULL;
	}
	else
	{
		delete curr;
		tmp->next = NULL;
	}
	
}

void	PhoneBook::delete_list( void )
{
	list_element	*curr = this->list;
	list_element	*tmp;

	if (getContactCount() == 0)
		return;
	while(curr->next != NULL)
	{
		tmp = curr;
		curr = tmp->next;
		delete tmp;
	}
	delete(curr);
	curr = NULL;
}