#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:

        Intern();
        Intern(Intern const & src);
        ~Intern();

        Intern& operator=(Intern const & src);
        AForm*  makeForm(std::string FormName, std::string target);
};

#endif