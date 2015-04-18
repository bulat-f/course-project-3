#include <iostream>
#include "vector.h"
#include "matrix.h"

using namespace std;

int main()
{
	float array[] = {1.6, 2, 3, 5};
	float **matrix = new float*[2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new float[2];
		for (int j = 0; j < 2; j++)
			matrix[i][j] = i + j + 3;
	}
	KFU::Vector<float> v1(array, 4);
	KFU::Vector<float> v2(v1);
	KFU::Matrix<float> m1(matrix, 2, 2);
	KFU::Matrix<float> m2(m1);
	v2[1]++;
	v1 = v2;
	cout << v1 << endl;
	cout << m2 << endl;
	return 0;
}
