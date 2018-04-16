#include <stdio.h>

int main() {
	int T, n;
	int cnt = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		cnt = 0;
		for (int a = 1; a <= 3; a++) {
			if ( a == n)cnt++;
			for (int b = 1; b <= 3; b++) {
				if ( a + b == n)cnt++;
				for (int c = 1; c <= 3; c++) {
					if ( a + b + c == n)cnt++;
					for (int d = 1; d <= 3; d++) {
						if ( a + b + c + d == n)cnt++;
						for (int e = 1; e <= 3; e++) {
							if ( a + b + c + d + e == n)cnt++;
							for (int f = 1; f <= 3; f++) {
								if ( a + b + c + d + e + f == n)cnt++;
								for (int g = 1; g <= 3; g++) {
									if (a + b + c + d + e + f + g == n)cnt++;
									for (int h = 1; h <= 3; h++) {
										if ( a + b + c + d + e + f + g + h == n)cnt++;
										for (int i = 1; i <= 3; i++) {
											if (a + b + c + d + e + f + g + h + i == n)cnt++;
											for (int j = 1; j <= 3; j++) {
												if ( a + b + c + d + e + f + g + h + i + j == n)cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}

	

	return 0;
}