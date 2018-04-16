#include <stdio.h>
#include <stdlib.h>

int main() {
	int t;
	int *permutation;
	int i = -1, j = 0;
	int temp;

	scanf("%d",&t);
	permutation = (int*)malloc(sizeof(int)*t);

	for (int k = 0; k < t; k++)scanf("%1d", &permutation[k]);

	for (int k = 1; k < t; k++) {
		if (permutation[k - 1] < permutation[k])	i = k;	
	}
	if (i == -1) {
		printf("-1\n");
		return 0;
	}
	for (int k = i; k < t; k++) {
		if (permutation[k] > permutation[i - 1])	j = k;
	}
	temp = permutation[i-1];
	permutation[i-1] = permutation[j];
	permutation[j] = temp;
	for (int k = 0; k < (t-i)/2 ; k++){
		temp=permutation[i+k];
		permutation[i+k] = permutation[t-1-k];
		permutation[t - 1 - k] = temp;
	}
	for (int k = 0; k < t; k++) {
		printf("%1d", permutation[k]);
	}
	printf("\n");

	return 0;
}