#include <stdio.h>
#include <string.h>
#define MIN(a, b) (a < b) ? (a) : (b);
#define INF 987654321
#define MAXN 11
#define MAXL 11

int N, L, idx;
int stack[MAXL], top;
char O[MAXN][MAXL], D[MAXN][MAXL];
char tmp[500][MAXL][MAXN];
int tmpT;

void push(int item);
int pop();
int same(char O[][MAXL]);
void storeO(char O[][MAXL]);
void returnO(char O[][MAXL]);
void flip(char O[][MAXL], int idx);
int minPossible(int* stack, char O[][MAXL], int idx);

int main()
{
	FILE* fp = fopen("A-small.out", "w");
	int T, t, i, min;

	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		// input
		scanf("%d %d", &N, &L);
		for(i = 0; i < N; i++)
			scanf("%s", O[i]);
		for(i = 0; i < N; i++)
			scanf("%s", D[i]);

		// initialize
		top = tmpT = -1;
		idx = 0;

		// exhaustive search
		min = minPossible(stack, O, idx);

		// output
		if(min == INF)
			fprintf(fp, "Case #%d: NOT POSSIBLE\n", t);
		else
			fprintf(fp, "Case #%d: %d\n", t, min);
	}

	return 0;
}

void push(int item) {
	stack[++top] = item;
}

int pop() {
	return stack[top--];
}

int same(char O[][MAXL]) {
	int check[MAXN] = {0, }, i, j;

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(strcmp(O[i], D[j]) == 0)
				check[i]++;
		}
	}
	
	for(i = 0; i < N; i++) {
		if(check[i] != 1)
			return 0;
	}
	return 1;
}

void storeO(char O[][MAXL]) {
	int i;

	++tmpT;
	for(i = 0; i < N; i++) {
		sscanf(O[i], "%s", tmp[tmpT][i]);
	}
}

void returnO(char O[][MAXL]) {
	int i;

	for(i = 0; i < N; i++) {
		sscanf(tmp[tmpT][i], "%s", O[i]);
	}
	tmpT--;
}

void flip(char O[][MAXL], int idx) {
	int i;

	for(i = 0; i < N; i++) {
		O[i][idx] = ((O[i][idx] - '0') ^ 1 + '0');
	}
}

int minPossible(int* stack, char O[][MAXL], int idx) {
	int ret = INF;

	// base case
	if(idx == L) {
		if(same(O) == 1)
			return top + 1;
		else
			return INF;
	}

	// recursive
	ret = minPossible(stack, O, idx + 1);
	push(idx);
	storeO(O);
	flip(O, idx);
	ret = MIN(ret, minPossible(stack, O, idx + 1));
	returnO(O);
	pop();
	return ret;
}