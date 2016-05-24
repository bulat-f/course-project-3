#include "waveguide.h"
#include "cmath"
#include <iostream>
using namespace std;

namespace KFU
{
	Waveguide::Waveguide(double k, double a, double b, double c, int max):
	wavenumber(k), height(b), position(a), width(c), M(max)
	{
	}

	Complex Waveguide::S(int i, int j)
	{
		i++;
		j++;
		Complex S_1 = 0, S_2 = 0;
		for (int m = 0; m < M; m++)
		{
			S_1 += (1 / gamma_a(m)) * I_a(j, m) * I_a(i, m);
			S_2 += (1 / gamma_b(m)) * I_b(j, m) * I_b(i, m);
		}
		Complex s = S_1 * (2 / position) + S_2 * (2 / (height - position));
		return s;
	}

	double Waveguide::delta(int i, int j)
	{
		return (i == j) ? height / 2 : 0;
	}

	double Waveguide::I_a(int n, int m)
	{
		return I_base(n, m, position, height);
	}

	double Waveguide::I_b(int n, int m)
	{
		return I_base(n, m, height - position, height);
	}

	double Waveguide::gamma2_a(int m)
	{
		return gamma2(m, position);
	}

	double Waveguide::gamma2_b(int m)
	{
		return gamma2(m, height - position);
	}

	double Waveguide::gamma2(int m)
	{
		return gamma2(m, height);
	}

	Complex Waveguide::gamma_a(int m)
	{
		return sqrt(gamma2_a(m));
	}

	Complex Waveguide::gamma_b(int m)
	{
		return sqrt(gamma2_b(m));
	}

	Complex Waveguide::exp_i(int k)
	{
		Complex i(0, 1);
		return _exp_i(gamma(k) * (height- position) * i);
	}

	Complex Waveguide::gamma(int m)
	{
		return sqrt(gamma2(m));
	}

	double Waveguide::gamma2(int m, double h)
	{
		return wavenumber * wavenumber - pow(M_PI * m / h, 2);
	}

	double Waveguide::I_base(int n, int m, double a, double b) // 7, 3, 6, 14
	{
		double result = (a * b * b * m * sin(M_PI * n * a / b) / M_PI)
			/ (b * b * m * m - a * a * n * n);
		int coeff = (m % 2 == 0) ? -1 : 1;
		return coeff * result;
	}

	Complex Waveguide::_exp_i(Complex x)
	{
		return Complex(cos(x.im()), sin(x.im())) * exp(x.re());
	}
}
