#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * Return: nothing void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: pointer to the array to sort
 * @low: start of the array
 * @high: end of the array
 * @size: size of the array
 * Return: nothing void
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition(array, low, high, size);
		quicksort(array, low, index - 1, size);
		quicksort(array, index + 1, high, size);
	}
}

/**
 * swap - function that swap value
 * @a: pointer to the first value
 * @b: pointer to the second value
 * Return: nothing void
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - function that partition an array of int
 * and swap the value
 * @array: array to partition
 * @low: beggining of the array
 * @high: end of the array
 * @size: size of the array
 * Return: returns the nwes index oh the value
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}
