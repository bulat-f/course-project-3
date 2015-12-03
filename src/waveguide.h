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
			Complex gamma_am(int m);
			Complex gamma_bm(int m);
			Complex gamma_m(int m);
		private:
			double wavenumber;
			double height;
			double position; // partitions
			double width;    // partitions

			Complex gamma(int n, double h);
	};
}

#endif
