#include <stdio.h>
#include <string.h>
int n, m, v;
int check[1001];
int map[1001][1001];


void dfs(int x) {
	check[x] = 1;
	printf("%d ", x);
	for (int i = 0; i <= n; i++) {
		if (check[i] == 0 && map[x][i] == 1)
			dfs(i);
	}
}

void bfs(int x) {
	int q[1001];
	int front = 0, rear = 0;
	int now;
	q[rear++] = x;
	check[x] = 1;
	
	while (front < rear) {
		now = q[front++];
		printf("%d ", now);
		for (int i = 0; i <= n; i++) {
			if (check[i] == 0 && map[now][i]) {
				q[rear++] = i;
				check[i] = 1;
			}
		}
	}
}

int main() {
	int a, b;
	scanf("%d %d %d", &n, &m, &v);

	while (m--) {
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}
	dfs(v);
	memset(check,0,sizeof(check));
	printf("\n");
	bfs(v);
	printf("\n");
	return 0;
}