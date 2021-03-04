//.cpp file to implement the Liked List class

#include<iostream>
#include"LIst_Int.h"
using namespace std;

list::list()
{
	head = NULL;
}

node* list::get_head() 
{
	return head; 
}
void  list::set_head(node* h)
{ 
	head = h; 
}

void list::print() {

	node* temp = head;		//traverse the head to nodes...
	while (temp != NULL) {
		cout << "The  List value= " << temp->get_data() << endl;
		temp = temp->get_next();
	}

}


int list::search(int d) {

	node* temp = head;
	int i = 0;
	if (temp == NULL)
		return -1;
	else
	{
		if (head->get_data() == d)
			return i;
	}
	while (temp->get_data() != d)
	{
		if (temp->get_next() == NULL)
			return -1;
		else
		{
			i++;
			temp = temp->get_next();
		}
	}
	return i;
}

void list::insertH(int d)
{
	node* new_node = new node(d);
	new_node->set_next(head);
	head = new_node;
}

int list::delete_listH()
{
	int data = -1;
	if (head != NULL)
	{
		data =head->get_data();
		head = head->get_next();
		return data;
	}
		
	else
		return data;
}



