#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
	float array[] = {1.6, 2, 3, 5};
	KFU::Vector<float> v1(array, 4);
	KFU::Vector<float> v2(v1);
	v2[1]++;
	v1 = v2;
	cout << v1 << endl;
	return 0;
}
