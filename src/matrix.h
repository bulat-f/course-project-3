#ifndef MATRIX_H_
#define MATRIX_H_

#include <fstream>
#include <iostream>
#include <vector>

namespace KFU
{
	template <class type>
	class Matrix;

	template <class type>
	std::ostream& operator<<(std::ostream&, const Matrix<type>&);

	template <class type>
	std::istream& operator>>(std::istream&, Matrix<type>&);

	template <class type>
	class Matrix
	{
		public:
			Matrix();
			Matrix(type **, const int &, const int &);
			Matrix(const Matrix &);
			int rows() const;
			int columns() const;

			type getElem(int, int) const;

			Matrix& operator=(const Matrix&);
		private:
			std::vector<std::vector<type>> values;
			friend std::ostream& operator<<<type>(std::ostream&, const Matrix&);
			friend std::istream& operator>><type>(std::istream&, Matrix&);
	};

	template <class type>
	Matrix<type>::Matrix(): values()
	{
	}

	template <class type>
	Matrix<type>::Matrix(type **array, const int &n, const int &m): values(n)
	{
		for (int i = 0; i < n; i++)
		{
			values[i].resize(m);
			for (int j = 0; j < m; j++)
				values[i][j] = array[i][j];
		}
	}

	template <class type>
	Matrix<type>::Matrix(const Matrix& other): values(other.values)
	{
	}

	template <class type>
	int Matrix<type>::rows() const
	{
		return values.size();
	}

	template <class type>
	int Matrix<type>::columns() const
	{
		return (values.empty() ? 0 : values[0].size());
	}

	template <class type>
	type Matrix<type>::getElem(int i, int j) const
	{
		return values[i][j];
	}

	template <class type>
	std::ostream& operator<<(std::ostream& out, const Matrix<type>& data)
	{
		for (int i = 0; i < data.rows(); i++)
		{
			for (int j = 0; j < data.columns(); j++)
				out << data.values[i][j] << ' ';
			out << std::endl;
		}
		return out;
	}

	template <class type>
	Matrix<type>& Matrix<type>::operator=(const Matrix& other)
	{
		values = other.values;
		return *this;
	}

	template <class type>
	std::istream& operator>>(std::istream& in, Matrix<type>& data)
	{
		int rows, columns;
		in >> rows >> columns;
		data.values.resize(rows);
		for (int i = 0; i < rows; i++)
		{
			data.values[i].resize(columns);
			for (int j = 0; j < columns; j++)
				in >> data.values[i][j];
		}
		return in;
	}
}

#endif
