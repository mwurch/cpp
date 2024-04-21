#include "ShrubberyCreationForm.hpp"


// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

// 1 Argument Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target) {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw NotSignedException("The current Form is not signed yet");
    else if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException("The Bureaucrat`s grade is too low to execute this Form");
    else
    {
        std::string tmp = _target;
        std::ofstream file(tmp.append("_shrubbery").c_str());
        if (!file.is_open())
        {
            std::cerr << "Creating *_shruberry file failed" << std::endl;
            return ;
        }
        
        file <<
                    "         v" << std::endl <<
                    "        >X<" << std::endl <<
                    "         A" << std::endl <<
                    "        d$b" << std::endl <<
                    "      .d\\$$b." << std::endl <<
                    "    .d$i$$\\$$b." << std::endl <<
                    "       d$$@b" << std::endl <<
                    "      d\\$$$ib" << std::endl <<
                    "    .d$$$\\$$$b" << std::endl <<
                    "  .d$$@$$$$\\$$ib." << std::endl <<
                    "      d$$i$$b" << std::endl <<
                    "     d\\$$$$@$b" << std::endl <<
                    "  .d$@$$\\$$$$$@b." << std::endl <<
                    ".d$$$$i$$$\\$$$$$$b." << std::endl <<
                    "        ###" << std::endl <<
                    "        ###" << std::endl <<
                    "        ###" << std::endl <<
                std::endl;
        file.close();
    }
}