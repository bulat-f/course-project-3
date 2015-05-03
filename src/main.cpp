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

	Complex c1(1, 3), c2(4, 2), c = c1 * 4;
	c1 *= 4;
	if (c1 == c)
		cout << "Yes\n";
	return 0;
}
