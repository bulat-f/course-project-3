#include <iostream>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include <vector>

using namespace std;

int main()
{
	// float array[] = {1, 2, 3};
	KFU::Vector<float> v1;
	KFU::Matrix<float> m1;
	cin >> v1;
	cin >> m1;
	cout << v1 << endl;
	cout << m1 << endl;
	return 0;
}
