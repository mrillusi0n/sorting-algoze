#include <stdlib.h>

extern int get_max(int *, int);

void counting_prefix_sort(int *nums, int size) {
	int counter_size = get_max(nums, size) + 1;

	int *counter = calloc(counter_size, sizeof(int));
	int *final = malloc(sizeof(int) * size);

	/* store frequencies */
	for (int i = 0; i < size; i++)
		counter[nums[i]]++;

	/* make the prefix sum */
	for (int i = 1; i < counter_size; i++)
		counter[i] += counter[i - 1];

	/* populate the final array */
	for (int i = size - 1; i >= 0; i--)
		final[counter[nums[i]]-- - 1] = nums[i];
	
	/* copy back into the input array */
	for (int i = 0; i < size; i++)
		nums[i] = final[i];
}

