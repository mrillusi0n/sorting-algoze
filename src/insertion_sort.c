extern void swap(int *, int *);

void insertion_sort(int *nums, int size) {
	for (int i = 1; i < size; i++) {
		int curr = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > curr) {
			nums[j + 1] = nums[j];
			j--;
		}

		nums[j + 1] = curr;
	}
}