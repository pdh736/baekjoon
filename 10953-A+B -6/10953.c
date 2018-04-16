#include <stdio.h>

int main() {
	int t;
	int num1, num2;
	char comma;

	scanf("%d", &t);
	while (t--) {
		scanf("%1d", &num1);
		scanf("%1c", &comma);
		scanf("%1d", &num2);
		printf("%d\n", num1 + num2);
	}
}