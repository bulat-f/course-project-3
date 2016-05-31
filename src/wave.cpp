#include "wave.h"
#include <iostream>

namespace KFU
{
	Wave::Wave(int n): Vector<Complex>(n)
	{
	}

	Wave::Wave(int n, int l, Complex al): Vector<Complex>(n), number(l)
	{
		values[l] = al;
	}

	Wave::Wave(int n, int l, double al): Wave(n, l, Complex(al))
	{
	}

	Wave::Wave(const Vector<Complex>& w, int first, int last): Vector<Complex>(w, first, last)
	{
	}

	int Wave::getNumber()
	{
		return number;
	}
}