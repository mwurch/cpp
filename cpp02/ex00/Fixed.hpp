#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

	private:

		int	_fixedNumber;
		static const int _fractionalBits = 8;

	public:

		Fixed();
		Fixed(Fixed const & src);
		Fixed & operator=(Fixed const & src);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	
};
#endif