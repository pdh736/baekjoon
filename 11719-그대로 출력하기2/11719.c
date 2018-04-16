#include <stdio.h>

int main() {
	char st[101];
	int i = 0;
	while (i < 10) {
		fgets(st, 101, stdin);
		printf("%s", st);
		i++;
	}
	return 0;
}