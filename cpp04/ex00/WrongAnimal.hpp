#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:

		std::string type;

	public:
						
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal( WrongAnimal const & src);
		~WrongAnimal();
		WrongAnimal & operator=( WrongAnimal const & src);

		void	        makeSound(void) const;
		std::string		getType() const;

};

#endif