#include <iostream>
#include <fstream>
#include "linear_system.h"
#include "complex.h"

using namespace std;

int main()
{
	ifstream in("input");
	KFU::LinearSystem sys(3, 3);
	in >> sys;
	cout << sys.solve();
	return 0;
}
