include<unordered_map>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<class T>
class Hash {
public:
	T value;
	int hashIndex;

	Hash()
	{
		hashIndex = -1;
	}
	Hash(int index, T value)
	{
		this->value = value;
		hashIndex = index;
	}
};

template<class T>
class HashTable {
public:
	int lengthOfEachRef[10];
	Hash<T>** refTo;

	int size = 0;
	int capacity = 0;

	HashTable(int index, T value)
	{

		refTo = new Hash<T>*[10];
		for (int i = 0; i < 10; i++)
		{
			lengthOfEachRef[i] = 0;
			refTo[i] = new Hash<T>[0];
		}

		capacity = 10;
		int result = index % capacity;
		Hash<T> a(index, value);
		refTo[result][lengthOfEachRef[result]].value = a.value;
		refTo[result][lengthOfEachRef[result]].hashIndex = a.hashIndex;
		lengthOfEachRef[result]++;
	}

	HashTable()
	{
		refTo = new vector<Hash<T>>*[10];
		for (int i = 0; i < 10; i++)
		{
			lengthOfEachRef[i] = 0;
			refTo[i] = new Hash<T>[0];
		}
		capacity = 10;
	}

	void insert(int index, T value)
	{
		int result = index % capacity;

	}

	~HashTable()
	{
		if (refTo != nullptr)
		{
			delete[]refTo;
		}
	}

	T at(int index)
	{
		int result = index % capacity;
		if (lengthOfEachRef[result] > 1)
		{

			for (int i = 0; i < lengthOfEachRef[result]; i++)
			{
				Hash<T> hashIndex = { refTo[result][i] };
				if (hashIndex.hashIndex == index)
				{
					Hash<T> value = { refTo[result][i] };
					return value.value;
				}
			}
		}
		else
		{
			Hash<T> hash = { *refTo[result] };
			return hash.value;
		}
	}

	void Add(int index, T value)
	{
		int result = index % capacity;

		refTo[result][lengthOfEachRef[result]].value = value;
		refTo[result][lengthOfEachRef[result]].hashIndex = index;
		lengthOfEachRef[result]++;

	}

	void Remove(int index, T value)
	{
		int result = index % capacity;
		if (lengthOfEachRef[result] <= 1)
		{
			refTo[result][lengthOfEachRef[result - 1]].value = -444444;
			refTo[result][lengthOfEachRef[result - 1]].hashIndex = -1;
		}
		else
		{
			for (int i = 0; i < lengthOfEachRef[result]; i++)
			{
				if (refTo[result][i].value == value && refTo[result][i].hashIndex == index)
				{
					refTo[result][lengthOfEachRef[i]].value = -444444;
					refTo[result][lengthOfEachRef[i]].hashIndex = -1;
					return;
				}
			}
		}
	}
};

int main()
{

	HashTable<int> table(2, 4);
	cout << "First: " << table.at(2) << endl;
	table.Add(12, 5);
	cout << "Second" << table.at(12);
	table.Add(22, 10);
	cout << "Third" << table.at(22);
	table.Add(1, 6);
	cout << "Four: " << table.at(1);
	table.Remove(1, 6);
	cout << "Four: " << table.at(1);

	return 0;
}