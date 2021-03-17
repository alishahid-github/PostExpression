//Stack header file for integers
#include<iostream>
#include"LIst_Int.h"
#ifndef STACKK
#define STACKK
using namespace std;
class stack
{
private:
	list L1;
public:
	void push(int d);
	int pop();
	void print();
};


#endif
