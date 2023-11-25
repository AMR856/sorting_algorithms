#include "sort.h"

void myQuickSort(int *, int, int, size_t);
int partition(int *, int, int, size_t);
void swapping(int *, int *);

/**
 * quick_sort - A function to sort the array (useless)
 * @array: A pointer to the array
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	myQuickSort(array, 0, size - 1, size);
}

/**
 * myQuickSort - This is the function to quick sort the array
 * @myArray: A pointer to an array of integers
 * @lower: The lower bound of the array
 * @higher: The higher bound of the array
 * @mySize: the size of the array
 * Return: Nothing (void)
*/

void myQuickSort(int *myArray, int lower, int higher, size_t mySize)
{
	int piIndex;

	if (lower < higher)
	{
		piIndex = partition(myArray, lower, higher, mySize);
		myQuickSort(myArray, lower, piIndex - 1, mySize);
		myQuickSort(myArray, piIndex + 1, higher, mySize);
	}
}

/**
 * partition - all the partitiong job is done here
 * @myArray: A pointer to the array
 * @low: the lower bound of the array
 * @high: the higher bound of the array
 * @mySize: the size of the array
 * Return: The index of the pivot in its correct position
*/

int partition(int *myArray, int low, int high, size_t mySize)
{
	int myPivot, i, j;

	myPivot = myArray[high];
	i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (myPivot >= myArray[j])
		{
			i++;
			swapping(&myArray[i], &myArray[j]);
			print_array(myArray, mySize);
		}
	}
	swapping(&myArray[i + 1], &myArray[high]);
	print_array(myArray, mySize);
	return (i + 1);
}

/**
 * swapping - A function to swap elements
 * @right: A pointer to the right element
 * @left: A pointer to the left element
 *
 * Return: Nothing
*/

void swapping(int *right, int *left)
{
	int temp;

	temp = *right;
	*right = *left;
	*left = temp;
}
