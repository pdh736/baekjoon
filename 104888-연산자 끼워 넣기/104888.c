#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int num[100];
int op[4];
int max = -1000000000;
int min = 1000000000;
int check[4];

int index = 0;
int pre;


void dfs(int x,int result) {
	check[x] += 1;
	//index++;
	pre = result;
	if(x==0 && op[x]!=0 )
		result += num[++index];
	else if(x==1 && op[x] != 0)
		result -= num[++index];
	else if (x == 2 && op[x] != 0)
		result *= num[++index];
	else if (x == 3 && op[x] != 0)
		result /= num[++index];
	if (index == n-1) {
		if (result > max)max = result;
		if (result < min)min = result;
	}
	for (int i = 0; i < 4; i++) {
		if (check[i] < op[i]) {
			dfs(i,result);
		}
	}
	check[x] -= 1;
	result = pre;
	index--;
}

int main() {
	FILE * fp = fopen("test.txt","r+");
	fscanf(fp, "%d", &n);
	
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		fscanf(fp, "%d", &op[i]);
	}

	dfs(0, num[0]);
	memset(check, 0, sizeof(check));
	index = 0;
	dfs(1, num[0]);
	memset(check, 0, sizeof(check));
	index = 0;
	dfs(2, num[0]);
	memset(check, 0, sizeof(check));
	index = 0;
	dfs(3, num[0]);
	printf("%d\n",max);
	printf("%d\n", min);
	return 0;
}