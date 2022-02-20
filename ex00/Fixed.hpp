#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &f);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _n;
		static const int _fbits = 8;

};

#endif