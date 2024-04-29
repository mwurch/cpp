#include "getNumbers.hpp"

void	printChar(char c)
{
	int i;
	float f;
	double d;

	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	if (c > 126 || c < 33)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	printInt(int i)
{
	char	c;
	float	f;
	double	d;

	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	if ((i > 127 || i < 0) || std::floor(d) != d)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	if (isInIntRange(d))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (f == std::floor(d) ? ".0" : "") << std::endl;
}

void	printFloat(float f)
{
	char	c;
	int		i;
	double	d;

	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);

	if ((i > 127 || i < 0) || std::floor(d) != d)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (isInIntRange(d))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (f == std::floor(d) ? ".0" : "") << std::endl;
}

void	printDouble(double d)
{
	char	c;
	int		i;
	float	f;

	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);

	if ((i > 127 || i < 0) || std::floor(d) != d)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (isInIntRange(d))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (f == std::floor(d) ? ".0" : "") << std::endl;
}


// util

bool	isInIntRange(double input)
{
	return input <= std::numeric_limits<int>::max() && input >= std::numeric_limits<int>::min();
}
