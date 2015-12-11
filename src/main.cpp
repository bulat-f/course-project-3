#include <iostream>
#include <fstream>
#include "waveguide.h"
#include "waveguide_system.h"
#include "wave.h"
#include "linear_system.h"

using namespace std;

int main()
{
	// ifstream in("input");
	// KFU::LinearSystem sys(3, 3);
	KFU::Wave w(10, 3, 215.3);
	KFU::Waveguide guide(120, 5, 12, 4, 4);
	KFU::WaveguideSystem sys(guide, w);
	// in >> sys;
	// cout << sys;

	cout << guide.I_a(4, 2) << endl;
	return 0;
}
