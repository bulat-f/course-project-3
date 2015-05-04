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

	Complex c1, c2;
	cin >> c1 >> c2;
	cout << c1 << ' ' << c2 << endl;
	if (c1 == c2)
		cout << "Yes\n";
	return 0;
}
