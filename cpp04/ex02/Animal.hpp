#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	private:

		Brain* brain;
		
	protected:

		std::string type;

	public:
						
		Animal();
		Animal(std::string type);
		Animal( Animal const & src);
		virtual ~Animal();
		Animal & operator=( Animal const & src);

		virtual	void	makeSound(void) const;
		//std::string		getType() const;

		Brain *getBrain();

};

#endif