#include "sort.h"

void swapping(int *, int *);

/**
 * bubble_sort - a function to sort using bubble sort
 * @array: A pointer to an array of integers
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool isSwapped;

	for (i = 0; i < size; i++)
	{
		isSwapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapping(&array[j], &array[j + 1]);
				print_array(array, size);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			break;
	}
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
