#include <stdio.h>

int main() {
	int n;
	int num;
	int sum = 0;

	scanf("%d", &n);

	while (n--) {
		scanf("%1d", &num);
		sum += num;
	}
	printf("%d\n", sum);
	
	return 0;
}