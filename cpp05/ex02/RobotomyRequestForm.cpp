#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

// 1 Argument Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target) {}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw NotSignedException("The current Form is not signed yet");
    else if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException("The Bureaucrat's grade is too low to execute this Form");
    else
    {
        srand(time(NULL));
        int successRate = rand();
        if (successRate & 1)
        {
            std::cout << "*drilling noises*" << std::endl;
            std::cout << _target << " has been robotomized successfully!" << std::endl;
        }
        else
            std::cout << "Robotomy on " << _target << " has failed." << std::endl;
    }
}
