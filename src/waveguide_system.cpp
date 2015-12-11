#include "waveguide_system.h"

#include <iostream>

namespace KFU
{
	WaveguideSystem::WaveguideSystem(Waveguide guide, Wave w):
	LinearSystem(w.size()), waveguide(guide), wave(w)
	{
		init_matrix();
		init_vector();
	}


	void WaveguideSystem::init_matrix()
	{
		int n = wave.size() / 2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_[i][j] = waveguide.gamma(j) * waveguide.S(i, j) + waveguide.delta(i, j);
			}

			for (int j = n; j < 2 * n; j++)
			{
				matrix_[i][j] = waveguide.gamma(j) * waveguide.S(i, j) * (-1) + waveguide.delta(i, j);
			}
		}

		// for (int i = n; i < 2 * n; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		matrix_[i][j] = waveguide.gamma(j) * waveguide.S(i, j) + waveguide.delta(i, j);
		// 	}

		// 	for (int j = n; j < 2 * n; j++)
		// 	{
		// 		matrix_[i][j] = waveguide.gamma(j) * waveguide.S(i, j) * (-1) + waveguide.delta(i, j);
		// 	}
		// }
	}

	void WaveguideSystem::init_vector()
	{
	}

	Complex WaveguideSystem::exp_i(Complex x)
	{
		return Complex(sin(0), cos(0));
	}
}