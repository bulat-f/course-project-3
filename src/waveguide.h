#ifndef WAVEGUIDE_H_
#define WAVEGUIDE_H

#include <iostream>
#include "linear_system.h"

namespace KFU
{
	class Waveguide: protected LinearSystem
	{
		public:
			Waveguide(int n, int m, int l, double al, double a, double b, double c);
		private:
	};
}

#endif
