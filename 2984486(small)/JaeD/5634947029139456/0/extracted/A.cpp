#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;
int Search(int reverse, int now, int L, int N);
int counta[40] = { 0 };
int countb[40] = { 0 };
int a[150][40];
int b[150][40];
bool flip[40] = { false };


int compare(int a[40], int b[40], int L) {
	int i;
	for (i = 0; i < L; i++) {
		if (a[i]>b[i]) return -1;
		else if (a[i] < b[i]) return 1;
	}
	return 0;
}

int main() {
	FILE*f = fopen("A-small-attempt3.in", "r+");
	int T, L, N, i, j, k, l;
	char str[40];
	fscanf(f, "%d", &T);
	char temp[40] = { 0 };
	int reverse;
	FILE*f2 = fopen("A-small-attempt3.out", "w+");


	for (i = 0; i < T; i++) {
		fscanf(f, "%d %d\n", &N, &L);
		for (j = 0; j < 40; j++) {
			counta[j] = 0;
			countb[j] = 0;
			str[j] = 0;
			temp[j] = 0;
			flip[j] = false;
		}
		for (j = 0; j < 150; j++) {
			for (k = 0; k < 40; k++) {
				a[j][k] = 0;
				b[j][k] = 0;
			}
		}

		for (j = 0; j < N; j++) {
			fscanf(f, "%s ", str);
			for (k = 0; k <L; k++) {
				a[j][k] = str[k] - '0';
				counta[k] += a[j][k];
			}
		}
		for (j = 0; j < N; j++) {
			fscanf(f, "%s ", str);
			for (k = 0; k < L; k++) {
				b[j][k] = str[k] - '0';
				countb[k] += b[j][k];
			}
		}
		for (k = 0; k < N; k++) {
			for (j = 0; j< N - 1; j++) {
				if (compare(b[j], b[j + 1], L) >0) {
					for (l = 0; l < L; l++)	temp[l] = b[j][l];
					for (l = 0; l < L; l++)	b[j][l] = b[j + 1][l];
					for (l = 0; l < L; l++)	b[j + 1][l] = temp[l];
				}
			}
		}
		fprintf(f2, "Case #%d: ", i + 1);
		reverse = Search(0, 0, L, N);
		if (reverse <0) fprintf(f2, "NOT POSSIBLE\n");
		else fprintf(f2, "%d\n", reverse);
	}
	fclose(f2);
	fclose(f);

}


bool Check(int L, int N) {
	int bufa[150][40] = { 0 };
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < L; j++) {
			bufa[i][j] = ((bool)a[i][j]) ^ flip[j];

		}
	}
	char temp[400] = { 0 };
	int k, l;
	for (k = 0; k < N; k++) {
		for (j = 0; j< N - 1; j++) {
			if (compare(bufa[j], bufa[j + 1], L) >0) {
				for (l = 0; l < L; l++)	temp[l] = bufa[j][l];
				for (l = 0; l < L; l++)	bufa[j][l] = bufa[j + 1][l];
				for (l = 0; l < L; l++)	bufa[j + 1][l] = temp[l];
			}
		}
	}
	for (i = 0; i < L; i++) {
		if (compare(bufa[i], b[i], L) != 0) return false;
	}
	return true;

}

int Search(int reverse, int now, int L, int N) {
	int buf1 = -2;
	int buf2 = -2;
	if (now >= L) {
		if (Check(L, N)) return reverse;
		else return -1;
	}
	if (counta[now] == countb[now]) {
		buf1 = Search(reverse, now + 1, L, N);
	}
	if (counta[now] == N - countb[now]) {
		flip[now] = true;
		buf2 = Search(reverse + 1, now + 1, L, N);
		flip[now] = false;
	}

	if (buf1 >= buf2) {
		if (buf2 >= 0) return buf2;
		return buf1;
	}
	if (buf1<buf2) {
		if (buf1 >= 0) return buf1;
		return buf2;
	}
}