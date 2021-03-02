//Header file for the Linked List with Basic funtions

#include<iostream>
#include"Node_Int.h"
#ifndef LISTT
#define LISTT
using namespace std;
class list {
public:
	list();
	void insertH(int d);		// d=data
	int delete_listH();
	void print();
	int search(int d);
	void set_head(node* h);
	node* get_head();		// usage will be in main on neeed base
	int node_count = 0;

private:
	node* head;

};

#endif
