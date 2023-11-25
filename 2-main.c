#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {20, 19, 18, 17, 16};
    selection_sort(array, 5);
    print_array(array, 5);
    return 0;
}