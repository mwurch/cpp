#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>
#include "Animal.hpp"


class Cat : public Animal
{
	public:

			Cat();
			Cat(Cat const & src);
			~Cat();
			Cat &	operator=(Cat const & src);
			void	makeSound(void) const;
};

#endif