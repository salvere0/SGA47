#pragma once

#include <list>

template<typename T>
class MyQueue
{
public :
	void push(const T& v)
	{
		data.push_back(v);
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