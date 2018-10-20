// Submitted by Silithus @ Macau
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define LL long long
#define INF 0x7fffffff

using namespace std;

int N,L,ans,zero[2][40],one[2][40];
long outlet[2][150];

void try_flip(int n, int flip)
{
	int i;

	if( n == L ) {
		sort(outlet[0], outlet[0]+N);
		sort(outlet[1], outlet[1]+N);
		for(i=0; i<N; i++)
			if( outlet[0][i] != outlet[1][i] )
				break;

		if( i >= N )
			ans = min(ans,flip);
		
		return;
	}

	if( zero[0][n]==zero[1][n] && one[0][n]==one[1][n] )
		try_flip(n+1,flip);

	if( zero[0][n]==one[1][n] && one[0][n]==zero[1][n] ) {
		long mask = 1<<n;
		for(i=0; i<N; i++) outlet[0][i] ^= mask;
		try_flip(n+1,flip+1);
		for(i=0; i<N; i++) outlet[0][i] ^= mask;
	}

	return;
}

void solve(void)
{
	int i,j,n;
	long mask;
	string s;
	
	cin >> N >> L;

	for(n=0; n<2; n++) {
		for(i=0; i<L; i++)
			zero[n][i] = one[n][i] = 0;
		for(i=0; i<N; i++) {
			cin >> s;
			for(j=0,outlet[n][i]=0ll,mask=0x1; j<L; j++,mask<<=1) {
				if( s[j] == '1' ) {
					one[n][j]++;
					outlet[n][i] |= mask;
				} else
					zero[n][j]++;
			}
		}
	}
	
	ans = INF;
	try_flip(0,0);
	
	if( ans == INF )
		cout << "NOT POSSIBLE" << endl;
	else
		cout << ans << endl;
}

int main(void)
{
	int t,T;
	
	cin >> T;

	for(t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	
	return 0;
}
