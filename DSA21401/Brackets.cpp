//============================================================================
// Name        : Brackets.cpp
// Author      : 21401
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
using namespace std;

class stack_
{
	char stack[10];  //stack is created using array
	int top;
public:
	stack_() :top(-1) {} //initialization of top using constructor

	void push(char x)  //push function to insert element in stack
	{
		if (top == 9)
			cout << "overflow";
		else
		{
			top++;
			stack[top] = x;
		}
	}

	char pop() //pop function to remove the element from stack
	{
		if (top != -1)
		{

			return(stack[top--]);

		}
		else
			cout << "underflow";

	}

	bool is_empty() //is_empty function to check whether the stack is empty or not
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool is_full() //is_full function to check whether the stack is full or not
	{
		if (top == 9)
			return true;
		else
			return false;
	}

	bool balence(string ex) // main logic starts from here
	{
		int j = 0;
		char c[10];
		for (int i = 0; i < ex.size(); i++)
		{
			if (ex[i] == '(' || ex[i] == '{' || ex[i] == '[')
				push(ex[i]);
			else if (ex[i] == ')' || ex[i] == '}' || ex[i] == ']')
			{
				if (is_empty() || !pair(stack[top], ex[i]))
					return false;
				else
				{

					c[j] = pop();
					j++;
				}
			}
		}
		for (int i = 0; i < j; i++)
		{
			cout << c[i];
		}
		for (int i = j - 1; i >= 0; i--)
		{
			if (c[i] == '(')
				cout << ")";
			else if (c[i] == '[')
				cout << "]";
			else if (c[i] == '{')
				cout << "}";
		}
		cout << endl;
		return is_empty() ? true : false;
	}


	bool pair(char ope, char cls)
	{
		if (ope == '(' && cls == ')')
			return true;
		else if (ope == '[' && cls == ']')
			return true;
		else if (ope == '{' && cls == '}')
			return true;
		return false;
	}

};

int main()
{
	stack_ o;
	bool b;
	int m;
	string s;
	cout << "\n\n Enter the expression : " ;
	cin >> s;
	b = o.balence(s);
	if (b == true)
		cout << "expression is well parenthesised\n";
	else
		cout << "expression is not well parenthesised\n";
	return 0;
}
