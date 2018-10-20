#include<stdio.h>
#include<algorithm>
using namespace std;
int S[151];
int T[151];
int main()
{
	int TT;
	int N, A, B;
	scanf("%d", &TT);
	int Case = 1;
	while ( TT-- ) {
		char s[1000];
		scanf("%d%d", &N, &B);
		for ( int i = 0 ; i < N ; i++ ) {
			scanf("%s", s);
			S[i] = 0;
			for ( int j = 0 ; j < B ; j++ ) {
				S[i] |= ((s[j]-'0')<<j);
			}
		}
		for ( int i = 0 ; i < N ; i++ ) {
			scanf("%s", s);
			T[i] = 0;
			for ( int j = 0 ; j < B ; j++ ) {
				T[i] |= ((s[j]-'0')<<j);
			}
		}
		int v[50];
		int totalN = 1<<B;
		int ans = 50;
		int bitset = 0;
		for ( int i = 0 ; i < totalN ; i++ ) {
			int mask = i;
			fill(v,v+50,0);
			
			int find = 0;
			for ( int j = 0 ; j < N ; j++ ) {
				find = 0;
				for ( int k = 0 ; k < N ; k++ ) {
					if ( !v[k] && (S[j]^mask) == T[k] ) {
						v[k] = 1;
						find = 1;
						break;
					}
				}
				if ( !find )
					break;
			}
			if ( !find )
				continue;
			int count = 0;
			for ( int j = 0 ; j < B ; j++ )
				if ( (i>>j) & 1 )
					count++;
			if ( ans > count ) {
				ans = count;
				bitset = i;
			}
		}
		printf("Case #%d: ", Case++);
		if ( ans == 50 )
			puts("NOT POSSIBLE");
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
