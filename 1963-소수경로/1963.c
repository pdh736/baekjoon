#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

int prime[MAX+1];
int check[MAX+1];
int q[MAX+1];

int change(int num,int index, int change_num) {
	char temp[5];
	if (index == 0 && change_num == 0)	return 0;
	itoa(num, temp, 10);
	temp[index] = change_num+'0';
	return atoi(temp);
}

int main() {
	int front = 0, rear = 0;
	int T, p1, p2;
	int dist[MAX];
	int temp;
	int next;

	scanf("%d", &T);

	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) {
			for (int j = i + i; j < MAX; j += i) {
				prime[j] = 1;
			}
		}
	}
	
	while (T--) {
		memset(dist, 0, MAX);
		memset(check, 0, MAX);
		
		scanf("%d", &p1);
		scanf("%d", &p2);

		q[rear++] = p1;
		dist[p1] = 0;
		check[p1] = 1;
	
		while (front < rear) {
			temp = q[front++];
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					next = change(temp, i, j);
					if ((next != 0) && (check[next] == 0) && prime[next] == 0) {
						q[rear++] = next;
						check[next] = 1;
						dist[next] = dist[temp] + 1;
					}

				}
			}
		}
		printf("%d\n", dist[p2]);
	}
	return 0;
}