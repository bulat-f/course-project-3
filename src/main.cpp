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
	double wavenumber = 100;
	KFU::Wave w(6, 3, 215.3);
	KFU::Waveguide guide(wavenumber, 6, 14, 4, 3);
	KFU::WaveguideSystem sys(guide, w);
	cout << sys.solve();
	cout << guide.gamma(2) * 0.1 << endl;
	return 0;
}
