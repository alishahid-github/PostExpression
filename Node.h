//A node class which creates the nodes for the Post Expression along basic getter and setter functions

#include<iostream>
using namespace std;
#ifndef NODE
#define NODE
class Node
{
public:
	Node();
	Node(char d);			// d=data
	void set_data(char d);
	void set_next(Node* n);		// n=next
	void set_prev(Node* p);		// p=prev
	char get_data();
	Node* get_next();
	Node* get_prev();
private:
	char data;
	Node* next;
	Node* prev;

};

#endif


