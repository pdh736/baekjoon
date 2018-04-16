#include <stdio.h>
#include <stdlib.h>

int main() {
	int * p;
	int n;
	int i , j ;
	int temp;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int)*n);

	for (int k = 0; k < n; k++)scanf("%1d",&p[k]);

	i = n - 1;

	while (i > 0 && p[i - 1] < p[i])i -= 1;
	if (i <= 0) {
		printf("-1");
		return 0;
	}
	j = n - 1;
	while (p[j] > p[i - 1]) j -= 1;
	temp = p[j];
	p[j] = p[i - 1];
	p[i - 1] = temp;

	j = n - 1;

	while (j > i) {
		temp = p[i];
		p[i] = p[j];
		p[j] = temp;
		i++;
		j--;
	}

	for (int k = 0; k < n; k++)printf("%1d", p[k]);

	return 0;
}