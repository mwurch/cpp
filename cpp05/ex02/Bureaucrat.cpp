#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() : invalid_argument("Default Exception") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *message) : invalid_argument(message){}

Bureaucrat::GradeTooLowException::GradeTooLowException() : invalid_argument("Default Exception") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *message) : invalid_argument(message){}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Default Constructor was called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 0)
        throw GradeTooHighException("Provided grade is out of range [1, 150]. Please choose a lower grade");
    else if (grade > 150)
        throw GradeTooLowException("Provided grade is out of range [1, 150]. Please choose a higher grade");
    else
        this->_grade = grade;
}


Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this != &src)
        this->_grade = src._grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException("Grade is already the highest value possible <1>!");
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException("Grad is already the lowest value possible <150>!");
    _grade++;
}

void Bureaucrat::signForm(AForm & form)
{
    try {
        form.beSigned(*this);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try {
        form.execute(*this);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << src.getName() << "'s grade is: " << src.getGrade();
	return (o);
}
