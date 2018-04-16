#include <stdio.h>
#include <string.h>

#define MAX 10

int n;
int map[MAX][MAX];
int check[MAX];
int min = (1 << 31) - 1;
int index;
int distance;
int start;

void dfs(int x, int pre) {
	check[x] = 1;
	distance += map[pre][x];
	index++;
	if (index == n) {
		distance += map[x][start];
		if (min > distance)min = distance;
		distance -= map[x][start];
	}
	for (int i = 0; i < n; i++) {
		if (map[x][i] != 0 && check[i] == 0) {
			dfs(i, x);
		}
	}
	check[x] = 0;
	index--;
	distance -= map[pre][x];
}

int main() {
	FILE * fp = fopen("test.txt", "r");

	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		start = i;
		memset(check,0,sizeof(check));
		index=0;
		dfs(start,0);
	}

	printf("%d\n",min);

	return 0;
}