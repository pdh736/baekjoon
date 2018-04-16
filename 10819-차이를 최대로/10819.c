#include <stdio.h>


int next_permutation(int size);
void sort(int size);
int ary[8];

int main() {
	int n;
	
	int sum=0;
	int p_sum=0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	sort(n);

	do {
		p_sum = 0;
		for (int i = 0; i < n-1; i = i ++)
			p_sum += (ary[i] - ary[i+1]);
		if (sum < p_sum)sum = p_sum;
	}
	while (next_permutation(n));
	
	printf("%d\n", sum);


	return 0;
}

int next_permutation(int size) {
	int i,j;
	int temp;
	i = size-1;
	while (i > 0 && (ary[i - 1] > ary[i])) i -= 1;
	if (i <= 0)return 0;
	j = size-1;
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
void sort(int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (ary[i] > ary[j]) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}