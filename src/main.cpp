#include <iostream>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "linear_system.h"

using namespace std;

int main()
{
	KFU::LinearSystem sys(3, 3);
	cin >> sys;
	sys.swap_lines(1, 2);
	cout << sys;
	return 0;
}
