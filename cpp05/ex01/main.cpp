#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat test = Bureaucrat("Steven", 149);

    try {
        test.decrementGrade();
        std::cout << "Arbeitsamt" << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "===============================" << std::endl;

    try {
        std::cout << test.getGrade() << std::endl;
        test.decrementGrade();
        std::cout << test.getName() << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "===============================" << std::endl;

    test = Bureaucrat("Olaf" , 1);
    std::cout << test << std::endl;

    try {
        test.incrementGrade();
        std::cout << test.getName() << std::endl;;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}