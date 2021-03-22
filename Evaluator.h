
#include"Node.h"
#include"List.h"
#include"Stack.h"
using namespace std;

class Evaluator
{
public:
	Stack mystack;
	int exp_count = 0;

	char* expression(string);
	int result(char*);
};

