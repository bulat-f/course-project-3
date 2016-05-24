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

  int Wave::getNumber()
  {
    return number;
  }
}