#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_minGrade;
		const int			_execGrade;

	public:

		Form();
		Form(std::string name, const int minGrade, const int execGrade);
		Form(Form const & src);
		~Form();

		Form &operator=(Form const & src);
		

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


		void		beSigned(Bureaucrat & src);
		std::string getName() const;
		int	getMinGrade() const;
		int	getExecGrade() const;

};


std::ostream & operator<<(std::ostream &o, Form const & src);

#endif