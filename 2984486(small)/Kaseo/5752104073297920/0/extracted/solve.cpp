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

int a[1005];

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++ ){
		int n;
		scanf("%d", &n);

		int dist = 0, tot = 0;
		for(int i=0; i<n; i++){
			scanf("%d", a+i);
			if( i < n/2 ){
				if( a[i] > i )
					tot++;
				else
					tot--;
			}
			else{
				if( a[i] < i )
					tot++;
				else
					tot--;
			}
			dist += abs( a[i] - i );
		}
		bool can = 1;
		
		if( a[0] == 0 && n > 1 ) 
			can = 0;
		if( dist < n ) 
			can = 0;
		
		printf("Case #%d: ", R);
		if( can ) 
			puts("GOOD");
		else
			puts("BAD");
	}
}