#pragma once

#include <list>

template<typename T>
class MyStack
{
public :
	void push(const T& v)
	{
		data.push_front(v);
	}
	void pop()
	{
		data.pop_front();
	}
	T value()
	{
		return (*(data.begin()));
	}
	bool IsEmpty()
	{
		return data.empty();
	}


private :
	std::list<T> data;
};