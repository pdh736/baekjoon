#include <stdio.h.>

//int fac(int num);

int main() {
	int n;
	int num;
	int mode;
	int p[10];
	int per = 0;
	int count=0;
	int flag[10] = { 0 };
	int fac[10] = { 1 };
	
	scanf("%d", &n);
	scanf("%1d", &mode);

	for (int i = 1; i < n; i++) {
		fac[i] = fac[i - 1] * i;
	}	

	if (mode == 2) {
		for (int i = 0; i < n; i++) {
			scanf("%1d", &p[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (p[j] < p[i])count++;
			}
			per += (p[i]-1 -count) * fac[n - i -1];
			count = 0;
		}
		printf("%d", per +1 );
		
	}
	if (mode == 1) {
		scanf("%d", &num);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (flag[j])continue;
				if (num > fac[n - i - 1]) num -= fac[n - i - 1];
				else {
					p[i] = j;
					flag[j] = 1;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			printf("%d", p[i]);
		}
	}
	printf("\n");
	return 0;
}
/*
int fac(int num) {
	if (num <= 1)return 1;
	return num*fac(num-1);
}*/