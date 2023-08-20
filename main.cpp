#include <iostream>
#include<vector>
#include<list>
#include<stack>
#include<functional>
#include<algorithm>
#include<set>
#include<fstream>
#include<Windows.h>
#include<forward_list>
#include<array>
#include<deque>
#include"shared_ptr.h"


using namespace std;

template<typename string, typename T>
class Directory;

template<typename string, typename T>
class Directory
{

private:
	vector<T>values;
	vector<string>names;

public:
	int length = 0;

	string Names_Of_Hash(const int index)
	{
		return names[index];
	}

	int size()
	{
		return length;
	}

	void add_from_front(string name, T value)
	{
		length++;
		names.push_front(name);
		names.push_front(value);
	}

	void add_from_back(string name, T value)
	{
		length++;
		names.push_back(name);
		values.push_back(value);
	}

	T Find_Value(T value)
	{
		int i = 0;
		for (auto iterator : value)
		{
			if (value == iterator)
			{
				return values[i];
			}
			i++;
		}
		return NULL;
	}

	T Find_Name(string name)
	{
		int i = 0;
		for (auto iterator : names)
		{
			if (iterator == name)
			{
				return values[i];
			}
			i++;
		}
		return NULL;
	}

	T operator[](const int index)
	{
		return values[index];
	}

	void Clear()
	{
		length = 0;
		names.clear();
		values.clear();
	}

	T begin()
	{
		return values[0];
	}

	T end()
	{
		return values[length - 1];
	}

	T at(const int index)
	{
		return values[index];
	}

	void operator = (Directory listHash)
	{
		values.clear();
		names.clear();
		for (int i = 0; i < listHash.length; i++)
		{
			values.push_back(listHash.at(i));
			names.push_back(listHash.Names_Of_Hash(i));
		}
		length = listHash.length;
	}
};

template<typename T>
class Stack {
public:
	vector<T> arrayRef;

	T operator()()
	{
		return arrayRef.at(arrayRef.size() - 1);
	}

	void add(T value)
	{
		arrayRef.push_back(value);
	}
	void remove()
	{
		if (arrayRef.size() >= 2)
			arrayRef.pop_back();
	}
	int size()
	{
		return arrayRef.size();
	}
};

template<typename T>
class LinkedList {
public:
	int size = 0;
	T** arrayRef;
	T* refToNextData;
	int currentIndexOfref = 0;

public:
	LinkedList()
	{
		arrayRef = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arrayRef[i] = new T[1];

		}
		for (int i = 0; i < size; i++)
		{
			arrayRef[i][0] = 0;

		}
		refToNextData = arrayRef[0];
	}
	~LinkedList()
	{
		for (int i = 0; i < size; i++)
		{
			refToNextData = arrayRef[i];
			delete[] refToNextData;
		}
		delete[] arrayRef;
	}

	void push_back(T value)
	{
		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];
			delete[]arrayRef[i];
		}
		delete[]arrayRef;

		size++;
		arrayRef = new int* [size];
		size--;
		for (int i = 0; i <= size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{

			arrayRef[i][0] = a[i];
		}
		arrayRef[size][0] = value;
		size++;
		refToNextData = arrayRef[0];
		delete[]a;
	}

	void push_front(T value)
	{
		T* a = new T[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];
			delete[]arrayRef[i];
		}
		delete[]arrayRef;

		size++;
		arrayRef = new int* [size];
		size--;
		for (int i = 0; i <= size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			if (i != 0)
				arrayRef[i][0] = a[i];
		}
		arrayRef[0][0] = value;
		refToNextData = arrayRef[0];
		size++;
		delete[]a;
	}

	void to_next()
	{

		if (size >= currentIndexOfref + 1)
		{
			currentIndexOfref++;
			refToNextData = arrayRef[currentIndexOfref];
		}
		else if (currentIndexOfref + 1 == size)
		{
			currentIndexOfref = 0;
			refToNextData = arrayRef[currentIndexOfref];
		}
		else
			cout << "Niger shit stupid Alkash" << endl;
	}

	T take_data()
	{
		if (size > currentIndexOfref)
		{
			T value = { *refToNextData };
			return value;
		}

	}

	void pop_front()
	{

		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];

			delete[]arrayRef[i];
		}
		delete[]arrayRef;

		size--;
		arrayRef = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			if (i != 0)
				arrayRef[i][0] = a[i];
		}
		delete[]a;
		refToNextData = arrayRef[0];
	}

	void pop_back()
	{
		size--;
		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];

			delete[]arrayRef[i];
		}
		delete[]arrayRef;


		arrayRef = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			arrayRef[i][0] = a[i];
		}
		delete[]a;
		refToNextData = arrayRef[0];
	}
};

