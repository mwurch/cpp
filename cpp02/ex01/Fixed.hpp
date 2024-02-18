#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {

	private:

		int					_fixedNumber;
		static const int	_fractionalBits = 8;

	public:

		Fixed();
		Fixed(int const n);
		Fixed(float const n);

		Fixed(Fixed const & src);
		Fixed & operator=(Fixed const & src);

		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

	
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif