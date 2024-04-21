#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat olaf("Olaf", 1);
    Intern max;

    AForm* a = max.makeForm("ShrubbaeryCreationForm", "Home");
    if (a)
    {
        olaf.signForm(*a);

        olaf.executeForm(*a);


        Bureaucrat holger("Holger", 150);

        holger.executeForm(*a);
    }  
}