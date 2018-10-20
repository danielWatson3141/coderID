#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

ll s[160];
ll t[160];
ll s2[160];

int count(ll mask){
    int ret = 0;
    for(int i = 0; i < 60; i++)
        if(1LL<<i&mask)
            ret++;
    return ret;
}

ll read(){
    char buf[100];
    ll ret = 0;
    scanf("%s", buf);
    for(int i = 0; buf[i]; i++){
        ret = ret*2 + (buf[i]-'0');
    }
    return ret;
}

int main() {
#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int i0 = 1;
	int T;
	scanf("%d", &T);
	for (i0 = 1; i0 <= T; i0++) {
		int i, j, k;
		int n, m;
		int ans = 1<<20;
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++)
		    s[i] = read();
        for(i = 0; i < n; i++)
            t[i] = read();
            
        sort(t, t+n);
        
        for(i = 0; i < n; i++){
            ll del = s[0]^t[i];
            for(j = 0; j < n; j++)
                s2[j] = s[j]^del;
            sort(s2, s2+n);
            for(j = 0; j < n; j++)
                if(s2[j] != t[j])
                    break;
                    
            if(j < n)
                continue;
            ans = min(ans, count(del));
        }
        if(ans < 1<<20)
            printf("Case #%d: %d\n", i0, ans);
        else
            printf("Case #%d: NOT POSSIBLE\n", i0);
	}
	return 0;
}
