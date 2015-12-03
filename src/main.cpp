#include <iostream>
#include <fstream>
#include "waveguide.h"
#include "wave.h"
#include "linear_system.h"

using namespace std;

int main()
{
	ifstream in("input");
	KFU::LinearSystem sys(3, 3);
	KFU::Wave w(10, 3, 215.3);
	KFU::Waveguide(120, 10, 5, 4);
	in >> sys;
	cout << sys.solve();
	return 0;
}
