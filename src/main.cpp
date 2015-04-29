#include <iostream>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "linear_system.h"
#include <vector>

using namespace std;

int main()
{
	KFU::LinearSystem sys(2, 2);
	cin >> sys;
	cout << sys;
	return 0;
}
