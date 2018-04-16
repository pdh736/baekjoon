#include <stdio.h>

int main() {
	char st[100];
	while (1) {
		fgets(st,100,stdin);
		printf("%s", st);
	}
	return 0;
}