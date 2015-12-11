#include "wave.h"
#include <iostream>

namespace KFU
{
	Wave::Wave(int n, int l, Complex al): Vector<Complex>(n), number(l)
	{
		values[l] = al;
		std::cout << "Wave constructor\n" << (*this) << std::endl;
	}

  int Wave::getNumber()
  {
    return number;
  }
}