#include <iostream>
#include <fstream>
#include "waveguide.h"
#include "linear_system.h"
#include "complex.h"

using namespace std;

int main()
{
	ifstream in("input");
	KFU::LinearSystem sys(3, 3);
	KFU::Waveguide w(3, 3, 1, 10, 5, 10, 10);
	in >> sys;
	cout << sys.solve();
	return 0;
}
