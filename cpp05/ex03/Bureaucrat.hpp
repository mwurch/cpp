#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <ostream>

class AForm;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:
	

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=( Bureaucrat const & src);

		~Bureaucrat();

		class GradeTooHighException : public std::invalid_argument
		{
			public:

				GradeTooHighException();
				GradeTooHighException(const char *message);
		};

		class GradeTooLowException : public std::invalid_argument
		{
			public:
				
				GradeTooLowException();
				GradeTooLowException(const char *message);
		};
		
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void		executeForm(AForm const & form);
		void		signForm(AForm &form);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);


#endif