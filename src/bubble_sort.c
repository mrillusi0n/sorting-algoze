#include "util.h"

void bubble_sort(int *nums, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums + j, nums + j + 1);
			}
		}
	}
}