#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::GradeTooHighException::GradeTooHighException() : invalid_argument("Default Exception") {}

AForm::GradeTooHighException::GradeTooHighException(const char *message) : invalid_argument(message) {}

AForm::GradeTooLowException::GradeTooLowException() : invalid_argument("Default Exception") {}

AForm::GradeTooLowException::GradeTooLowException(const char *message) : invalid_argument(message) {}

AForm::AForm() : _name("Default Form"), _isSigned(false), _minGrade(150), _execGrade(150)
{
}

AForm::AForm(std::string name, const int minGrade, const int execGrade) : _name(name), _isSigned(false), _minGrade(minGrade), _execGrade(execGrade)
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

AForm::~AForm() {}

AForm::AForm(AForm const & src) : _name(src._name), _isSigned(src._isSigned), _minGrade(src._minGrade), _execGrade(src._execGrade)
{
}

AForm & AForm::operator=(AForm const & src)
{
    if (this != &src)
    {
        //Nothing to assign in this case
        //this->_isSigned = src._isSigned;
    }
    return (*this);
}




void		AForm::beSigned(Bureaucrat & src)
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

std::string AForm::getName() const
{
    return (this->_name);
}
int	AForm::getMinGrade() const
{
    return (this->_minGrade);
}
int	AForm::getExecGrade() const
{
    return (this->_execGrade);
}


std::ostream & operator<<(std::ostream & o, AForm const & src)
{
    o << "==============" << std::endl;
    o << "Form Name                 : " << src.getName() << std::endl;
    o << "Min. Grade to sign        : " << src.getMinGrade() << std::endl; 
    o << "Grade to Exec the form    : " << src.getExecGrade() << std::endl;
    o << "==============";
    return (o);
}