#ifndef WAVE_H_
#define WAVE_H_

#include "vector.h"
#include "complex.h"

namespace KFU
{
	class Wave: protected Vector<Complex>
	{
		public:
			Wave(int n, int l, Complex al);
		private:
	};
}

#endif