#include <iostream>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "linear_system.h"
#include <vector>

using namespace std;

int main()
{
	KFU::Vector<double> v1;
	KFU::Matrix<double> m1;
	cin >> v1;
	cin >> m1;
	cout << v1 << endl;
	cout << m1 << endl;
	KFU::LinearSystem sys(m1, v1);
	cout << sys;
	return 0;
}
