#include <stdio.h>
#include <string.h>

int k;
int ary[51];
int index;
int check[51];
int temp[6];
int list[30][6];
int count;

void dfs(int x) {
	temp[index] = ary[x];
	index++;
	check[x]=1;
	if (index == 6) {
		for (int i = 0; i < 6; i++) {
			list[count][i] = temp[i];
		}
		count++;
	}
	for (int i = x+1; i < k; i++) {
		if (check[i] == 0)
			dfs(i);
	}
	index--;
	check[x] = 0;
}

int main() {

	FILE * fp = fopen("test.txt","r");
	
	while (1) {
		fscanf(fp, "%d", &k);
		if (k == 0)break;
		for (int i = 0; i < k; i++) {
			fscanf(fp, "%d", &ary[i]);
		}
		index = 0;
		count = 0;
		memset(list,0,sizeof(list));
		for (int i = 0; i <= k - 6; i++) {
			dfs(i);
		}
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < 6; j++) {
				printf("%d ", list[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	fclose(fp);
	return 0;
}