//============================================================================
// Name        : assignment.cpp
// Author      : 21401
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <bits/stdc++.h>
using namespace std;

void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}


int partition (float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
       return (i + 1);
   }


   void quickSort(float arr[], int low, int high)
   {
       if (low < high)
       {
           int pi = partition(arr, low, high);
           quickSort(arr, low, pi - 1);
           quickSort(arr, pi + 1, high);
       }
   }
   void printArray(float arr[], int size)
   {
       int i;
       for (i = 0; i < size; i++)
           cout << arr[i] << " ";
       cout << endl;
   }
   int main()
   {
	   int n;
	   cout<<"enter size of array"<<endl;
	   cin>>n;
	   float arr[n];
	   cout<<"enter elemnets"<<endl;
	   for(int i=0;i<n;i++)
	   {
		   cin>>arr[i];
	   }
	   quickSort(arr, 0, n - 1);
	          cout << "Sorted array: \n";
	          printArray(arr, n);
	          return 0;
   }

  /* int main()
   {
       float arr[] = {10.5, 7.5, 8.5, 9.5, 1.5, 5.5};
       int n = sizeof(arr) / sizeof(arr[0]);
       quickSort(arr, 0, n - 1);
       cout << "Sorted array: \n";
       printArray(arr, n);
       return 0;
   }*/
