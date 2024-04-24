#ifndef INPUT_PARS_HPP
#define INPUT_PARS_HPP

#include <iostream>
#include <string>
#include "ScalarTypes.hpp"



//functions to get type
type get_type(const std::string & input);
bool	isINT(const std::string & input);
bool	isCHAR(const std::string & input);
bool	isFLOAT(const std::string & input);
bool	isDOUBLE(const std::string & input);


// util
size_t	count_char(std::string input, char c);

#endif