#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException() : invalid_argument("Default Exception") {}

Form::GradeTooHighException::GradeTooHighException(const char *message) : invalid_argument(message) {}

Form::GradeTooLowException::GradeTooLowException() : invalid_argument("Default Exception") {}

Form::GradeTooLowException::GradeTooLowException(const char *message) : invalid_argument(message) {}

Form::Form() : _name("Default Form"), _isSigned(false), _minGrade(150), _execGrade(150)
{
}

Form::Form(std::string name, const int minGrade, const int execGrade) : _name(name), _isSigned(false), _minGrade(minGrade), _execGrade(execGrade)
{
    if (_minGrade > 150)
        throw GradeTooLowException("Provided grade is out of range [1, 150]. Please choose a lover grade");
    else if (_minGrade < 1)
        throw GradeTooHighException("Provided grade is out of range [1, 150]. Please choose a higher grade");
    else if (_execGrade > 150)
        throw GradeTooLowException("Provided grade is out of range [1, 150]. Please choose a lover grade");
    else if (_execGrade < 1)
        throw GradeTooHighException("Provided grade is out of range [1, 150]. Please choose a higher grade");
}

Form::~Form() {}

Form::Form(Form const & src) : _name(src._name), _isSigned(src._isSigned), _minGrade(src._minGrade), _execGrade(src._execGrade)
{
}

Form & Form::operator=(Form const & src)
{
    if (this != &src)
    {
        //Nothing to assign in this case
        //this->_isSigned = src._isSigned;
    }
    return (*this);
}




void		Form::beSigned(Bureaucrat & src)
{
    if (src.getGrade() > this->_minGrade)
        throw GradeTooLowException("Bureaucrat does not possess the required grade to sign this form!");
    else if (_isSigned == false)
    {
        this->_isSigned = true;
        std::cout << "Bureaucrat " << src.getName() << " signed " << this->getName() << std::endl;
    }
    else
        std::cout << "Bureaucrat " << src.getName() << " is not able to sign " << this->getName() << ". Form is already signed!" << std::endl;
}

std::string Form::getName() const
{
    return (this->_name);
}
int	Form::getMinGrade() const
{
    return (this->_minGrade);
}
int	Form::getExecGrade() const
{
    return (this->_execGrade);
}


std::ostream & operator<<(std::ostream & o, Form const & src)
{
    o << "==============" << std::endl;
    o << "Form name: " << src.getName() << std::endl;
    o << "Min. grade to sign: " << src.getMinGrade() << std::endl; 
    o << "Grade to Exec the form: " << src.getExecGrade() << std::endl;
    o << "==============" << std::endl;
    return (o);
}