#ifndef WAVEGUIDE_H_
#define WAVEGUIDE_H_

#include <iostream>
#include "complex.h"

namespace KFU
{
	class Waveguide
	{
		public:
			Waveguide(double, double, double, double);

			double I_a(int n, int m);
			double I_b(int n, int m);

			double gamma2_a(int m);
			double gamma2_b(int m);
			double gamma2(int m);

			Complex gamma_a(int m);
			Complex gamma_b(int m);
			Complex gamma(int m);
		private:
			double wavenumber;
			double height;
			double position; // partitions
			double width;    // partitions

			double gamma2(int n, double h);
	};
}

#endif
