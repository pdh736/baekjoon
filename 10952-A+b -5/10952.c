#include <stdio.h>

int main() {
	int num1, num2;

	while (1) {
		scanf("%1d %1d", &num1, &num2);
		if (!num1 && !num2)break;
		printf("%d\n", num1 + num2);
	}


	return 0;
}