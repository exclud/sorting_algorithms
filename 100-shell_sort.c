#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1, i, j;
    int temp;

    if (array == NULL || size <= 1)
        return;

    /* Find the first interval using Knuth's formula (n+1 = n * 3 + 1) */
    while (interval < size)
        interval = interval * 3 + 1;

    /* Reduce the interval until it becomes 1 (i.e., normal insertion sort) */
    for (interval = (interval - 1) / 3; interval > 0; interval = (interval - 1) / 3)
    {
        /* Perform insertion sort for the current interval */
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= interval && array[j - interval] > temp)
            {
                array[j] = array[j - interval];
                j -= interval;
            }

            array[j] = temp;
        }

        /* Print the array after each interval decrease */
        print_array(array, size);
    }
}
