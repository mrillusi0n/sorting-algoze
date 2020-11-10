#include <stdlib.h>

extern int get_max(int *, int);

void counting_sort(int *nums, int size) {
	int counter_size = get_max(nums, size) + 1;

	int *counter = calloc(counter_size, sizeof(int));
	int *final = malloc(sizeof(int) * size);

	/* store frequencies */
	for (int i = 0; i < size; i++)
		counter[nums[i]]++;

	/* fill the final array */
	for (int i = 0, f = 0; i < counter_size; i++) {
		while (counter[i]) {
			final[f++] = i;
			counter[i]--;
		}
	}
	
	/* copy into the input array */
	for (int i = 0; i < size; i++)
		nums[i] = final[i];
}