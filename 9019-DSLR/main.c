#include <stdio.h>
#include <string.h>

int q[10001];
char code[10001];
int check[10001];
int previous[10001];

int main() {

	int T;
	int A, B;
	int front = 0, rear = 0;
	int now;
	int next;
	int i;

	scanf("%d", &T);
	while (T--) {

		scanf("%d %d", &A, &B);

		memset(check, 0, sizeof(check));
		memset(code, 0, sizeof(code));
		memset(previous, 0, sizeof(previous));

		q[rear++] = A;
		check[A] = 1;
		previous[A] = 0;

		while (front < rear) {
			now = q[front++];

			next = now * 2;
			if (next > 9999) next = next % 10000;
			if (check[next] == 0) {
				q[rear++] = next;
				check[next] = 1;
				code[next] = 'D';
				previous[next] = now;
			}
			next = now - 1;
			if (next == 0)next = 9999;
			if (check[next] == 0) {
				q[rear++] = next;
				check[next] = 1;
				code[next] = 'S';
				previous[next] = now;
			}
			next = ((now % 1000) * 10) + (now / 1000);
			if (check[next] == 0) {
				q[rear++] = next;
				check[next] = 1;
				code[next] = 'L';
				previous[next] = now;
			}
			next = ((now % 10) * 1000) + (now / 10);
			if (check[next] == 0) {
				q[rear++] = next;
				check[next] = 1;
				code[next] = 'R';
				previous[next] = now;
			}
		}
		i = B;

		while (previous[i]) {
			printf("%c", code[i]);
			i = previous[i];
		}
		printf("\n");
	}

	return 0;
}