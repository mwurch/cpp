#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:

			std::string type;

	public:
						
		Animal();
		Animal(std::string type);
		Animal( Animal const & src);
		virtual ~Animal();
		Animal & operator=( Animal const & src);
		virtual	void	makeSound(void) = 0;
			
};

#endif