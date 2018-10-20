#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

const long long INF = 1000000007;
typedef pair <int, int> ii;
long long gcd( long long b, long long s ){
	return (s!=0) ? gcd( s, b%s ) : b;
}

char s[155][44], p[155][44];
long long t[155], c[155];

int main(){ //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++ ){
		int n, l;
		scanf("%d %d", &n, &l);

		for(int i=0; i<n; i++){
			scanf("%s", s[i]);
			long long st = 0;
			for(int j=0; j<l; j++)
				if( s[i][j] == '1' )
					st |= (1<<j );
			t[i] = st;
		}

		
		for(int i=0; i<n; i++){
			scanf("%s", p[i]);
			long long st = 0;
			for(int j=0; j<l; j++)
				if( p[i][j] == '1' )
					st |= (1<<j);
			c[i] = st;
		}
		int res = INF;
		bool can = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				long long f = 0;
				int tot = 0;
				for(int k=0; k<l; k++){
					if( s[i][k] != p[j][k] ) {
						f |= (1<<k); 
						++tot;
					}
				}
				bool check = 1;
				map <long long, int> mp;
				map <long long, int> ::iterator it;
				for(int k=0; k<n; k++){
					++mp[f^t[k]];
					--mp[c[k]];
				}	
				
				for(it = mp.begin(); it != mp.end(); it++){
					if( it->second != 0 ) {
						check = 0;
						break;
					}
				}
				if( check ){
					
					res = min( res, tot );
					can  = 1;
				}
			}
		}
		printf("Case #%d: ", R);
		if( can ) 
			printf("%d\n", res);
		else
			puts("NOT POSSIBLE");
	}
}