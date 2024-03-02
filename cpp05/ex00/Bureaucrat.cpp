#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() : invalid_argument("Default Exception") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *message) : invalid_argument(message){}

Bureaucrat::GradeTooLowException::GradeTooLowException() : invalid_argument("Default Exception") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *message) : invalid_argument(message){}

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
