//============================================================================
// Name        : Icecream.cpp
// Author      :21401
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<stdlib.h>
#include<iostream>


using namespace std;
class node
{
	int data;
	node* next;

public:
	node* createnode();
	void print(node*);
	int uni(node* , node* );
	int inter(node* , node* );
	void sub1(node*, node* );
	void sub2(node*, node*);

};
node* node::createnode()
{
	int n, i;
	node* p, * head, * t;
	head = NULL;
	cout<<"\n\n\nenter the no of students:\n\n\n";
	cin>>n;
	for (i = 0; i < n; i++)
	{
		p = new node;
		cout<<"\n\n\nenter the students  roll numbers: ";
		cin>>p->data;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
		{
			t = head;
			while (t->next != NULL)
				t = t->next;
			t->next = p;
		}
	}
	return head;
}
void node::print(node* head)
{
	node* p;
	int cnt = 0;
	p = head;
	while (p != NULL)
	{
		cout<< p->data<<"\n\n";
		p = p->next;
		cnt++;
	}
	cout<<"\n\n\ntotal no of students="<< cnt<<"\n\n";
}
int node::uni(node* head, node* head1)
{
	node* p, * q;
	int found = 0, count = 0;
	p = head;



	for (p = head; p != NULL; p = p->next)
	{
		found = 0;
		for (q = head1; q != NULL; q = q->next)
		{
			if (p->data == q->data)
			{
				found = 1;
				break;
			}
		}
		if (found != 1)
		{
			cout << p->data << "\n\n";
			count++;
		}
	}

	for (q = head1; q != NULL; q = q->next)
	{found = 0;
		for (p = head; p != NULL; p = p->next)
		{
			if (p->data == q->data)
			{
				found = 1;
				break;
			}
		}
		if (found != 1)
		{
			cout << q->data << "\n\n";
			count++;
		}
	}


	return count;
}
int node::inter(node* head1, node* head2)
{
	node* p, * q;
	int found = 0;
	int cnt = 0;
	for (q = head2; q != NULL; q = q->next)
	{
		found = 0;
		for (p = head1; p != NULL; p = p->next)
		{
			if (q->data == p->data)
			{
				found = 1;
				break;
			}
		}
		if (found == 1)
		{
			cout<<"\n\n"<<q->data << "\n\n";
			cnt++;
		}
	}
	return cnt;
}
void node::sub1(node* head1, node* head2)
{
	node* p, * q;
	int found = 0;

	for (p = head1; p != NULL; p = p->next)
	{
		found = 0;
		for (q = head2; q != NULL; q = q->next)
		{
			if (p->data == q->data)
			{
				found = 1;
				break;
			}
		}
		if (found != 1)
		{
			cout << "\n\n"<<p->data << "\n\n";

		}
	}
}
void node::sub2(node* head1, node* head2)
{
	node* p, * q;
	int found = 0;

	for (q = head2; q != NULL; q = q->next)
	{
		found = 0;
		for (p = head1; p != NULL; p = p->next)
		{
			if (p->data == q->data)
			{
				found = 1;
				break;
			}
		}
		if (found != 1)
		{
			cout << "\n\n" <<q->data << "\n\n";

		}
	}
}
int main()
{
	node x,y;
	node* head, * head1;
	int ch = 0, a,m, count;
	head = head1 = NULL;

	cout<<"\n\n\nenter the no of students";
	cin >> m;
	head = NULL;
	while (ch != 8)
	{
		cout<<"\n **************************************";
		cout<<"\n 1]create";
		cout<<"\n 2]print";
		cout << "\n 3]students like either vanilla or butterscotch";
		cout << "\n 4]students like both vanilla & butterscotch";
		cout << "\n 5]students like vanilla only";
		cout << "\n 6]students like only butterscotch";
		cout << "\n 7]number of students liking neither vanilla nor butterscotch";
		cout << "enter your choice" << "\n\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n\n\nstudents like vanilla" << "\n\n";
			head = x.createnode();
			cout << "\n\n\nstudents like butterscotch"<<"\n\n";
			head1 = y.createnode();
			break;


		case 2:
			cout << "\n\n\nstudents like vanilla";
			x.print(head);
			cout << "\n\n\nstudents like butter scotch";
			y.print(head1);
			break;

		case 3:
			cout << "\n \n\n\nstudents like atleast vanilla or butterscotch :";
			count = x.uni(head, head1);
			cout << "\n\n Count is" << count;
			break;
		case 4:"\n\n Students like both vanilla & butterscotch";
			a=x.inter(head, head1);
			break;
		case 5:
			cout << "\n students like vanilla only";
			x.sub1(head, head1);
			break;
		case 6:
			cout << "\n students like butterscotch only";
			x.sub2(head, head1);
			break;
		case 7:
			cout << "\n students like neither vanilla nor butterscotch="<<(( m - count)+a);

			break;
		}
	}
	return 0;
}
