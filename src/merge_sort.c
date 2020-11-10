/* internal routines */
static void _merge_sort(int *, int, int);
static void _merge(int *, int, int, int);
static void _copy(int *, int *, int);

void merge_sort(int *nums, int size) {
	_merge_sort(nums, 0, size - 1);
}

static void _merge_sort(int *nums, int left, int right) {
	if (left == right)
		return;

	int mid = left + (right - left) / 2;
	_merge_sort(nums, left, mid);
	_merge_sort(nums, mid + 1, right);
	_merge(nums, left, mid, right);
}

static void _merge(int *nums, int left, int mid, int right) {
	int i = 0, j = 0, k = left;

	int n_one = mid - left + 1;
	int n_two = right - mid;

	int left_arr[n_one], right_arr[n_two];

	_copy(nums + left, left_arr, n_one);
	_copy(nums + mid + 1, right_arr, n_two);


	while (i < n_one && j < n_two) {
		if (left_arr[i] < right_arr[j])
			nums[k] = left_arr[i++];
		else
			nums[k] = right_arr[j++];
		k++;
	}

	_copy(left_arr + i, nums + k, n_one - i);
	_copy(right_arr + j, nums + k, n_two - j);
}

static void _copy(int *src, int *dest, int count)  {
	for (int i = 0; i < count; i++)
		dest[i] = src[i];
}
