#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int L;

char initial[150][44];
char device[150][44];

long long init[150];
long long dev[150];

int flips = 0;

int minFlips = 100;


void convert()
{
	for (int i = 0; i < N; i++) {
		long long val = 0;
		init[i] = 0;
		dev[i] = 0;
		for (int j = 0; j < L; j++) {
			init[i] |= (((long long)(initial[i][j]-'0')) << j);
			dev[i] |= (((long long)(device[i][j]-'0')) << j);
		}
	}

	sort(dev, dev + N);
}

void check()
{
	sort(init, init + N);
	for (int i = 0; i < N; i++) {
		if (init[i] != dev[i]) {
			return;
		}
	}

	minFlips = flips;
}

void flipit(int depth)
{
	for (int i = 0; i < N; i++) {
		long long val = init[i];
		val ^= (((long long)1) << (depth - 1));
		init[i] = val;
	}
}

void brute(int depth)
{
	if (depth == 0) {
		check();
		return;
	}
	
	if (minFlips <= flips) {
		return;
	}

	brute(depth-1);

	if (minFlips <= flips + 1) {
		return;
	}

	flips++;
	flipit(depth);
	brute(depth-1);
	flipit(depth);
	flips--;
}

void solve()
{
	flips = 0;
	minFlips = 100;
	brute(L);

	if (minFlips < 100) {
		printf("%d\n", minFlips);
	} else {
		printf("NOT POSSIBLE\n", minFlips);
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &N, &L);
		for (int j = 0; j < N; j++) {
			scanf("%s", initial[j]);
		}
		for (int j = 0; j < N; j++) {
			scanf("%s", device[j]);
		}

		printf("Case #%d: ", i);
		convert();
		solve();
	}
	return 0;
}
