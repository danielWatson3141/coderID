#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
int v[1020];
int main() {
    //ios_base::sync_with_stdio(0);
    int T, n;
    scanf("%d", &T);
    for(int caso=1 ; caso<=T ; caso++) {
    	scanf("%d", &n);
    	for(int i=0 ; i<n ; i++) {
    		scanf("%d", &v[i]);
    	}
    	int cnt = 0;
    	for(int i=0 ; i<n ; i++) {
    		if( i == v[i] ) cnt++;
    		//scanf("%d", &v[i]);
    	}
    	if( cnt > n / 10 ) printf("Case #%d: BAD\n", caso);
    	else if( rand() % 2 ) printf("Case #%d: GOOD\n", caso);
    	else printf("Case #%d: BAD\n", caso);
    }
    return 0;
}