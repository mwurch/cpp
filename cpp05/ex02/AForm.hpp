#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_minGrade;
		const int			_execGrade;

	public:

		AForm();
		AForm(std::string name, const int minGrade, const int execGrade);
		AForm(AForm const & src);
		virtual ~AForm();

		AForm &operator=(AForm const & src);
		

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

		class IsNotSignedException : public std::invalid_argument
		{
			public:
				
				IsNotSignedException();
				IsNotSignedException(const char *message);
		};

		void				beSigned(Bureaucrat & src);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
		std::string getName() const;
		int	getMinGrade() const;
		int	getExecGrade() const;
};


std::ostream & operator<<(std::ostream &o, AForm const & src);

#endif