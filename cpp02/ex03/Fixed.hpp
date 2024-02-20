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

		bool	operator<(Fixed const & src) const;
		bool	operator>(Fixed const & src) const;
		bool    operator>=(Fixed const & src) const;
		bool    operator<=(Fixed const & src) const;
		bool    operator==(Fixed const & src) const;
		bool    operator!=(Fixed const & src) const;
		
		float   operator-(Fixed const & src) const;
		float   operator+(Fixed const & src) const;
		float   operator*(Fixed const & src) const;
		float   operator/(Fixed const & src) const;

		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed & operator++();
		Fixed & operator--();


		~Fixed();

		static Fixed & min(Fixed &a, Fixed &b);
		static const Fixed & min(const Fixed &a, const Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

	
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif