#include <stdlib.h>

extern int get_max(int *, int);

/* internal routines */
/* is there a way to use the existing `counting_sort`? */
void _counting_sort(int *, int, int, int *);

void radix_sort(int *nums, int size) {
	int max_val = get_max(nums, size);
	int *out = malloc(sizeof(int) * (size + 1));

	for (int place = 1; (max_val / place) > 0; place *= 10)
		_counting_sort(nums, size, place, out);
}
	
void _counting_sort(int *nums, int size, int place, int *out) {
	int count[10] = {0};

	/* frequencies */
	for (int i = 0; i < size; i++)
		count[(nums[i] / place) % 10]++;

	/* prefix sum */
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* populate the output */
	for (int i = size - 1; i >= 0; i--)
		out[count[(nums[i] / place) % 10]-- - 1] = nums[i];

	/* copy back to the input array */
	for (int i = 0; i < size; i++) {
		nums[i] = out[i];
	}
}