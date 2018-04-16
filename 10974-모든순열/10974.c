#include <stdio.h>
#include <stdlib.h>

int next_permutation();

int n, i, j;
int * p;

int main() {
	scanf("%d", &n);

	p = (int*)malloc(sizeof(int)*n);

	for (int k = 0; k < n; k++) {
		p[k] = k + 1;
	}

	do {
		for (int k = 0; k < n; k++) {
			printf("%d", p[k]);
		}
		printf("\n");
	} while (next_permutation()>0);

	return 0;
}

int next_permutation() {
	int temp;
	i = n - 1;
	while (i>0 && p[i - 1]>p[i])	i -= 1;
	if (i <= 0)return -1;

	j = n - 1;
	while (p[j] < p[i - 1]) j -= 1;

	temp = p[i - 1];
	p[i - 1] = p[j];
	p[j] = temp;

	j = n - 1;
	while (j > i) {
		temp = p[i];
		p[i] = p[j];
		p[j] = temp;
		i++; j--;
	}
	return 1;
}