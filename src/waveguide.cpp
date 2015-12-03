#include "waveguide.h"
#include "cmath"

namespace KFU
{
	Waveguide::Waveguide(double k, double a, double b, double c):
	wavenumber(k), height(a), position(b), width(c)
	{
	}

	Complex Waveguide::gamma_am(int m)
	{
		return gamma(m, position);
	}

	Complex Waveguide::gamma_bm(int m)
	{
		return gamma(m, height - position);
	}

	Complex Waveguide::gamma_m(int m)
	{
		return gamma(m, height);
	}

	Complex Waveguide::gamma(int m, double h)
	{
		Complex result;
		result = sqrt(wavenumber * wavenumber - pow(M_PI * m / h, 2));
		return result;
	}
}
