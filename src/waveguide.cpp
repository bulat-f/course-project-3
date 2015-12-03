#include "waveguide.h"
#include "cmath"

namespace KFU
{
	Waveguide::Waveguide(double k, double a, double b, double c):
	wavenumber(k), height(b), position(a), width(c)
	{
	}

	double Waveguide::I_a(int n, int m)
	{
		double result = (M_PI * m / (height - position) * sin(M_PI * n * position / height)) / (gamma2(n) - gamma2_b(m));
		int coeff = (m % 2 == 0) ? -1 : 1;
		return coeff * result;
	}

	double Waveguide::I_b(int n, int m)
	{
		return (M_PI * m / position * sin(M_PI * n * position / height)) / (gamma2(n) - gamma2_a(m));
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

	Complex Waveguide::gamma(int m)
	{
		return sqrt(gamma2(m));
	}

	double Waveguide::gamma2(int m, double h)
	{
		return wavenumber * wavenumber - pow(M_PI * m / h, 2);
	}
}
