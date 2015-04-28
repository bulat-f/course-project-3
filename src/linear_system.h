#ifndef LINEAR_SYSTEM_H_
#define LINEAR_SISTEM_H_

#include <iostream>
#include "matrix.h"
#include "vector.h"

namespace KFU
{
	class LinearSystem
	{
		public:
			LinearSystem();
			LinearSystem(const Matrix<double>&, const Vector<double>&);

			Vector<double> solve();
		private:
			Vector<double> v;
			Matrix<double> m;
			friend std::ostream& operator<<(std::ostream&, LinearSystem&);
	};
}

#endif
