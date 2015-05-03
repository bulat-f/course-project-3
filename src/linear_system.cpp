#include "linear_system.h"

namespace KFU
{
	LinearSystem::LinearSystem()
	{
	}

	LinearSystem::LinearSystem(int n, int m)
	{
		matrix_.resize(n, m);
		vector_.resize(n);
	}

	LinearSystem::LinearSystem(const Matrix<double>& m, const Vector<double>& v)
	{
		matrix_ = m;
		vector_ = v;
	}

	int LinearSystem::equations() const
	{
		return vector_.size();
	}

	int LinearSystem::variables() const
	{
		return matrix_.columns();
	}

	void LinearSystem::swap_lines(int i, int j)
	{
		matrix_.swap_lines(i, j);
		vector_.swap(i, j);
	}

	Vector<double> LinearSystem::solve()
	{
		Vector<double> v;
		return v;
	}

	std::ostream& operator<<(std::ostream& out, LinearSystem& sys)
	{
		for (int i = 0; i < sys.equations(); i++)
		{
			out << "| ";
			for (int j = 0; j < sys.variables(); j++)
			{
				out << sys.matrix_.getElem(i, j) << ' ';
			}
			out << " | ";
			out << sys.vector_[i] << std::endl;
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, LinearSystem& sys)
	{
		in >> sys.matrix_ >> sys.vector_;
		return in;
	}
}
