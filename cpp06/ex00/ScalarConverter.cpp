#include "ScalarConverter.hpp"
#include "ScalarTypes.hpp"
#include "input_pars.hpp"
#include "getNumbers.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) {(void) src;}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & src) {(void) src; return *this;}

void ScalarConverter::convert(std::string input)
{
	t_type type = get_type(input);
	std::istringstream test(input);
	double _test; test >> _test;
	std::istringstream iss(input);

	switch(type)
	{
		case INT:
		{
			if (!isInIntRange(_test)){
				printDouble(_test);
				break;
			}
			int i = std::atoi(input.c_str());
			printInt(i);
			break;
		}
		case CHAR:
			printChar(input[0]);
			break;
		case FLOAT:
		{
			if (input.back() == 'f')
				input.pop_back();
			if (_test > std::numeric_limits<float>::max() || _test < -std::numeric_limits<float>::max())
				throw std::out_of_range("FLoat is out of range");
			float f = static_cast<float>(std::strtof(input.c_str(), NULL));
			printFloat(f);
			break;
		}
		case DOUBLE:
		{
			double d; iss >> d;
			printDouble(d);
			break;
		}
		case PSEUDO:
			printPseudo(input);
			break ;
		case UNKNOWN:
			std::cout << "Invalid Input: " << input << std::endl; 
			break;
	}
}