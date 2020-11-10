extern void swap(int *, int *);

/* internal routines */
void _quick_sort(int *, int, int);
int _partition(int *, int, int);

void quick_sort(int *nums, int size) {
	_quick_sort(nums, 0, size - 1);
}

void _quick_sort(int *nums, int lo, int hi) {
	if (lo >= hi)
		return;

	int pivot_index = _partition(nums, lo, hi);

	_quick_sort(nums, lo, pivot_index - 1);
	_quick_sort(nums, pivot_index + 1, hi);
}

int _partition(int *nums, int lo, int hi) {
	int pivot = nums[hi];
	int i = lo - 1;

	for (int j = lo; j < hi; j++) {
		if (nums[j] < pivot)
			swap(nums + j, nums + ++i);
	}

	swap(nums + i + 1, nums + hi);

	return i + 1;
}