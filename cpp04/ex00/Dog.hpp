#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"


class Dog : public Animal
{
	public:

			Dog();
			Dog(Dog const & src);
			~Dog();
			Dog &	operator=(Dog const & src);
			void	makeSound(void) const;
};

#endif