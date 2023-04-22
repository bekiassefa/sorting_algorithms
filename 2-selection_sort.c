#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @prmArray: pointer to the array of int to sort
 * @prmSize: size of the array
 * Return: nothing void
 */

void selection_sort(int *prmArray, size_t prmSize)
{
	size_t cLoop1, cLoop2, cLoopMin;
	int tmp, *array = prmArray;

	if (prmArray == NULL || prmSize < 2)
		return;

	for (cLoop1 = 0; cLoop1 < prmSize; cLoop1++)
	{
		cLoopMin = cLoop1;
		for (cLoop2 = cLoop1; cLoop2 < prmSize; cLoop2++)
			if (array[cLoop2] < array[cLoopMin])
				cLoopMin = cLoop2;
		tmp = prmArray[cLoop1];
		array[cLoop1] = prmArray[cLoopMin];
		array[cLoopMin] = tmp;
		if (cLoopMin != cLoop1)
			print_array(array, prmSize);
	}
}
