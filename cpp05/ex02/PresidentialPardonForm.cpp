#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw NotSignedException("The current Form is not signed yet");
    else if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException("The Bureaucrat's grade is too low to execute this Form");
    else
    {
        std::cout << _target << " has been pardoned by the Zaphod Beeblebrox!" << std::endl;
    }
}
