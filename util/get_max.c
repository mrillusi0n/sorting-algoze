int get_max(int *nums, int size) {
	int max_val = nums[0];

	for (int i = 1; i < size; i++)
		if (nums[i] > max_val)
			max_val = nums[i];

	return max_val;
}
