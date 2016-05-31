#ifndef WAVEGUIDE_SYSTEM_H_
#define WAVEGUIDE_SYSTEM_H_

#include "linear_system.h"
#include "waveguide.h"
#include "wave.h"
#include "complex"

namespace KFU
{
	class WaveguideSystem: public LinearSystem
	{
		public:
			WaveguideSystem(Waveguide guide, Wave w);
			void solve_all();
			Wave* getSolutions();
		private:
			Waveguide waveguide;
			Wave wave;
			Wave* solutions;

			void init_matrix();
			void init_vector();

			Complex exp_i(Complex x);
	};
}

#endif