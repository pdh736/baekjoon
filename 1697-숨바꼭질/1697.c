#include <stdio.h>

#define MAX 200000

int check[MAX];
int dist[MAX];
int q[MAX];

int main() {
	int n, k;
	
	int front = 0, rear = 0;
	int x;


	scanf("%d %d", &n, &k);

	q[rear] = n;
	rear++;
	check[n] = 1;
	dist[n] = 0;

	while (front < rear) {
		x=q[front];
		front++;
		if (x - 1 >= 0 && check[x-1]==0) {
			q[rear] = x - 1;
			rear++;
			check[x - 1] = 1;
			dist[x - 1] = dist[x] + 1;
		}

		if (x + 1 <= MAX && check[x + 1] == 0) {
			q[rear] = x + 1;
			rear++;
			check[x + 1] = 1;
			dist[x + 1] = dist[x] + 1;
		}


		if (2 * x <= MAX && check[2 * x] == 0) {
			q[rear] = x * 2;
			rear++;
			check[2 * x] = 1;
			dist[2 * x] = dist[x] + 1;
		}
		
	}

	printf("%d\n", dist[k]);
	return 0;
}