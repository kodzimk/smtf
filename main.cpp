#include<iostream>
#include"shared_ptr.h"

template<class T>
shared_ptr<T>* shared_ptr<T>::helper = nullptr;

int main()
{

	shared_ptr<int> a(1);
	shared_ptr<int>b(a);
	shared_ptr<int>c(a);
	
	shared_ptr<int> k(c);
	c.set(4);
	

	return 0;
}