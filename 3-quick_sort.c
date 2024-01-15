#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * @size: size of the array
 * Return: void
 */

void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
    int p;

    if (lo < hi)
    {
        p = partition(array, lo, hi, size);
        quick_sort_helper(array, lo, p - 1, size);
        quick_sort_helper(array, p + 1, hi, size);
    }
}

/**
 * partition - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * @size: size of the array
 * Return: void
 */

int partition(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi];
    int i = lo - 1, j, temp;

    for (j = lo; j <= hi - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[hi];
    array[hi] = temp;
    if (i + 1 != hi)
        print_array(array, size);
    return (i + 1);
}