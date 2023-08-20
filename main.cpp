#include<iostream>
#include"shared_ptr.h"
#include"twowaylinkedlist.h"
#include<string>

int main()
{

	TLinkedList<int> a(1);
	a.push_front(2);
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a.at(i) << " ";
	}
	return 0;
}