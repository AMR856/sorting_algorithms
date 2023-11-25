#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - A function to sort an array using counting sort
 * @array: A pointer to the array
 * @size: The size of the array
 *
 * Return: Nothing (void)
*/

void counting_sort(int *array, size_t size)
{
    int maxElement = -20000;
    int i, mySize = size;
    int *myCountArray;
    int *myOutputArray;

    for (i = 0; i < mySize; i++)
    {
        if (maxElement < array[i])
            maxElement = array[i];
    }
    myCountArray = (int *)malloc((maxElement + 1) * sizeof(int));
    if (myCountArray == NULL)
        return;
    for (i = 0; i <= maxElement; i++)
        myCountArray[i] = 0;
    for (i = 0; i < mySize; i++)
        myCountArray[array[i]]++;
    for (i = 1; i <= maxElement; i++)
        myCountArray[i] += myCountArray[i - 1];
    print_array(myCountArray, maxElement + 1);
    myOutputArray = (int *)malloc((mySize + 1) * sizeof(int));
    for (i = mySize - 1; i >= 0; i--)
    {
        myOutputArray[myCountArray[array[i]] - 1] = array[i];
        myCountArray[array[i]]--;
    }
    for (i = 0; i < mySize; i++)
        array[i] = myOutputArray[i];
    free(myCountArray);
    free(myOutputArray);
}
