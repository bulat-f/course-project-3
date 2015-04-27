#ifndef VECTOR_H_
#define VECTOR_H_

#include <fstream>
#include <iostream>
#include <vector>

namespace KFU
{
	enum class Orientation
	{
		vertical, horizontal
	};

	template <class type>
	class Vector;

	template <class type>
	std::ostream& operator<<(std::ostream&, const Vector<type>&);

	template <class type>
	std::istream& operator>>(std::istream&, Vector<type>&);


	template <class type>
	class Vector {
		public:
			Vector();
			Vector(type *, int, Orientation);
			Vector(const Vector&);

			int size() const;

			type operator[](int) const;
			type& operator[](int);
			Vector& operator=(const Vector&);
			Vector& operator+(const Vector&);
		protected:
			std::vector<type> values;
			Orientation orient;
			friend std::ostream& operator<<<type>(std::ostream&, const Vector&);
			friend std::istream& operator>><type>(std::istream&, Vector&);
	};

	template <class type>
	Vector<type>::Vector(): values(), orient(Orientation::horizontal)
	{
	}

	template <class type>
	Vector<type>::Vector(type *array, int size, Orientation o = Orientation::horizontal): values(array, array + size), orient(o)
	{
	}

	template <class type>
	Vector<type>::Vector(const Vector& other): values(other.values), orient(other.orient)
	{
	}

	template <class type>
	int Vector<type>::size() const
	{
		return values.size();
	}

	template <class type>
	type Vector<type>::operator[](int i) const
	{
		return values[i];
	}

	template <class type>
	type& Vector<type>::operator[](int i)
	{
		return values[i];
	}

	template <class type>
	Vector<type>& Vector<type>::operator=(const Vector& other)
	{
		values = other.values;
		return *this;
	}

	template <class type>
	std::ostream& operator<<(std::ostream& out, const Vector<type>& data)
	{
		char separator = (' ');
		for (int i = 0; i < data.size(); i++)
			out << data[i] << separator;
		return out;
	}

	template <class type>
	std::istream& operator>>(std::istream& in, Vector<type>& data)
	{
		int size;
		in >> size;
		data.values.resize(size);
		for (int i = 0; i < data.size(); i++)
			in >> data[i];
		return in;
	}
}

#endif
