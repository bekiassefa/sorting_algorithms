#include "sort.h"
/**
* quick_sort_hoare - function that sorts an array of integers
* in ascending order using the Quick sort algorithm
* @array: pointer to the array to sort
* @size: size of the array
* Return: nothing void
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}

/**
* quicksort_hoare - function that sorts an array of integers
* in ascending order using the Quick sort algorithm
* @array: pointer to the array to sort
* @low: start of the array
* @high: end of the array
* @size: size of the array
* Return: nothing void
*/
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition_hoare(array, low, high, size);
		quicksort_hoare(array, low, index - 1, size);
		quicksort_hoare(array, index, high, size);
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
* partition_hoare - function that partition an array of int
* and swap the value
* @array: array to partition
* @low: beggining of the array
* @high: end of the array
* @size: size of the array
* Return: returns the nwes index oh the value
*/
int partition_hoare(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i += 1;
		} while (array[i] < pivot);
		do {
			j -= 1;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (0);
}
