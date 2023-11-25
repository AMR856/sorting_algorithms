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
	int i, j, myGap;
	int myTemp;

	if (size < 2)
		return;
	while ((myGap = myGap * 3 + 1) < size)
	;
	myGap = (myGap - 1) / 3;
	for (; myGap > 0; myGap = (myGap - 1) / 3)
	{
		for (i = 0; i < size; i++)
		{
			myTemp = array[i];
			for (j = 1; j >= myGap && myTemp <= array[j - myGap]; j = j - myGap)
				array[j] = array[j - myGap];
			array[j] = myTemp;
		}
		print_array(array, size);
	}
}
