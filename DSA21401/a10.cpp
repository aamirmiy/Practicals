//============================================================================
// Name        : 21401
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class deque
{ int a[10];
  int front,rear;

	public:
	deque(){
		front=-1;
		rear=-1;
	}

	void enqueueF(int);
	void dequeueF();
	void enqueueR(int);
	void dequeueR();
	void display();

};

void deque::enqueueR(int x)
{          if(rear==9)
		cout<<"\nOverflow"<<endl;
	else
	{
		if(front==-1)
		{
			front++;
			rear++;
			a[rear]=x;
		}
		else
		{	rear++;
			a[rear]=x;
		}
	}

}

void deque::dequeueF()
{ int y;
	if(front==-1)
		cout<<"\nUnderflow"<<endl;

	else
	{
		y=a[front];
		front++;
		cout<<"\nThe element removed from queue is "<<y;
	}

}

void deque::display()
{ int i;
	if(front>rear){
		cout<<"\nUnderflow";
	front=-1;
	rear=-1;
	}
	else{
	for(i=front;i<=rear;i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;

	}

}

void deque::enqueueF(int x)
{
int i;
	/*if(front==-1){
		rear++;
		front++;
		a[front]=x;
        }

	else if(rear=9){
		for(i=rear;i>front;i--){
			a[i+1]=a[i];
		}
		a[i]=x;
		rear++;
	*/
	if(front==0){

		if(rear==9)
			cout<<"\nEnqueueF not possible";
		else{
			for(i=rear;i>-1;i--){
				a[i+1]=a[i];
			}
			a[front]=x;
			rear++;

		}
	}
	else if(front==-1){
		front++;
		rear++;
		a[rear]=x;
	}
	else{
		front--;
		a[front]=x;
	}
}

void deque::dequeueR()
{int y;
	if(front==-1)
		cout<<"\nDequeue not possible";
	else{
		y=a[rear];
		rear--;
		cout<<"\nElement removed is "<<y;

	}
}

int main()
{
	deque q;
	int d,n,e;
	char ch;
	cout<<"\nEnter:\n"<<"1.EnqueueR \n"<<"2.DeleteF \n"<<"3.EnqueueF \n"<<"4.DequeueR \n"<<"5.Display\n";
	do
	{
		cout<<"\nEnter choice no."<< endl;
		cin>>n;
		switch(n)
		{
		case 1:
			cout<<"\nEnter no : "<<endl;
			cin>>d;
			q.enqueueR(d);
			break;
		case 2:
			q.dequeueF();
			break;
		case 3:
			cout<<"\nEnter no: "<<endl;
			cin>>e;
			q.enqueueF(e);
			break;
		case 4:
			q.dequeueR();
			break;
		case 5:
			q.display();
			break;
		default:
			cout<<"\nEntered wrong choice";
			break;
		}
	cout<<"\nDo you want to continue(y/n) ";
	cin>>ch;

	}while(ch=='y');
	return 0;

}

