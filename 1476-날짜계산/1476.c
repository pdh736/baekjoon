#include <stdio.h>

int main() {
	int year = 1;
	int e, s, m;
	int c_e = 1, c_s = 1, c_m = 1;
	int flag = 0;

	scanf("%d %d %d", &e, &s, &m);
	while (!flag) {
		if (e == c_e) {
			if (s == c_s) {
				if (m == c_m) {
					printf("%d", year);
					flag = 1;
				}
			}
		}
		c_e++;
		c_s++;
		c_m++;
		if (c_e == 16)c_e = 1;
		if (c_s == 29)c_s = 1;
		if (c_m == 20)c_m = 1;
		year++;
	}

	return 0;
}