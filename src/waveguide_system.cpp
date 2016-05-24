#include "waveguide_system.h"

#include <iostream>

using namespace std;

namespace KFU
{
	WaveguideSystem::WaveguideSystem(Waveguide guide, Wave w):
	LinearSystem(w.size()), waveguide(guide), wave(w)
	{
		init_matrix();
		init_vector();
		solutions = new Wave(wave.size())[5];
	}


	void WaveguideSystem::solve_all()
	{
	}


	void WaveguideSystem::init_matrix()
	{
		int n = wave.size() / 2;
		Complex c(0, 1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_[i][j] = waveguide.gamma(j) * waveguide.S(i, j) + waveguide.delta(i, j);
				matrix_[i + n][j] = waveguide.exp_i(j) * (waveguide.gamma(j) * waveguide.S(i, j) + waveguide.delta(i, j));
		
				matrix_[i][j + n] = waveguide.gamma(j) * waveguide.S(i, j) * (-1) + waveguide.delta(i, j);
				matrix_[i + n][j + n] = waveguide.exp_i(j) * (waveguide.gamma(j) * waveguide.S(i, j) + waveguide.delta(i, j));
			}
		}
	}

	void WaveguideSystem::init_vector()
	{
		int n = wave.size() / 2, l = wave.getNumber();
		Complex a = wave[l] * 2;
		for (int k = 1; k <= n; k++)
			vector_[k - 1] = a * waveguide.I_a(k, l);
	}
}