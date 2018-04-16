#include <stdio.h>
#include <string.h>
int t, k;
int magnet[4][8];
//int direction = 1;
int ary[20][2];
int state[4];

void rotate(int n,int dir) {
	int temp;
	if (dir == 1) {
		temp = magnet[n][0];
		for (int j = 7; j>0; j--) {
			if (j == 7)magnet[n][0] = magnet[n][j];
			else magnet[n][j + 1] = magnet[n][j];
		}
		magnet[n][1] = temp;
	}
	else if(dir==-1) {
		temp = magnet[n][7];
		for (int j = 0; j<8; j++) {
			if (j == 0)magnet[n][7] = magnet[n][j];
			else magnet[n][j - 1] = magnet[n][j];
		}
		magnet[n][6] = temp;
	}

}

int main() {
	int q[10];
	int front , rear;
	int temp;
	int result;

	
	FILE *fp = fopen("test.txt", "r");

	fscanf(fp,"%d",&k);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			fscanf(fp, "%d", &magnet[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2; j++) {
			fscanf(fp, "%d", &ary[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {

		memset(state,0,sizeof(state));
		memset(q, 0, sizeof(q));
		front = 0; rear = 0;
		q[rear++] = ary[i][0]-1;
		state[ary[i][0]-1] = ary[i][1];

		while (front < rear) {
			temp = q[front++];
			if (temp != 3 && magnet[temp][2] != magnet[temp +1][6] && state[temp +1] == 0) {
				if (state[temp] == 1)
					state[temp + 1] = -1;
				else if (state[temp] == -1)
					state[temp + 1] = 1;
				else
					state[temp +1] = 2;
				q[rear++] = temp + 1;
			}
			if (temp != 0 && magnet[temp][6] != magnet[temp - 1][2] && state[temp - 1] == 0) {
				if (state[temp] == 1)
					state[temp - 1] = -1;
				else if (state[temp] == -1)
					state[temp - 1] = 1;
				else
					state[temp - 1] = 2;
				q[rear++] = temp - 1;
			}
		}
		rotate(0, state[0]);
		rotate(1, state[1]);
		rotate(2, state[2]);
		rotate(3, state[3]);
	}

	result = 1 * magnet[0][0] + 2 * magnet[1][0] + 4 * magnet[2][0] + 8 * magnet[3][0];
	printf("%d\n",result);
	fclose(fp);

	return 0;
}