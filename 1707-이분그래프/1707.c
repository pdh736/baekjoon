#include <stdio.h>

int k, v, e;
int check[20000];
int map[20000][20000];

int dfs(int x) {
	check[x] += 1;
	for (int i = 0; i <= v; i++) {
		if (check[x] < 3 && map[x][i])
			dfs(i);
	}
}

int main() {
	int a, b;
	int flag=0;

	scanf("%d", &k);
	while (k--) {
		memset(check,0,sizeof(check));

		scanf("%d %d", &v, &e);
		while (e--) {
			scanf("%d %d", &a, &b);
			map[a][b] = 1;
		}

		dfs(1);

		for (int i = 0; i <= v; i++) {
			if (check[i] == 2) {
				flag = 1;
				break;
			}
		}
		if (flag)printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}