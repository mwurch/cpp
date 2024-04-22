#include "input_pars.hpp"


type get_type(const std::string & input)
{
	if (isINT(input))
		return INT;
	else if (isCHAR(input))
		return CHAR;
	else if (isFLOAT(input))
		return FLOAT;
	else if (isDOUBLE(input))
		return DOUBLE;
	else
		return UNKNOWN;
}

bool	isINT(const std::string & input)
{
	//
}

bool	isCHAR(const std::string & input)
{
	//
}

bool	isFLOAT(const std::string & input)
{
	//
}

bool	isDOUBLE(const std::string & input)
{
	//
}