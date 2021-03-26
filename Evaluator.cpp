//Implementation File of Evaluator.h

#include "Evaluator.h"
#include "Stack_Int.h"

char* Evaluator::expression(string expression)
{
	char* new_expres=new char[expression.length()];

	for (unsigned int i = 0; i < expression.length(); i++)
	{
		if ((expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= 'a' && expression[i] <= 'z'))
		{
			new_expres[exp_count] = expression[i];
			exp_count++;
		}
		else if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[' || 
		         expression[i] == '*' || expression[i] == '/')
		{
			mystack.push(expression[i]);
		}

		else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
		{
		bool chk = true;   /*  this is used to chk whether the current character is or not the closing bracket 
							   and the loop will run and pop all the stack elements untill the closing bracket
							not found  */
			while (chk)
			{
				char res = mystack.pop();
				if (res == '(' || res == '{' || res == '[' || res == '@')
					chk = false;
				else
				{
					chk = true;
					new_expres[exp_count++] = res;
				}
			}
		}

		else if (expression[i] == '+' || expression[i] == '-')
		{
		again:				// this is used for checking that next upcoming also not of higher precidence.
			char temp = mystack.get_Latest();
			if (temp == '*' || temp == '/')
			{
				new_expres[exp_count++] = mystack.pop();
				goto again;
			}
			else
				mystack.push(expression[i]);
		}
		else
			cout << "Invalid input";
	}
	char temp = mystack.pop();
	while (temp != '@')
	{
		new_expres[exp_count++] = temp;
		temp = mystack.pop();
	}

	return new_expres;
}

int Evaluator::result(char* express)
{
	int i = 0;
	stack temp;
	for(; ;i++)
	{
		if ((express[i] >= 'A' && express[i] <= 'Z') || (express[i] >= 'a' && express[i] <= 'z') || 
		     express[i] == '+' || express[i] == '-' || express[i] == '*' || express[i] == '/' )
		{
			if (express[i] != '+' && express[i] != '-' && express[i] != '*' && express[i] != '/')
			{
				cout << "Enter the value of " << express[i] << ": ";
				int n; cin >> n;
				temp.push(n);
			}
			else if (express[i] == '+')
			{
				int n1, n2, res = 0;
				n2 = temp.pop();
				n1 = temp.pop();
				res = n1 + n2;
				temp.push(res);
			}
			else if (express[i] == '-')
			{
				int n1, n2, res = 0;
				n2 = temp.pop();
				n1 = temp.pop();
				res = n1 - n2;
				temp.push(res);
			}
			else if (express[i] == '*')
			{
				int n1, n2, res = 0;
				n2 = temp.pop();
				n1 = temp.pop();
				res = n1 * n2;
				temp.push(res);
			}
			else if (express[i] == '/')
			{
				int n1, n2, res = 0;
				n2 = temp.pop();
				n1 = temp.pop();
				res = n1 / n2;
				temp.push(res);
			}
			else
			{
				continue;
			}
		}
			
		else
			return temp.pop();
	}
}
