#pragma once

#include <iostream>

template<typename T>
class Matrix
{
public :
	Matrix()
	{
		m[0] = m[3] = 1;
		m[1] = m[2] = 0;
	}
	Matrix(const T& _0, const T& _1, const T& _2, const T& _3)
	{
		m[0] = _0;
		m[1] = _1;
		m[2] = _2;
		m[3] = _3;
	}
	~Matrix()
	{
	}

	Matrix& operator = (const T& n)
	{
		for (int i = 0; i < 4; i++)
			m[i] = n;
		return *this;
	}
	Matrix& operator = (const Matrix& o)
	{
		for (int i = 0; i < 4; i++)
			m[i] = o.m[i];
		return *this;
	}
	Matrix operator + (const Matrix& o)
	{
		return Matrix(m[0] + o.m[0],
					  m[1] + o.m[1],
					  m[2] + o.m[2],
					  m[3] + o.m[3]);
	}
	Matrix operator - (const Matrix& o)
	{
		return Matrix(m[0] - o.m[0],
					  m[1] - o.m[1],
					  m[2] - o.m[2],
					  m[3] - o.m[3]);
	}
	Matrix operator * (const Matrix& o)
	{
		return Matrix(m[0]*o.m[0] + m[1]*o.m[2],
					  m[0]*o.m[1] + m[1]*o.m[3],
					  m[2]*o.m[0] + m[3]*o.m[2],
					  m[2]*o.m[1] + m[3]*o.m[3]);
	}
	friend Matrix operator * (const Matrix& o, const int& s)
	{
		return Matrix(o.m[0]*s,
					  o.m[1]*s,
					  o.m[2]*s,
					  o.m[3]*s);
	}
	friend Matrix operator * (const int& s, const Matrix& o)
	{
		return Matrix(o.m[0]*s,
					  o.m[1]*s,
					  o.m[2]*s,
					  o.m[3]*s);
	}
	Matrix operator << (const int& e)
	{
		Matrix tmp(*this);
		Matrix buffer;
		for (int i = 0; i < e; i++)
		{
			buffer = buffer*tmp;
		}
		return buffer;
	}
	T& operator [] (const int& index)
	{
		static T error = -1;
		if (index < 0 || index >= 4)
		{
			std::cout << "invalid index" << std::endl;
			return error;
		}
		return m[index];
	}
	friend std::ostream& operator << (std::ostream& os, const Matrix& obj)
	{
		os << obj.m[0] << '\t' << obj.m[1] << std::endl;
		os << obj.m[2] << '\t' << obj.m[3] << std::endl;
		os << "====================" << std::endl;
		return os;
	}

private :
	T m[4];
};