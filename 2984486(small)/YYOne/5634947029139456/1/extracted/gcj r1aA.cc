#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define clr(a,b) memset(a,b,sizeof(a))

int bc[155], ec[155];
string bs[155], es[155];
int ans;
int tmp;
int n;

void dfs(int cur, int l, int tot) {
    if(cur == l) {
        ans = min(ans, tot);
        return;
    }
    sort(bs, bs+n);
    bool same = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=cur; j++) {
            if(bs[i][j] != es[i][j]) {
                same = false;
                break;
            }
        }
    }
    if(same) dfs(cur+1, l, tot);
    if(bc[cur] == ec[cur] && n%2 == 0 && bc[cur] == n/2) {
        for(int i=0; i<n; i++) {
            if(bs[i][cur] == '0') {
                bs[i][cur] = '1';
            } else {
                bs[i][cur] = '0';
            }
        }
        sort(bs, bs+n);
        bool same = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<=cur; j++) {
                if(bs[i][j] != es[i][j]) {
                    same = false;
                    break;
                }
            }
        }
        if(same && tot+1 < ans) dfs(cur+1, l, tot+1);
        for(int i=0; i<n; i++) {
            if(bs[i][cur] == '0') {
                bs[i][cur] = '1';
            } else {
                bs[i][cur] = '0';
            }
        }
    }
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    ios::sync_with_stdio(false);
    int T; cin>>T;
    int cas(0);
    while(T--) {
        int l; cin>>n>>l;
        for(int i=0; i<n; i++) cin>>bs[i];
        for(int i=0; i<n; i++) cin>>es[i];
        sort(es, es+n);
        ans = 0x3f3f3f3f;
        for(int j=0; j<l; j++) {
            bc[j] = ec[j] = 0;
            for(int i=0; i<n; i++) {
                if(bs[i][j] == '1') ++ bc[j];
                if(es[i][j] == '1') ++ ec[j];
            }
        }
        bool possible = true;
        tmp = 0;
        for(int j=0; j<l; j++) {
            if(bc[j] != ec[j] && ec[j] != n - bc[j]) {
                possible = false;
                break;
            } else if(bc[j] != ec[j]) {
                for(int i=0; i<n; i++) {
                    if(bs[i][j] == '1') bs[i][j] = '0';
                    else bs[i][j] = '1';
                }
                ++ tmp;
            }
        }
        if(possible) dfs(0, l, tmp);
        cout<<"Case #"<<++cas<<": ";
        if(possible && ans < 0x3f3f3f3f) cout<<ans<<endl;
        else cout<<"NOT POSSIBLE"<<endl;
    }

    return 0;
}
