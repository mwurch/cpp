#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain deafault constructor was called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Default thought";
}

Brain::~Brain()
{
	std::cout << "Brain destructor was called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor was called" << std::endl;
	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
}

Brain & Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}