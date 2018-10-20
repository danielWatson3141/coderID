#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<string.h>
#include<string>
#include<cassert>
#include<stack>
#include<queue>
#include<cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PI;

int main() {
  	int t, N, L;
  	int out[150];
  	int req[150];
 	scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {    
	  
	  	memset(out, 0, sizeof(out));
	  	memset(req, 0, sizeof(req));

    	scanf("%d %d", &N, &L);
    	string str;
    	vector<string> O, R;
    	bool pos = true;
		int ans = L + 1;
    	for(int i = 0; i < N; i++) {
    		cin>>str;
    		O.push_back(str);
    	}
    	for(int i = 0; i < N; i++) {
    		cin>>str;
    		R.push_back(str);
    	}

    	sort(R.begin(), R.end());
    	
    	for(int i = 0; i < (1 << L); i++) {
    		vector<string> tmp = O;
    		int bcnt = 0;
    		for(int j = 0; j < L; j++) {
    			if((i & (1 << j)) != 0) {
    				bcnt++;
    				for(int x = 0; x < N; x++) {
    					if(tmp[x][j] == '1') tmp[x][j] = '0';
    					else tmp[x][j] = '1';
    				}
    			} 
    		}
    		bool pp = true;
    		sort(tmp.begin(), tmp.end());
    		for(int l = 0; l < N; l++) {
    			if(tmp[l].compare(R[l]) != 0) {
    				pp = false;break;
    			}
    		}
    		if(pp) {
    			ans = min(ans, bcnt);
    		}
    	}

    	
    	if(ans <= L) {
			printf("Case #%d: %d\n", tt, ans);
		}
		else {
			printf("Case #%d: NOT POSSIBLE\n", tt);	
		}
    }

}
