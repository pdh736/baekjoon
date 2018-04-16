#include <stdio.h>
#include <stdlib.h>

//int compare(const void*a, const void *b);
int compare(const int *a, const int *b);
int main() {
	int test[6] = { 1,5,3,9,7,4 };
	int(*pfunc)(const void *, const void *);
	pfunc = compare;
	qsort(test, 6, sizeof(int),pfunc);
	for (int i = 0; i < 6; i++) {
		printf("%d ", test[i]);
	}
}
/*
int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}*/

int compare(const int *a, const int *b) {
	return *a - *b;
}