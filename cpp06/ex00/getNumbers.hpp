#ifndef GETNUMBERS_HPP
#define GETNUMBERS_HPP

#include "ScalarConverter.hpp"
#include "ScalarTypes.hpp"
#include "input_pars.hpp"

void	printChar(char c);
void	printInt(int i);
void	printFloat(float f);
void	printDouble(double d);
void	printPseudo(std::string & input);

bool	isInIntRange(double input);
#endif