#include <stdio.h>

int main() {
	char st[101];
	int i;
	fgets(st, 101, stdin);
	i = 0;
	while (st[i]!='\n') {
		printf("%c", st[i]);
		if ((i + 1) % 10 == 0)printf("\n");
		i++;
	}
	printf("\n");	
	return 0;
}