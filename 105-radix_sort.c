#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

/**
 * radix_sort - Sort an array of integers in ascending order using the LSD
 * radix sort algorithm
 *
 * @array: The array of integers to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int *bucket[10], *tmp;
    size_t i, j, digit, max_digits, divisor;

    if (array == NULL || size < 2)
        return;

    max_digits = 0;
    for (i = 0; i < size; i++) {
        digit = 0;
        while (array[i] > 0) {
            array[i] /= 10;
            digit++;
        }
        if (digit > max_digits)
            max_digits = digit;
    }

    divisor = 1;
    for (i = 0; i < max_digits; i++) {
        memset(bucket, 0, sizeof(bucket));
        for (j = 0; j < size; j++) {
            digit = (array[j] / divisor) % 10;
            if (bucket[digit] == NULL) {
                bucket[digit] = malloc(size * sizeof(int));
                if (bucket[digit] == NULL) {
                    for (digit = 0; digit < 10; digit++)
                        free(bucket[digit]);
                    return;
                }
            }
            bucket[digit][bucket[digit][0] + 1] = array[j];
            bucket[digit][0]++;
        }
        tmp = array;
        for (j = 0; j < 10; j++) {
            if (bucket[j] != NULL) {
                memcpy(tmp, &bucket[j][1], bucket[j][0] * sizeof(int));
                tmp += bucket[j][0];
                free(bucket[j]);
            }
        }
        divisor *= 10;
        print_array(array, size);
    }
}
