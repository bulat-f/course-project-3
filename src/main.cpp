#include <iostream>
#include <fstream>
#include "waveguide.h"
#include "waveguide_system.h"
#include "wave.h"
#include "linear_system.h"
#include <cmath>

using namespace std;

int main()
{
	double wavenumber = 4;
	KFU::Wave w(3, 1, 500.);
	KFU::Waveguide guide(wavenumber, 4, 10, 8, 3);
	KFU::WaveguideSystem sys(guide, w);
	sys.solve_all();
	cout << sys.getSolutions()[0] << sys.getSolutions()[1];
	return 0;
}
