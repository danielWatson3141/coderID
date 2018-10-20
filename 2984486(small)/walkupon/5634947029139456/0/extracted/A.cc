#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#define LL long long
using namespace std;

map<LL, int>mp;
LL x[200];
LL y[200];
int n, m;

struct point{
    LL bit;
    int cnt;
}p[200];

int CNT(LL x){
    int ans = 0;
    while(x){
        if(x & 1LL) ans++;
        x /= 2;
    }
    return ans;
}

bool cmp(point x, point y){
    return x.cnt < y.cnt;
}

LL input(){
    char str[50];
    scanf("%s", str);
    LL ans = 0;
    for(int i = 0; i < m; ++i){ans = ans * 2 + str[i] - '0';
    //cout<<str<<"   "<<ans<<endl;
    }
    return ans;
}

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, tt = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) x[i] = input();
        for(int i = 0; i < n; ++i) y[i] = input();
        for(int i = 0; i < n; ++i) {
            LL tmp = x[0] ^ y[i];
            p[i].bit = tmp;
            p[i].cnt = CNT(tmp);
        }
        sort(p, p + n, cmp);
        int ans = 2000000;
        for(int i = 0; i < n; ++i){
            LL bit = p[i].bit;
            //cout<<" ====== "<<i<<"  "<<bit<<"  "<<endl;
            mp.clear();
            for(int j = 0; j < n; ++j) mp[y[j]] = 1;
            bool ok = true;
            for(int j = 0; j < n; ++j){
                int tmp = x[j] ^ bit;
            //cout<<" ====== "<<j<<"  "<<tmp<<"  "<<mp[tmp]<<endl;
                if(mp[tmp] <= 0){
                    ok = false;
                    break;
                }
                --mp[tmp];
            }
            if(ok){
                ans = p[i].cnt;
                break;
            }
        }
        if(ans > m) printf("Case #%d: NOT POSSIBLE\n", ++tt);
        else printf("Case #%d: %d\n", ++tt, ans);
    }
    return 0;
}
