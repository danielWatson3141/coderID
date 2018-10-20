#include <bits/stdc++.h>
using namespace std;
#define INF (1<<30)
#define msg(x) cout<<#x<<" = "<<x<<endl;
int main() {
    //ios_base::sync_with_stdio(0);
    int T, ans, n, len;
    scanf("%d", &T);
    for(int caso=1 ; caso<=T ; caso++) {
    	ans = INF;
    	scanf("%d %d", &n, &len);
		vector<string> enchufe(n), conector(n); 
    	for(int i=0 ; i<n ; i++) cin>>enchufe[i];
    	for(int i=0 ; i<n ; i++) cin>>conector[i];
    	sort(conector.begin(), conector.end());
    	for(int i=0 ; i<1 ; i++) {
    		for(int k=0 ; k<n ; k++) {
    			bool sw[100] = {false};
    			int cnt = 0;
    			for(int z=0 ; z<len ; z++)
    				if( conector[i][z] != enchufe[k][z] ) { sw[z] = true; cnt++; }
    			vector<string> v(n);
    			for(int j=0 ; j<n ; j++) {
    				string s = enchufe[j];
    				for(int z=0 ; z<len ; z++) {
    					if( sw[z] ) {
    						if( enchufe[j][z] == '1' ) s[z] = '0';
    						else s[z] = '1';
    					}
    				}
    				v[j] = s;
    			} 
    			sort(v.begin(), v.end());
    			bool flag = true;
    			for(int j=0 ; j<n ; j++) if( v[j] != conector[j] ) { flag = false; break; }
    			if( flag ) ans = min(ans, cnt);
    		}
    	}
    	if( ans == INF ) printf("Case #%d: NOT POSSIBLE\n", caso);
    	else printf("Case #%d: %d\n", caso, ans);
    }
    return 0;
}