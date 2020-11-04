#include <stdlib.h>

/* internal routines */
static void _merge_sort(int *, int, int);
static void _merge(int *, int, int, int);
static void _copy(int *, int *, int);
static int* _get_memory(int);

void merge_sort(int *nums, int size) {
	_merge_sort(nums, 0, size - 1);
}

static void _merge_sort(int *nums, int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	_merge_sort(nums, left, mid);
	_merge_sort(nums, mid + 1, right);
	_merge(nums, left, mid, right);
}

static void _merge(int *nums, int left, int mid, int right) {
	int i = 0;
	int j = 0;
	int k = left;

	int n_one = mid - left + 1;
	int n_two = right - mid;

	int *one = _get_memory(n_one);
	int *two = _get_memory(n_two);

	_copy(nums + left, one, n_one);
	_copy(nums + mid + 1, two, n_two);

	while (i < n_one && j < n_two) {
		if (one[i] < two[j])
			nums[k] = one[i++];
		else
			nums[k] = two[j++];
		k++;
	}

	_copy(one, nums + k, n_one - i);
	_copy(two, nums + k, n_two - j);
}

static void _copy(int *src, int *dest, int count)  {
	for (int i = 0; i < count; i++)
		dest[i] = src[i];
}

static int* _get_memory(int size) {
	return malloc(sizeof(int) * size);
}