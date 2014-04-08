#pragma once

template<typename T>
struct Point
{
	typedef T value_type;

	value_type x;
	value_type y;
};

template<typename T>
struct Rect
{
	typedef typename Point<T>::value_type value_type;

	Point<value_type> lt;
	Point<value_type> rb;
};

//struct Point
//{
//	int* x;
//	int* y;
//};
