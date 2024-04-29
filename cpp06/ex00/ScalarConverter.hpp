#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>


class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter const & src);

	public:

		static void	convert(std::string input);
};


#endif