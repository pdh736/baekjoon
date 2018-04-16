#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char op [10];
	int num;
	int set = 0;

	scanf("%d",&n);
	while (n--) {
		scanf("%s", op);
		
		if (!strcmp(op, "add")) {
			scanf("%d", &num);
			set |= (1 << num - 1);
		}

		else if (!strcmp(op, "remove")) {
			scanf("%d", &num);
			set &= ~(1<< num-1);
		}

		else if (!strcmp(op, "check")) {
			scanf("%d", &num);
			if ( (set & (1 << num - 1) ) == (1 << num - 1))printf("1\n");
			else printf("0\n");
		}

		else if (!strcmp(op, "toggle")) {
			scanf("%d", &num);
			set ^= (1<<num-1);
		}

		else if (!strcmp(op, "all")) {
			scanf("%d", &num);
			set = (1<<20)-1;
		}

		else if (!strcmp(op, "empty")) {
			scanf("%d", &num);
			set =0;
		}
	}
	return 0;
}

