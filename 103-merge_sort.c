#include "sort.h"
#include "string.h"

/**
 * merge - merge two part of an array
 * @prmArray: array of int to sort
 * @prmStart: start of the array
 * @prmMiddle: middle of the array
 * @prmEnd: end of the array
 * Return: nothing void
 */
void merge(int *prmArray, int prmStart, int prmMiddle, int prmEnd)
{
	int cLoop1, cLoop2, cLoop3, cLoop4 = 0;
	int size1 = prmMiddle - prmStart + 1, size2 = prmEnd - prmMiddle;
	int tmp1[4096], tmp2[4096];
	int *tmp3 = malloc(sizeof(int) * (size1 + size2));

	for (cLoop1 = 0, cLoop2 = 0; cLoop1 < size1 || cLoop2 < size2; cLoop1++, cLoop2++)
	{
		tmp1[cLoop1] = prmArray[prmStart + cLoop1];
		tmp2[cLoop2] = prmArray[prmMiddle + 1 + cLoop2];
	}

	for (cLoop1 = cLoop2 = 0, cLoop3 = prmStart;
	     cLoop1 < size1 && cLoop2 < size2; cLoop3++)
		if (tmp1[cLoop1] <= tmp2[cLoop2])
			prmArray[cLoop3] = tmp3[cLoop4++] = tmp1[cLoop1++];
		else
			prmArray[cLoop3] = tmp3[cLoop4++] = tmp2[cLoop2++];

	printf("Merging...\n[left]: ");
	print_array(tmp1, size1);
	printf("[right]: ");
	print_array(tmp2, size2);

	while (cLoop1 < size1)
		prmArray[cLoop3++] = tmp3[cLoop4++] = tmp1[cLoop1++];

	while (cLoop2 < size2)
		prmArray[cLoop3++] = tmp3[cLoop4++] = tmp2[cLoop2++];

	printf("[Done]: ");
	print_array(tmp3, size1 + size2);

	free(tmp3);
}

/**
 * sort - sort the array then merge it recursively
 * @prmArray: array of int to sort
 * @prmStart: begin of the array
 * @prmEnd: end of the array
 * Return: nothing void
 */

void sort(int *prmArray, int prmStart, int prmEnd)
{
	int middle;

	if (prmStart < prmEnd)
	{
		middle = (prmStart + prmEnd - 1) / 2;
		sort(prmArray, prmStart, middle);
		sort(prmArray, middle + 1, prmEnd);
		merge(prmArray, prmStart, middle, prmEnd);
	}
}

/**
 * merge_sort - function that sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @prmArray: array of int to sort
 * @prmSize: size of the array
 * Return: nothing void
 */

void merge_sort(int *prmArray, size_t prmSize)
{
	if (prmArray == NULL || prmSize < 2)
		return;
	sort(prmArray, 0, prmSize - 1);
}
