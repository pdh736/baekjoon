#include <stdio.h>

#define MAX 1001

int map[MAX][MAX];
int check[MAX][MAX];
int q[MAX][2];


int main() {
	int m, n;
	int front = 0, rear = 0;
	int x, y;
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	int flag = 1;
	int day=0;

	FILE * fp = fopen("test.txt","r");

	fscanf(fp,"%d",&m);
	fscanf(fp,"%d",&n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j]==1){
				q[rear][0] = j;
				q[rear++][1] = i;
				check[i][j] = 1;
			}
			else if (map[i][j]==0) flag = 0;
		}
	}

	if (flag) {
		printf("0\n");
		return 0;
	}

	while (front < rear) {
		x = q[front][0];
		y = q[front++][1];
		for (int k = 0; k < 4; k++) {
			if (x + dx[k] >= 0 && y + dy[k] >= 0 && x+dx[k]<m && y+dy[k]<n) {
				if (map[y + dy[k]][x + dx[k]] == 0 && check[y + dy[k]][x + dx[k]] == 0) {
					//map[y + dy[k]][x + dx[k]] = 1;
					check[y + dy[k]][x + dx[k]] = check[y][x] + 1;
					q[rear][0] = x + dx[k];
					q[rear++][1] = y + dy[k];
				}
			}
		}
	}
	flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0 && map[i][j]!=-1) {
				flag = 0;
				break;
			}
			else {
				if (day < check[i][j])day = check[i][j];
			}
		}
	}
	if (flag)
		printf("%d\n", day-1);
	else
		printf("-1\n");

	fclose(fp);
	return 0;
}