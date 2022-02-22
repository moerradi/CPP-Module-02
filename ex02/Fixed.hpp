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
		// arethmetic operators
		Fixed operator+(const Fixed &f);
		Fixed operator-(const Fixed &f);
		Fixed operator*(const Fixed &f);
		Fixed operator/(const Fixed &f);

		// pre-increment
		Fixed operator++(void);
		// post-increment
		Fixed operator++(int);
		// pre-decrement
		Fixed operator--(void);
		// post-decrement
		Fixed operator--(int);

		// comparison
		bool operator>(const Fixed &f) const;
		bool operator<(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a,const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a,const Fixed &b);
	private:
		int _n;
		static const int _fbits = 8;

};

std::ostream &operator << (std::ostream &out, const Fixed &f);

#endif