//============================================================================
// Name        : assignment12.cpp
// Author      : 21401
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int n,i,j,min;
	float temp;
cout<<"enter the number of students in class "<<endl;
cin>>n;
float a[n];
cout<<"enter the percentages of students "<<endl;
for(i=0;i<n;i++)
{
	cin>>a[i];
}
for(i=0;i<n;i++)//bubble sort
{
	for(j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		{   temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
}
cout<<"the sorted array is "<<endl;
for(i=0;i<n;i++)
{
	cout<<a[i]<<endl;
}
for(i=0;i<n-1;i++)//selection sort
{min=i;
	for(j=i+1;j<=n;j++)
	{
		{
			if(min>a[j])
			{
				 temp=min;
							min=a[j];
							a[j]=temp;
			}

		}
	}
}
cout<<"the sorted array is "<<endl;
for(i=0;i<n;i++)
{
	cout<<a[i]<<endl;
}
cout<<"the top four scores are "<<endl;
for(i=n-1;i>=n-4;i--)
{
	cout<<a[i]<<endl;
}
	return 0;
}
