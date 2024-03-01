#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"


class Cat : public AAnimal
{
	public:

			Cat();
			Cat(Cat const & src);
			~Cat();
			Cat &	operator=(Cat const & src);
			void	makeSound(void);
};

#endif