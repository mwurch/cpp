#include "input_pars.hpp"


t_type get_type(const std::string & input)
{
	if (isINT(input))
		return INT;
	else if (isCHAR(input))
		return CHAR;
	else if (isFLOAT(input))
		return FLOAT;
	else if (isDOUBLE(input))
		return DOUBLE;
	else if (isPSEUDO(input))
		return PSEUDO;
	else
		return UNKNOWN;
}

bool	isINT(const std::string & input)
{
	std::string tmp = input;
	if (input[0] == '-' || input[0] == '+')
		tmp.erase(0);
	size_t pos = tmp.find_first_not_of("0123456789");
	if (pos != std::string::npos)
		return false;
	return true;
}

bool	isCHAR(const std::string & input)
{
	if (input.size() != 1 || std::isdigit(input[0]))
		return false;
	return true;
}

bool	isFLOAT(const std::string & input)
{
	std::string tmp = input;
	if (input[0] == '-' || input[0] == '+')
		tmp.erase(0);
	size_t pos = tmp.find_first_not_of("0123456789.f");
	if (pos != std::string::npos)
		return false;
	if (count_char(input,'.') != 1 || count_char(input, 'f') != 1)
		return false;
	if (input[input.size() - 1] != 'f' || tmp[0] == '.' || input[input.size() - 2] == '.')
		return false;
	return true;
}

bool	isDOUBLE(const std::string & input)
{
	std::string tmp = input;
	if (input[0] == '-' || input[0] == '+')
		tmp.erase(0);
	size_t pos = tmp.find_first_not_of("0123456789.");
	if (pos != std::string::npos)
		return false;
	if (count_char(input, '.') != 1 || tmp[0] == '.' || input[input.size() - 1] == '.')
		return false;
	return true;
}

bool	isPSEUDO(const std::string & input)
{
	std::string pseudoTypes[] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};

	for (int index = 0; index < 6; index++)
	{
		if (pseudoTypes[index] == input)
			return true;
	}
	return false;
}

//util

size_t	count_char(std::string input, char c)
{
	size_t count = 0;

	for (size_t index = 0; index < input.size(); index++)
	{
		if (input[index] == c)
			count++;
	}
	return (count);
}