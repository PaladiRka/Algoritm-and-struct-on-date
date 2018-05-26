#include "intHashMap.h"



IntHashMap::IntHashMap()
{
}

void IntHashMap::put(int key, int value)
{
	if ((value < 32) && (value > 0))
	{
		int hash = hash_func(key);
		map[hash] = value;
	}
}

int IntHashMap::get(int key)
{
	return map[hash_func(key)];
}

int IntHashMap::rand_value()
{
	int result;
	return contain(result = (rand()*5) % MAXINT + 1) < 0 ? result : 0;
}

IntHashMap IntHashMap::operator*(IntHashMap & right)
{
	IntHashMap result;
	for (int i = 0; i < M; i++)
	{
		int key = right.contain(get(i));
		if (key >= 0)
		{
			result.put(i, get(i));
		}
	}
	return result;
}

IntHashMap IntHashMap::operator/(IntHashMap & right)
{
	IntHashMap result;
	for (int i = 0; i < M; i++)
	{
		int key = right.contain(get(i));
		if (key < 0)
		{
			result.put(result.get_empty_key(), get(i));
		}
	}
	return result;
}

IntHashMap IntHashMap::operator+(IntHashMap & right)
{
	return (*this / right) | (right / *this);
}

IntHashMap IntHashMap::operator|(IntHashMap right)
{
	IntHashMap result;

	for (int i = 0; i < M; i++)
	{
		result.peek(get(i));
		result.peek(right.get(i));
	}
	return result;
}

int IntHashMap::contain(int value)
{
	for (int key = 0; key < M; key++)
	{
		if (value == get(key))
			return key;
	}
	return -1;
}

IntHashMap::~IntHashMap()
{
}

int IntHashMap::hash_func(int key)
{
	return (A*key + B) % M;
}

int IntHashMap::get_empty_key()
{
	for (int i = 0; i < M; i++)
	{
		if (get(i) == 0)
			return i;
	}
	return -1;
}

int IntHashMap::peek(int value)
{
	if (value != 0)
	{
		if (contain(value) < 0)
		{
			put(get_empty_key(), value);
			return 1;
		}
	}
	return 0;
}