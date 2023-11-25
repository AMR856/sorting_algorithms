#include "sort.h"

void swapping(int *, int *);

/**
 * selection_sort - A function to sort elements using selection sort
 * @array: A pointer to an array of integers
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, myMin;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		myMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[myMin] > array[j])
				myMin = j;
			if (myMin != i)
			{
				swapping(&array[i], &array[myMin]);
				print_array(array, size);
			}
		}
	}
}

/* 1 9 4 5 7 */

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
