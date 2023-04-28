#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * merge - Merges two sorted sub-arrays into a single sorted array
 * @array: Array containing sub-arrays to be merged
 * @left: Left index of the first sub-array
 * @middle: Middle index of the array
 * @right: Right index of the second sub-array
 */
void merge(int *array, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Allocate memory for temporary left and right sub-arrays
    int *left_arr = (int *) malloc(n1 * sizeof(int));
    int *right_arr = (int *) malloc(n2 * sizeof(int));

    // Copy data from main array to temporary left and right sub-arrays
    for (i = 0; i < n1; i++)
        left_arr[i] = array[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = array[middle + 1 + j];

    // Merge the left and right sub-arrays into the main array
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            array[k] = left_arr[i];
            i++;
        } else {
            array[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_arr, if there are any
    while (i < n1) {
        array[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_arr, if there are any
    while (j < n2) {
        array[k] = right_arr[j];
        j++;
        k++;
    }

    // Free the memory allocated for temporary left and right sub-arrays
    free(left_arr);
    free(right_arr);
}

/**
 * merge_sort_helper - Sorts the given array using the merge sort algorithm
 * @array: Array to be sorted
 * @left: Left index of the array
 * @right: Right index of the array
 */
void merge_sort_helper(int *array, int left, int right)
{
    if (left < right) {
        int middle = (left + right) / 2;

        // Sort the left half of the array
        merge_sort_helper(array, left, middle);

        // Sort the right half of the array
        merge_sort_helper(array, middle + 1, right);

        // Merge the two sorted halves of the array
        merge(array, left, middle, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    // Call the helper function to sort the array
    merge_sort_helper(array, 0, size - 1);
}
