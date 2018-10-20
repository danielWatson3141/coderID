#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void good(int *A, int N) {
	for (int k = 0; k < N; k++) {
		A[k] = k;
	}
	for (int k = 0; k < N; k++) {
		int index = rand() % (N - k) + k;
		int temp = A[k];
		A[k] = A[index];
		A[index] = temp;
	}
}

void bad(int *A, int N) {
	for (int k = 0; k < N; k++) {
		A[k] = k;
	}
	for (int k = 0; k < N; k++) {
		int index = rand() % (N - 0) + 0;
		int temp = A[k];
		A[k] = A[index];
		A[index] = temp;
	}
}

enum { MAX = 1000 };

double dist[MAX][MAX];
double distOld[MAX][MAX];

void algoGood(int N) {
	double invN = 1.0 / N;
	double invNPrime = 1.0 - 1.0 / N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = i == j ? 1 : 0;
		}
	}

	double temp[MAX];
	for (int k = 0; k < N; k++) {  // iteration;

		for (int j = 0; j < N; j++) {
			temp[j] = dist[k][j];
		}
		for (int i = k; i < N; i++) {
			for (int j = 0; j < N; j++) {
				distOld[i][j] = dist[i][j];
				dist[i][j] = 0;
			}
		}
		for (int j = 0; j < N; j++) {
			dist[k][j] = 0;  // clear;
		}
		double beta = 1.0 / (N - k);
		double alpha = 1.0 - beta;
		for (int i = k + 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = alpha * distOld[i][j] + temp[j] * beta;
				dist[k][j] += distOld[i][j] * beta;
			}
		}
		for (int j = 0; j < N; j++) {
			dist[k][j] += distOld[k][j] * beta;
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
	// 		printf("good dist[%d][%d] = %lf\n", i, j, dist[i][j]);
		}
	}
}

void algoBad(int N) {
	double invN = 1.0 / N;
	double invNPrime = 1.0 - 1.0 / N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = i == j ? 1 : 0;
		}
	}

	double temp[MAX];
	for (int k = 0; k < N; k++) {  // iteration;

		for (int j = 0; j < N; j++) {
			temp[j] = dist[k][j];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				distOld[i][j] = dist[i][j];
				dist[i][j] = 0;
			}
		}
		for (int j = 0; j < N; j++) {
			dist[k][j] = 0;  // clear;
		}
		double beta = 1.0 / (N - 0);
		double alpha = 1.0 - beta;
		for (int i = 0; i < N; i++) {
			if (i == k) continue;  // for now;
			for (int j = 0; j < N; j++) {
				dist[i][j] = alpha * distOld[i][j] + temp[j] * beta;
				dist[k][j] += distOld[i][j] * beta;
			}
		}
		for (int j = 0; j < N; j++) {
			dist[k][j] += distOld[k][j] * beta;
		}
// printf("iter = %d\n", k);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
// 			printf("bad dist[%d][%d] = %lf\n", i, j, dist[i][j]);
		}
	}
}

bool firsttime = true;

void solve(int CASE) {
	int N;
	scanf("%d", &N);
	if (N < 1000) {
		algoBad(N);
	} else if (firsttime) {
		algoBad(N);
		firsttime = false;
	}
	double sum = 0;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		// printf("  dist(%d) = %d: %lf\n", i, a, dist[i][a]);
		sum += dist[i][a];
	}
//	printf("  sum = %lf\n", sum);
	printf("Case #%d: %s\n", CASE, sum <= 1.007 ? "GOOD" : "BAD");
}

void makegood(int N) {
	enum { T = 1000 };
	int A[MAX];
	printf("%d\n", T);
	for (int i = 0; i < T; i++) {
		good(A, N);
		printf("%d\n", N);
		for (int j = 0; j < N; j++) {
			printf("%d ", A[j]);
		}
		printf("\n");		
	}
}

void makebad(int N) {
	enum { T = 1000 };
	int A[MAX];
	printf("%d\n", T);
	for (int i = 0; i < T; i++) {
		bad(A, N);
		printf("%d\n", N);
		for (int j = 0; j < N; j++) {
			printf("%d ", A[j]);
		}
		printf("\n");		
	}
}

int main(void) {

//	makebad(1000);
//	return 0;

	int Q;
	scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
		solve(q + 1);
	}
	return 0;
}
