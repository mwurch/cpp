#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
    Bureaucrat olaf("Olaf", 1);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm rob("home");
    PresidentialPardonForm biden("home");

    olaf.signForm(shrub);
    olaf.signForm(rob);

    olaf.executeForm(shrub);
    olaf.executeForm(rob);
    olaf.executeForm(biden);

    olaf.signForm(biden);
    olaf.executeForm(biden);

    Bureaucrat holger("Holger", 150);

    holger.executeForm(biden);
}