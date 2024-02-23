#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
	private:

	protected:

		std::string _name;
		int         _hitPoints;
		int         _energyPoints;
		int         _attackDamage;

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		ClapTrap & operator=(ClapTrap const &src);
		~ClapTrap();

		virtual void    attack(const std::string &target);
		void            takeDamage(unsigned int amount);
		void            beRepaired(unsigned int amount);
};

#endif