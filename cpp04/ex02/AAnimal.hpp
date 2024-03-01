#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    private:

        Brain* brain;

    protected:

        std::string type;
    
    public:

        AAnimal();
		AAnimal(std::string type);
		AAnimal( AAnimal const & src);
		virtual ~AAnimal();
		AAnimal & operator=( AAnimal const & src);

		virtual	void	makeSound(void) = 0;
};
#endif