/********************************
 * Author: theteachr
 *******************************/

#include <stdio.h>
#include <string.h>
#include "sort_functions.h"

void print_arr(int *, int);
typedef void (*sort_function)(int *, int);

void (*SORT_FUNCTIONS[])(int *, int) = {
	bubble_sort,
	selection_sort,
	insertion_sort,
	merge_sort,
	quick_sort,
	bucket_sort,
	counting_sort,
	radix_sort
};

int NUM_FUNCTIONS = 8;

char *SORT_FUNCTION_NAMES[] = {
	"bubble_sort",
	"selection_sort",
	"insertion_sort",
	"merge_sort",
	"quick_sort",
	"bucket_sort",
	"counting_sort",
	"radix_sort"
};

int test_sorter(sort_function sort, char *func_name) {
	int scores[] = {8, 12, 4, 1, 19, 19, 15, 17};
	int scores_sorted[] = {1, 4, 8, 12, 15, 17, 19, 19};
	int num_scores = 8;
	int flag = 1;
	
	char *statuses[] = {"✘", "✔"};

	sort(scores, num_scores);

	for (int i = 0; flag && (i < num_scores); i++)
		flag &= (scores[i] == scores_sorted[i]);

	printf("%s %s\n", statuses[flag], func_name);

	return flag;
}

int main(int argc, char const *argv[]) {
	for (int i = 0; i < NUM_FUNCTIONS; i++)
		test_sorter(SORT_FUNCTIONS[i], SORT_FUNCTION_NAMES[i]);

	return 0;
}

void print_arr(int *nums, int size)
{
	printf("[");
	for (int i = 0; i < size - 1; i++)
		printf("%d, ", nums[i]);
	if (size > 0) printf("%d", nums[size - 1]);
	printf("]");
}