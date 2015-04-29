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
			LinearSystem(const int, const int);
			LinearSystem(const Matrix<double>&, const Vector<double>&);

			int equations() const;
			int variables() const;

			Vector<double> solve();
		private:
			Vector<double> vector_;
			Matrix<double> matrix_;
			friend std::ostream& operator<<(std::ostream&, LinearSystem&);
			friend std::istream& operator>>(std::istream&, LinearSystem&);
	};
}

#endif
