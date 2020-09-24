void selection_sort(int *nums, int size) {
	for (int i = 0; i < size; i++) {
		int min_index = i;

		for (int j = i; j < size; j++) {
			if (nums[min_index] > nums[j])
				min_index = j;
		}

		int temp = nums[i];
		nums[i] = nums[min_index];
		nums[min_index] = temp;
	}
}