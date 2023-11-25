#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high)
{
  //choose the pivot
	
	int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
	int i=(low-1);
	/*
	int arr[]={10,7,8,9,1,5};
	pivot = 5 arr[5]
	i = -1
	j = 0 -> 5 -> ++
	i = 0
	{1, 7, 8, 9, 10, 5}
	-
	-
	-
	{1, 5, 8, 9, 10, 7}
	{8, 9, 10 ,7}
	pivot = 7
	i = 1
	-
	-
	-
	{7, 9, 10, 8}
	*/
	for(int j=low;j<=high;j++)
	{
	//If current element is smaller than the pivot
	if(arr[j]<pivot)
	{
	  //Increment index of smaller element
	i++;
	swap(arr[i],arr[j]);
	}
}
	swap(arr[i+1],arr[high]);
	return (i+1);
}

// The Quicksort function Implement
		
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
	if(low<high)
	{
	// pi is the partition return index of pivot

	int pi=partition(arr,low,high);

	//Recursion Call
	//smaller element than pivot goes left and
	//higher element goes right
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);
}
}

int main() {
	int arr[]={10,7,8,9,1,5};
	int n=sizeof(arr)/sizeof(arr[0]);
  // Function call
	quickSort(arr,0,n-1);
  //Print the sorted array
	cout<<"Sorted Array\n";
	for(int i=0;i<n;i++)
	{
	cout<<arr[i]<<" ";
	}
	return 0;
}
// This Code is Contributed By Diwakar Jha