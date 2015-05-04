#include "complex.h"
#include <cmath>

Complex::Complex(double Re_, double Im_): Re(Re_), Im(Im_)
{
}

Complex::Complex(const Complex& other): Re(other.Re), Im(other.Im)
{
}

double Complex::module() const
{
	return sqrt(Re*Re + Im*Im);
}

double Complex::re() const
{
	return Re;
}

double Complex::im() const
{
	return Im;
}

Complex& Complex::conjugate() const
{
	return *(new Complex(Re, -Im));
}

Complex& Complex::operator=(const Complex& other)
{
	Re = other.Re;
	Im = other.Im;
	return *this;
}

Complex& Complex::operator+(const Complex& other) const
{
	return *(new Complex(Re + other.Re, Im + other.Im));
}

Complex& Complex::operator-(const Complex& other) const
{
	return *(new Complex(Re - other.Re, Im - other.Im));
}

Complex& Complex::operator*(const Complex& other) const
{
	Complex *result = new Complex();
	result->Re = Re*other.Re - Im*other.Im;
	result->Im = Im*other.Re + Re*other.Im;
	return *result;
}

Complex& Complex::operator/(const Complex& other) const
{
	Complex *result = new Complex();
	*result = ((*this) * other.conjugate()) / pow(other.module(), 2);
	return *result;
}

Complex& Complex::operator+=(const Complex& other)
{
	(*this) = (*this) + other;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	(*this) = (*this) - other;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	(*this) = (*this) * other;
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	(*this) = (*this) / other;
	return *this;
}

Complex& Complex::operator=(double real)
{
	Re = real;
	return *this;
}

Complex& Complex::operator+(double real) const
{
	return *(new Complex(Re + real, Im));
}

Complex& Complex::operator-(double real) const
{
	return *(new Complex(Re - real, Im));
}

Complex& Complex::operator*(double real) const
{
	return *(new Complex(Re * real, Im * real));
}

Complex& Complex::operator/(double real) const
{
	return *(new Complex(Re / real, Im / real));
}

Complex& Complex::operator+=(double real)
{
	this->Re += real;
	return *this;
}

Complex& Complex::operator-=(double real)
{
	this->Re -= real;
	return *this;
}

Complex& Complex::operator*=(double real)
{
	this->Re *= real;
	this->Im *= real;
	return *this;
}

Complex& Complex::operator/=(double real)
{
	this->Re /= real;
	this->Im /= real;
	return *this;
}

bool Complex::operator==(const Complex& other) const
{
	return Re == other.Re && Im == other.Im;
}

Complex& operator+(double left, const Complex& right)
{
	return *(new Complex(left + right.Re, right.Im));
}

Complex& operator-(double left, const Complex& right)
{
	return *(new Complex(left - right.Re, -right.Im));
}

Complex& operator*(double left, const Complex& right)
{
	return *(new Complex(left * right.Re, left * right.Im));
}

Complex& operator/(double left, const Complex& right)
{
	Complex *result = new Complex();
	(*result) = (left * right.conjugate()) / pow(right.module(), 2);
	return *result;
}

std::istream& operator>>(std::istream& in, Complex& x)
{
	double _Re = 0, _Im = 0;
	char ch;
	in >> ch;
	if (ch == '(')
	{
		in >> _Re;
		in >> ch;
		if (ch == ',')
		{
			in >> _Im;
			in >> ch;
		}
		if (ch != ')')
		{
			in.setstate(std::ios_base::failbit);
		}
	}
	else
	{
		in.putback(ch);
		in >> _Re;
	}
	x = Complex(_Re, _Im);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& x)
{
	out << '(' << x.Re << ',' << x.Im << ')';
	return out;
}
