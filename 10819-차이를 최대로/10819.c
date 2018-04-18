#include <stdio.h>
#include <math.h>

int next_permutation(int size);
int ary[8];

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n;

	int sum = 0;
	int p_sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	qsort(ary, n, sizeof(int), compare);

	do {
		p_sum = 0;
		for (int i = 0; i < n - 1; i = i++)
			p_sum += abs(ary[i] - ary[i + 1]);
		if (sum < p_sum)sum = p_sum;
	} while (next_permutation(n));

	printf("%d\n", sum);

	return 0;
}

int next_permutation(int size) {
	int i, j;
	int temp;
	i = size - 1;
	while (i > 0 && (ary[i - 1] > ary[i])) i -= 1;
	if (i <= 0)return 0;
	j = size - 1;
	while (ary[j] < ary[i - 1])j -= 1;
	temp = ary[j];
	ary[j] = ary[i - 1];
	ary[i - 1] = temp;
	j = size - 1;
	while (j > i) {
		temp = ary[j];
		ary[j] = ary[i];
		ary[i] = temp;
		i++; j--;
	}
	return 1;
}

