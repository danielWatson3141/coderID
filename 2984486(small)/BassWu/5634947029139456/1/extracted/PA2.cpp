#include<stdio.h>
#include<algorithm>
using namespace std;
long long S[151];
long long T[151];
int main()
{
	int TT;
	int N, A, B;
	scanf("%d", &TT);
	int Case = 1;
	while ( TT-- ) {
		char s[1044];
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
		int v[151];
		long long totalN = 1<<B;
		int ans = 50;
		long long bitset = 0;
		for ( int Hi = 0 ; Hi < N ; Hi++ ) {
			fill(v,v+N+1,0);
			v[Hi] = 1;
			long long mask = S[0]^T[Hi];
			int find = 0;
			for ( int i = 1 ; i < N ; i++ ) {
				find = 0;
				for ( int j = 0 ; j < N ; j++ ) {
					if ( !v[j] && (S[i]^mask) == T[j] ) {
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
				if ( (mask>>j) & 1 )
					count++;
			if ( ans > count ) {
				ans = count;
				bitset = mask;
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
