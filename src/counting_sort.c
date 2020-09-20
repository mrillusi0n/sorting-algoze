#include <stdlib.h>

void print_arr(int *, int);

static int get_max_val(int *nums, int size)
{
	int max_val = nums[0];

	for (int i = 0; i < size; i++)
		max_val = (max_val < nums[i]) ? nums[i] : max_val;

	return max_val;
}

void counting_sort(int *nums, int size)
{
	int counter_size = get_max_val(nums, size) + 1;
	int *counter = calloc(counter_size, sizeof(int));
	int *final = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		counter[nums[i]]++;

	for (int i = 0, f = 0; i < counter_size; i++)
	{
		while (counter[i])
		{
			final[f++] = i;
			counter[i]--;
		}
	}
	
	for (int i = 0; i < size; i++)
		nums[i] = final[i];
}