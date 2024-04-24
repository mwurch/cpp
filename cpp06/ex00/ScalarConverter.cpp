#include "ScalarConverter.hpp"
#include "ScalarTypes.hpp"
#include "input_pars.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) {(void) src;}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & src) {(void) src;}

void ScalarConverter::convert(std::string input)
{
	type type = get_type(input);
	t_info info;

	switch(type)
	{
		case INT:
		case FLOAT:
		case DOUBLE:
		{
			info = getNumbers(input);
			break;
		}
		case CHAR:
		{
			info = getChar(input);
			break;
		}
		case UNKNOWN:
		{
			std::cout << "Invalid Input: " << input << std::endl; 
			break;
		}
	}

	

}