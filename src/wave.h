#ifndef WAVE_H_
#define WAVE_H_

#include "vector.h"
#include "complex.h"

namespace KFU
{
	class Wave: public Vector<Complex>
	{
		public:
			Wave():Vector<Complex>() {}
			Wave(int n);
			Wave(int n, int l, Complex al);
			Wave(int n, int l, double al);
			Wave(const Vector<Complex>& w, int first, int last);

			int getNumber();
		private:
			int number;
	};
}

#endif