#include "sort.h"

void myQuickSort(int *, int, int, size_t);
int partition(int *, int, int, size_t);
void swapping(int *, int *);

/**
 * quick_sort - A function to sort the array using quick sort
 * @array: A pointer to the array
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;
	myQuickSort(array, 0, size - 1, size);
}

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

int partition(int *myArray, int low, int high, size_t mySize)
{
	int pivot, i, j;

	pivot = myArray[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (myArray[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swapping(&myArray[i], &myArray[j]);
				print_array(myArray, mySize);
			}
		}
	}
	swapping(&myArray[i + 1], &myArray[high]);
	print_array(myArray, mySize);
	return (i + 1);
}

void swapping(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
