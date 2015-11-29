#include "waveguide.h"

namespace KFU
{
	Waveguide::Waveguide(int n, int m, int l, double al, double a, double b, double c): LinearSystem(2 * n)
	{
		std::cout << "Constructor\n";
	}
}
