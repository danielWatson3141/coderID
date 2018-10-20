#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int ans;
string ss[152];
map<string, int> hm;
string st[152];
int cnt(int n){
    int res = 0;
    while(n){
        if (n&1)    res ++;
        n >>= 1;
    }
    return res;
}
int main(int argc,char**argv){
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, n, l;
    cin >> t;
    for (int ca = 1; ca <= t; ca ++){
        ans = 100;
        cin >> n >> l;
        for (int i = 0; i < n; i ++){
            cin >> ss[i];
        }
        for (int i = 0; i < n; i ++){
            cin >> st[i];
        }
        for (int mnt = 0; mnt < (1<<l); mnt ++){
            hm.clear();
            for (int i = 0; i < n; i ++){
                string tmp = ss[i];
                for (int j = 0; j < l; j ++){
                    if(mnt & (1<<j)){
                        tmp[j] = '1' - tmp[j] + '0';
                    }
                }
                hm[tmp] ++;
            }
            bool ok = true;
            for (int i = 0; i < n; i ++){
                if(hm[st[i]] != 0){
                    hm[st[i]] --;
                }
                else{
                    ok = false;
                }
            }
            if (ok){
                ans = min(ans, cnt(mnt));
            }
        }
        if(ans == 100){
            printf("Case #%d: NOT POSSIBLE\n", ca);
        }
        else{
            printf("Case #%d: %d\n", ca, ans);
        }
    }
    return 0;
}
