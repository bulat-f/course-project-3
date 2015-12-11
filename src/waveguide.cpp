#include "waveguide.h"
#include "cmath"

namespace KFU
{
	Waveguide::Waveguide(double k, double a, double b, double c, int max):
	wavenumber(k), height(b), position(a), width(c), M(max)
	{
	}

	Complex Waveguide::S(int i, int j)
	{
		Complex S_1 = 0, S_2 = 0;
		for (int m = 0; i < M; i++)
		{
			S_1 += (1 / gamma_a(m)) * I_a(j, m) * I_a(i, m);
			S_2 += (1 / gamma_b(m)) * I_b(j, m) * I_b(i, m);
		}
		return S_1 * (2 / position) + S_2 * (2 / (height - position));
	}

	double Waveguide::delta(int i, int j)
	{
		return (i == j) ? height / 2 : 0;
	}

	double Waveguide::I_a(int n, int m)
	{
		double result = (position * height * height * m * sin(M_PI * n * position / height) / M_PI)
			/ (height * height * m * m - position * position * n * n);
		int coeff = (m % 2 == 0) ? -1 : 1;
		return coeff * result;
	}

	double Waveguide::I_b(int n, int m)
	{
		return (M_PI * m / (height - position) * sin(M_PI * n * position / height)) / (gamma2(n) - gamma2_a(m));
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
