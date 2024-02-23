#ifndef SCAV_CLAP_HPP
# define SCAV_CLAP_HPP

# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:

        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();
        ScavTrap & operator=(ScavTrap const & src);
        void    guardGate(void);
        void    attack(const std::string &target);
};

#endif