template<typename T>
class TWLinkedList {
public:
	int size = 0;
	T** arrayRef;
	T* refToNextData;
	int currentIndexOfref = 0;

public:
	TWLinkedList()
	{
		arrayRef = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arrayRef[i] = new T[1];

		}
		for (int i = 0; i < size; i++)
		{
			arrayRef[i][0] = 0;

		}
		refToNextData = arrayRef[0];
	}
	~TWLinkedList()
	{
		for (int i = 0; i < size; i++)
		{
			refToNextData = arrayRef[i];
			delete[] refToNextData;
		}
		delete[] arrayRef;
	}

	void push_back(T value)
	{
		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];
			delete[]arrayRef[i];
		}
		delete[]arrayRef;

		size++;
		arrayRef = new int* [size];
		size--;
		for (int i = 0; i <= size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{

			arrayRef[i][0] = a[i];
		}
		arrayRef[size][0] = value;
		size++;
		refToNextData = arrayRef[0];
		delete[]a;
	}

	void push_front(T value)
	{
		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];
			delete[]arrayRef[i];
		}
		delete[]arrayRef;

		size++;
		arrayRef = new int* [size];
		size--;
		for (int i = 0; i <= size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			if (i != 0)
				arrayRef[i][0] = a[i];
		}
		arrayRef[0][0] = value;
		refToNextData = arrayRef[0];
		size++;
		delete[]a;
	}

	void to_next()
	{

		if (size >= currentIndexOfref + 1)
		{
			currentIndexOfref++;
			refToNextData = arrayRef[currentIndexOfref];
		}
		else if (currentIndexOfref + 1 == size)
		{
			currentIndexOfref = 0;
			refToNextData = arrayRef[currentIndexOfref];
		}
		else
			cout << "Niger shit stupid Alkash" << endl;
	}

	void to_previous()
	{
		if (currentIndexOfref != 0)
		{
			currentIndexOfref--;
			refToNextData = arrayRef[currentIndexOfref];
		}
	}

	T take_data()
	{
		if (size > currentIndexOfref)
		{
			T value = { *refToNextData };
			return value;
		}

	}

	void pop_front()
	{

		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];

			delete[]arrayRef[i];
		}
		delete[]arrayRef;

		size--;
		arrayRef = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			if (i != 0)
				arrayRef[i][0] = a[i];
		}
		delete[]a;
		refToNextData = arrayRef[0];
	}

	void pop_back()
	{
		size--;
		T* a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = arrayRef[i][0];

			delete[]arrayRef[i];
		}
		delete[]arrayRef;


		arrayRef = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arrayRef[i] = new T[1];
			arrayRef[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			arrayRef[i][0] = a[i];
		}
		delete[]a;
		refToNextData = arrayRef[0];
	}
};

template<typename T>
class Stack_WP
{
	T** refArray;
	int size = 0;

public:
	Stack_WP()
	{
		refArray = new T * [size];
		for (int i = 0; i < size; i++)
		{
			refArray[i] = new T[1];
		}
	}
	Stack_WP(T value)
	{
		size++;
		refArray = new T * [size];

		for (size_t i = 0; i < size; i++)
		{
			refArray[i] = new T[1];
		}
		refArray[0][0] = value;
	}
	~Stack_WP()
	{
		for (int i = 0; i < this->size; i++)
		{
			delete[] refArray[i];
		}
		delete[]refArray;
	}

	void add(T value)
	{
		size++;
		T*a = new int[size];
		
		for (int i = 0; i < size-1; i++)
		{
			a[i] = refArray[i][0];
		
		}
		for (size_t i = 0; i < size-1; i++)
		{
			delete[]refArray[i];
		}
		delete[]refArray;

		refArray = new int* [size];
		for (int i = 0; i < size; i++)
		{
			refArray[i] = new T[1];
			refArray[i][0] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			if (i != 0)
				refArray[i][0] = a[i];
		}
		refArray[0][0] = value;
	
		refArray = sort(refArray, size, value);
		delete[]a;

	}
	void remove()
	{
		size--;
		T** newArray = new T*[size];

		for (int i = 0; i < size; i++)
		{
			newArray[i][0] = refArray[i][0];
		}

		for (int i = 0; i < size + 1; i++)
		{
			delete[]refArray[i];
		}

		delete[]refArray;

		refArray = new T * [size];

		for (int i = 0; i < size; i++)
		{
			refArray[i] = new T[size];
			refArray[i][0] = newArray[i][0];
			newArray[i] = 0;
			delete[]newArray[i];
		}

		delete[]newArray;

	}
	T last()
	{
		T* ref = refArray[size - 1];
		return {*ref};
	}

private:
	T** sort(T** newAray, int size, T value)
	{
		int valueOf = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != 0 && newAray[i - 1][0] > newAray[i][0])
			{
				valueOf = newAray[i][0];
				newAray[i][0] = value;
				newAray[i - 1][0] = valueOf;
			}

		}
		return newAray;
	}
};

int main()
{
	Stack_WP<int> a;
	a.add(3);
	a.add(2);
	
	std::cout << a.last();
	
	std::cout << a.last();
	return 0;
}