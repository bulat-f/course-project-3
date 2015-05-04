#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex
{
	public:
		Complex(double = 0, double = 0);
		Complex(const Complex&);

		double module() const;
		double re() const;
		double im() const;

		Complex& conjugate() const;

		Complex& operator=(const Complex&);
		Complex& operator+(const Complex&) const;
		Complex& operator-(const Complex&) const;
		Complex& operator*(const Complex&) const;
		Complex& operator/(const Complex&) const;
		Complex& operator=(double);
		Complex& operator+(double) const;
		Complex& operator-(double) const;
		Complex& operator*(double) const;
		Complex& operator/(double) const;

		Complex& operator+=(const Complex&);
		Complex& operator-=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator/=(const Complex&);
		Complex& operator+=(double);
		Complex& operator-=(double);
		Complex& operator*=(double);
		Complex& operator/=(double);

		bool operator==(const Complex&) const;
	private:
		double Re, Im;

		friend Complex& operator+(double, const Complex&);
		friend Complex& operator-(double, const Complex&);
		friend Complex& operator*(double, const Complex&);
		friend Complex& operator/(double, const Complex&);
		friend std::istream& operator>>(std::istream&, Complex&);
		friend std::ostream& operator<<(std::ostream&, const Complex&);
};

#endif
