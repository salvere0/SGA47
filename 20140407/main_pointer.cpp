#include <iostream>
#include <conio.h>

class Data
{
public :
	enum class_id
	{
		KNIGHT,
		WIZARD,
		HEALDER,
		DEALEAR,
	};
	enum gender_id
	{
		NONE,
		FEMALE,
		MALE,
	};
public :
	Data(const int& gen, const int& cls)
		: nGender(gen), nClass(cls)
	{
	}

public :
	void Create(const int& gen, const int& cls)
	{
		nGender = gen;
		nClass = cls;
	}
	int getGender() const
	{
		return nGender;
	}
	int getClass() const
	{
		return nClass;
	}
private :
	int nGender;
	int nClass;
};

class Character
{
public :
	Character()
		: data(NULL)
	{
	}
	~Character()
	{
		if (data)
			delete data;
	}
	void Draw()
	{
		if (data)
		{
			if (data->getGender())
			{
			}

			if (data->getClass())
			{
			}
		}
	}
	void SetData(Data* pData)
	{
		data = pData;
	}

private :
	Data* data;
};

int main(void)
{
	// 3가지 사용....
	// 동적할당...
	// 함수인자...
	// 참조

	Character Human;

	Human.SetData(new Data(Data::KNIGHT, Data::MALE));

	Human.Draw();


	_getch();
	return 0;
}
