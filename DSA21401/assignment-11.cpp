//============================================================================
// Name        : assignment-11.cpp
// Author      : 21401
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{int n,i,j=0,r,count=0,last;
cout<<"enter no. of students in class"<<endl;
cin>>n;
int a[n];
cout<<"enter the roll numbers of students"<<endl;
for(i=0;i<n;i++)
{
	cin>>a[i];
}
cout<<"enter roll no. to be searched"<<endl;
cin>>r;
for(i=0;i<n;i++)
{
	if(r==a[i])
	{count++;
		break;}
}
if(count==1)
{
	cout<<"the student was present"<<endl;
}else
{
	cout<<"the student was absent"<<endl;
}
//sentinel search
last=a[n-1];
a[n-1]=r;
while(a[j]!=r)
{
	j++;
}
a[n-1]=last;
if((r==a[n-1])||j<(n-1))
		{
			cout<<"element is found";
		}
		else
		{
			cout<<"element is not found";
		}
	return 0;
}
