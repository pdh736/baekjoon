#include <stdio.h>
#include <math.h>

int index;
int check[13];
int temp[13];
int list[50][13];
int count;

int n,m;
int map[50][50];
int c_list[100][2];
int p_list[13][3];
int c_cnt;
int p_cnt;

int min1 = 30000;
int min2 = 30000;
int result;


void com(int x) {
	temp[index] = x;
	index++;
	check[x]=1;
	if (index == m) {
		for (int i = 0; i < m; i++) {
			list[count][i] = temp[i];
		}
		count++;
	}
	for (int i = x+1; i < c_cnt; i++) {
		if (check[i] == 0)
			com(i);
	}
	index--;
	check[x] = 0;
}

int main() {
	//int sum;
	//FILE * fp = fopen("test.txt","r");
	
	//fscanf(fp, "%d", &n);
	//fscanf(fp, "%d", &m);
	scanf("%d", &n);
	scanf("%d", &m);
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1) {
				p_list[p_cnt][0] = i;
				p_list[p_cnt][1] = j;
				p_list[p_cnt][2] = 100;
				p_cnt++;
			}

			if (map[i][j] == 2) {
				c_list[c_cnt][0] = i;
				c_list[c_cnt][1] = j;
				c_cnt++;
			}
		}
	}
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				p_list[p_cnt][0] = i;
				p_list[p_cnt][1] = j;
				p_list[p_cnt][2] = 100;
				p_cnt++;
			}

			if (map[i][j] == 2) {
				c_list[c_cnt][0] = i;
				c_list[c_cnt][1] = j;
				c_cnt++;
			}
		}
	}

	for (int i = 0; i <= c_cnt - m; i++) {
		com(i);
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < p_cnt; j++) {
			for (int k = 0; k <m; k++) {
				if (p_list[j][2] > abs(c_list[list[i][k]][0] - p_list[j][0]) + abs(c_list[list[i][k]][1] - p_list[j][1]))
					p_list[j][2] = abs(c_list[list[i][k]][0] - p_list[j][0]) + abs(c_list[list[i][k]][1] - p_list[j][1]);
			}
			result += p_list[j][2];
			p_list[j][2] = 100;
		}
		if (min1 > result)min1 = result;
		result = 0;
	}
	printf("%d\n", min1);
	
	//fclose(fp);
	return 0;
}


