#ifndef WAVEGUIDE_H_
#define WAVEGUIDE_H_

#include <iostream>
#include "linear_system.h"

namespace KFU
{
	class Waveguide: protected LinearSystem
	{
		public:
			Waveguide(double k, double a, double b, double c);
		private:
			double wavenumber;
			double height;
			double position;
			double width;
	};
}

#endif
