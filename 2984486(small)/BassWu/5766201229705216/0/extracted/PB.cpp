#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<int> link[1001];
int v[1001];
int DP[1001];
int move[1001];

int comp(const void * a, const void * b) {
	return DP[*(int*)b]-DP[*(int*)a];
}

int DFS(int A) {
	v[A] = 1;
	int min3[3];
	int count = 0;
	int last = 0;
	DP[A] = 1;
	for ( int i = 0 ; i < link[A].size() ; i++ ) {
		int B = link[A][i];
		if ( !v[B] ) {
			count++;
			DFS(B);
			DP[A]+=DP[B];
			if ( count <= 2 )
				min3[count-1] = B;
			else {
				min3[2] = B;
				qsort(min3, 3, sizeof(int), comp);
				last += DP[min3[2]];
			}
		}
	}
	move[A] = last;
	if ( count == 1 )
		move[A] += DP[min3[0]];
	if ( count >= 2 ) {
		move[A] += move[min3[0]] + move[min3[1]];
	}
	return 0;
}

int main()
{
	int T;
	int N, A, B;
	scanf("%d", &T);
	int Case = 1;
	while ( T-- ) {
		scanf("%d", &N);
		for ( int i = 0 ; i <= N ; i++ ) {
			link[i].clear();
		}
		for ( int i = 1 ; i < N ; i++ ) {
			scanf("%d%d", &A, &B);
			link[A].push_back(B);
			link[B].push_back(A);
		}
		int ans = N+10;
		for ( int i = 1 ; i <= N ; i++ ) {
			fill(v,v+N+1,0);
			fill(DP,DP+N+1,0);
			fill(move,move+N+1,0);
			DFS(i);
			
			if ( move[i] < ans )
				ans = move[i];
		}
		printf("Case #%d: %d\n", Case++, ans);
	}
	return 0;
}
