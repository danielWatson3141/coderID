#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
typedef long long i64;

int N;
int A[1050];

void bad_shuffle() {
	for(int i = 0; i < N; i++) {
		A[i] = i;
	}

	for(int i = 0; i < N; i++) {
		int p = rand() % N;
		if(p != i) swap(A[i], A[p]);
	}
}

void good_shuffle() {
	for(int i = 0; i < N; i++) {
		A[i] = i;
	}

	for(int i = 0; i < N; i++) {
		int p = rand() % (N-i) + i;
		if(p != i) swap(A[i], A[p]);
	}
}

bool judge()
{
	int bp = 0;
	/*
	for(int i = 0; i < N/2; i++) {
		if(A[i] >= i && A[i] < (i + N/2)) ++bp;
	}
	*/
	for(int i = 0; i < 1000; i++) {
		if(A[i] >= i && A[i] < (i + 500)) ++bp;
	}

	//printf("%d\n", bp);
	bool flg = bp > 375 + 20;

	return flg; //true: BAD false: GOOD
}

void examine()
{
	int bad = 0;
	puts("Good test");
	for(int i = 0; i < 10000; i++) {
		N = 1000;
		good_shuffle();
		if(judge()) bad++;
	}

	printf("False judge: %d\n", bad);

	bad = 0;
	puts("Bad test");
	for(int i = 0; i < 10000; i++) {
		N = 1000;
		bad_shuffle();
		if(!judge()) bad++;
	}

	printf("False judge: %d\n", bad);
}

int main()
{
	srand((int)time(NULL));

	//examine();
	//return 0;
	int T;
	scanf("%d", &T);

	int bc = 0;

	for(int t = 0; t++ < T; ) {
		scanf("%d", &N);
		//N = 1000;

		for(int i = 0; i < N; i++) scanf("%d", A + i);
		//bad_shuffle();
		//good_shuffle();

		bool flg = judge();
		if(flg) ++bc;
		printf("Case #%d: %s\n", t, flg ? "BAD" : "GOOD");
	}

	//printf("%d\n", bc);
	return 0;
}
