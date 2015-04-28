#include "linear_system.h"

namespace KFU
{
	LinearSystem::LinearSystem()
	{
	}

	LinearSystem::LinearSystem(const Matrix<double>& matrix_, const Vector<double>& vector_)
	{
		m = matrix_;
		v = vector_;
	}

	Vector<double> LinearSystem::solve()
	{
		Vector<double> v;
		return v;
	}

	std::ostream& operator<<(std::ostream& out, LinearSystem& sys)
	{
		for (int i = 0; i < sys.v.size(); i++)
		{
			out << "| ";
			for (int j = 0; j < sys.m.columns(); j++)
			{
				out << sys.m.getElem(i, j) << ' ';
			}
			out << " | ";
			out << sys.v[i] << std::endl;
		}
		return out;
	}
}
