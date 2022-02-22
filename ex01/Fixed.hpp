#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &f);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int _n;
		static const int _fbits = 8;

};

std::ostream &operator << (std::ostream &out, const Fixed &f);

#endif