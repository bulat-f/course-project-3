#ifndef LINEAR_SYSTEM_H_
#define LINEAR_SISTEM_H_

#include <iostream>
#include "matrix.h"
#include "vector.h"
#include "complex.h"

namespace KFU
{
	class LinearSystem
	{
		public:
			LinearSystem();
			LinearSystem(int, int);
			LinearSystem(const Matrix<Complex>&, const Vector<Complex>&);
			LinearSystem(const LinearSystem&);

			int equations() const;
			int variables() const;

			void swap_lines(int, int);

			Vector<Complex> solve();
		private:
			Vector<Complex> vector_;
			Matrix<Complex> matrix_;
			friend std::ostream& operator<<(std::ostream&, LinearSystem&);
			friend std::istream& operator>>(std::istream&, LinearSystem&);
	};
}

#endif
