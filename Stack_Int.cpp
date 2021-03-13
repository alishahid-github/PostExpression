#include "Stack_Int.h"
#include "Node_Int.h"

void stack::push(int d)
{
	L1.insertH(d);
}

int stack::pop()
{
	return L1.delete_listH();
}

void stack::print()
{
	if (L1.get_head() == NULL)
		cout << "\nStack is empty";
	else
	{
		node* temp = L1.get_head();
		while(temp != NULL)
		{ 
			cout << "\tvalue is = "<<temp->get_data();
			temp = temp->get_next();
		}
	}
}
