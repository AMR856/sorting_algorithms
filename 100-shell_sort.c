#include "sort.h"

/**
 * shell_sort - A function to sort the array using shell sort
 * @array: A pointer to the head of the array
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t myGap;
	int myTemp;

	if (size < 2)
		return;

	myGap = 1;
	while (myGap < size)
		myGap = myGap * 3 + 1;
	myGap = (myGap - 1) / 3;

	for (; myGap > 0; myGap = (myGap - 1) / 3)
	{
		for (i = myGap; i < size; i++)
		{
			myTemp = array[i];
			for (j = i; j >= myGap && myTemp < array[j - myGap]; j -= myGap)
				array[j] = array[j - myGap];
			array[j] = myTemp;
		}
		print_array((const int *)array, size);
	}
}