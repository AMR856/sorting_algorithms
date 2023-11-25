#include "sort.h"

void myMerge(int *, int *, size_t, size_t);
void mergingEverything(int *, int*, size_t, size_t, size_t);

/**
 * merge_sort - A function to sort an array using merge sort
 * @array: A pointer to the array
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/
void merge_sort(int *array, size_t size)
{
	int *myCopyArray;

	if (array == NULL || size < 2)
		return;
	myCopyArray = (int *)malloc(sizeof(int) * size);
	myMerge(myCopyArray, array, 0, size);
	free(myCopyArray);
}

/**
 * myMerge - A function to be able to merge without their declaration
 * @myCopy: The copy of the function
 * @theMainArray: The array that is required to be sorted
 * @left: The left index of the array
 * @right: The upper right of the array
 *
 * Return: Nothing (void)
*/
void myMerge(int *myCopy, int *theMainArray, size_t left, size_t right)
{
	size_t theMiddle;

	if (right - left > 1)
	{
		theMiddle =  left + (right - left) / 2;
		myMerge(myCopy, theMainArray, left, theMiddle);
		myMerge(myCopy, theMainArray, theMiddle, right);
		mergingEverything(myCopy, theMainArray, left, theMiddle, right);
	}
}

/***
 * mergingEverything - A function to merge not just for calling other functions
 * @myC: The copy of the array
 * @tMO: The main array that is required to be sorted
 * @left: The left index of the array
 * @theMiddle: The middle of the array that we got above
 * @right: The ubber right of the array
 *
 * Return: Nothing (void)
*/

void mergingEverything(int *myC, int *tMO, size_t l, size_t theM, size_t r)
/*myC = myCopy -- tMo = theMainOne*/
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(tMO + l, theM - l);
	printf("[right]: ");
	print_array(tMO + theM, r - theM);

	for (i = l, j = theM; i < theM && j < r; k++)
	{
		if (tMO[i] < tMO[j])
		{
			myC[k] = tMO[i];
			i++;
		}
		else
		{
			myC[k] = tMO[j];
			j++;
		}
	}
	while (i < theM)
	{
		myC[k] = tMO[i];
		k++;
		i++;
	}
	while (j < r)
	{
		myC[k] = tMO[j];
		k++;
		j++;
	}
	for (k = l, i = 0; k < r; k++)
	{
		tMO[k] = myC[i];
		i++;
	}
	printf("[Done]: ");
	print_array(tMO + l, r - l);
}
