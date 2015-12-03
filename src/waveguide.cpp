#include "waveguide.h"

namespace KFU
{
	Waveguide::Waveguide(double k, double a, double b, double c):
	wavenumber(k), height(a), position(b), width(c)
	{
		std::cout << "Constructor\n" << wavenumber << std::endl;
	}
}
