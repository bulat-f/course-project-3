#include "waveguide_system.h"

#include <iostream>

using namespace std;

namespace KFU
{
	WaveguideSystem::WaveguideSystem(Waveguide guide, Wave w):
	LinearSystem(2 * w.size()), waveguide(guide), wave(w)
	{
		init_matrix();
		init_vector();
		solutions = new Wave[6];
	}


	void WaveguideSystem::solve_all()
	{
		int n = wave.size();
		Vector<Complex> s(solve());
		solutions[0] = *(new Wave(s, 0, n));
		solutions[1] = *(new Wave(s, n, 2*n));
	}

	Wave* WaveguideSystem::getSolutions()
	{
		return solutions;
	}


	void WaveguideSystem::init_matrix()
	{
		int n = wave.size();
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
		int n = wave.size(), l = wave.getNumber();
		Complex a = wave[l] * 2;
		for (int k = 1; k <= n; k++)
			vector_[k - 1] = a * waveguide.I_a(k, l);
	}
}