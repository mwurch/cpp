#include "Intern.hpp"

// helper functions

AForm* makeShrub(std::string target) {return new ShrubberyCreationForm(target);}
AForm* makePresident(std::string target) {return new PresidentialPardonForm(target);}
AForm* makeRobo(std::string target) {return new RobotomyRequestForm(target);}

Intern::Intern() {};
Intern::Intern(Intern const & src) { (void)src;};
Intern::~Intern() {};

Intern& Intern::operator=(Intern const & src) {(void) src; return *this;}

AForm* Intern::makeForm(std::string FormName, std::string target)
{
    std::string FormTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    AForm* (*f[]) (std::string target) = {

        &makePresident,
        &makeRobo,
        &makeShrub
    };

    for (int index = 0; index < 3; index++)
    {
        if (FormTypes[index] == FormName)
        {
            std::cout << "Intern successfully created " << FormTypes[index] << "!" << std::endl;
            return (f[index](target));
        }
    }
    std::cerr << "Intern can not create an unknown formtype" << std::endl;
    return (NULL);
}

