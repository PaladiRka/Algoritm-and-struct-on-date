#include "HashMapSequence.h"



HashMapSequence::HashMapSequence()
{
	memset(numbers, -1, 1000 * sizeof(int));
}

void HashMapSequence::put(int key, int value)
{
	
	IntHashMap::put(key, value);

	numbers[currentNumber] = key;
	currentNumber++;
}

int HashMapSequence::get(int number)
{
	return numbers[number] == -1 ? 0 : IntHashMap::get(numbers[number]);
}

int HashMapSequence::rand_value()
{
	return (rand() * 5) % 32 + 1;
}

void HashMapSequence::set(int number, int value)
{
	IntHashMap::put(numbers[number], value);
}

HashMapSequence HashMapSequence::EXCL(HashMapSequence & right)
{
	HashMapSequence result;
	for (int i = 0; i < currentNumber; i++)
		if (get(i) == right.get(0))
		{
			for (int j = 0; j < right.getCurrent(); j++, i++)
				if (!(get(i) == right.get(j)))
				{
					i -= j;
					result.put(numbers[i], get(i));
					break;
				}
			i--;
		}
		else
			result.put(numbers[i], get(i));
	return result;
}

HashMapSequence HashMapSequence::ERASE(int p1, int p2)
{
	HashMapSequence result;
	for (int i = 0; i < p1; i++)
		result.put(numbers[i], get(i));
	for (int i = p2 + 1; i < currentNumber; i++)
		result.put(numbers[i], get(i));
	return result;
}

void HashMapSequence::CHANGE(HashMapSequence & right, int p1)
{
	for(int i = p1; i < (p1 + right.getCurrent()); i++)
		set(i, right.get(i - p1));

}

HashMapSequence::~HashMapSequence()
{
}
