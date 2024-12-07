#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRUE 0
#define FALSE 1


int circle_size;

int num_array[100];
int num_array_idx;

uint64_t iteratio_cnt = 0;

void
print_num_array()
{
	for (int i = 0; i < num_array_idx; i++) {
		printf("%d ", num_array[i]);
	}

	printf("\n");
}

int
is_present(int n)
{
	for (int i = 0; i < num_array_idx; i++) {
		if (n == num_array[i])
			return TRUE;
	}

	return FALSE;
}

int
is_square(int n)
{
static int square_array[] = {4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 0};
int square_array_size;

	square_array_size = sizeof(square_array);

	for (int i = 0; ; i++) {
		if (square_array[i] == 0)
			return FALSE;

		if (n == square_array[i])
			return TRUE;

		if (square_array[i] > n)
			return FALSE;
	}

	return FALSE;
}

int
add_number()
{
int last_number;

	if (num_array_idx >= circle_size) {
		if (is_square(num_array[0] + num_array[circle_size - 1]) == FALSE)
			return FALSE;

		printf("\nSUCCESS!!\n\nMagic Circle is\n");
		print_num_array();
		return TRUE;
	}

	last_number = num_array[num_array_idx - 1];

	for (int i = 1; i <= circle_size; i++) {
		if (is_square(last_number + i) == FALSE)
			continue;

		if (is_present(i) == TRUE)
			continue;

		num_array[num_array_idx] = i;
		num_array_idx++;
		iteratio_cnt++;
		if ((iteratio_cnt % 10000000) == 0) {
			print_num_array();
			fflush(stdout);
		}

		if (add_number() == TRUE) {
			return TRUE;
		}

		num_array_idx--;
	}

	return FALSE;
}

int
main()
{
	for (int i = 55; i <= 64; i++) {
		circle_size = i;

		num_array[0] = circle_size;
		num_array_idx = 1;
		if (add_number() == FALSE)
			printf("\nCould not find Magic Circle\n");

		fflush(stdout);
	}
}

