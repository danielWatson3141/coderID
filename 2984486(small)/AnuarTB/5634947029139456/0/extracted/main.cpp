#include <bits/stdc++.h>

//#define debug

using namespace std;

const int MXN = 1e6 + 10;
const int INF = 1e9 + 7;

int T, n, l;
string a[1510], b[1510];
vector <string> v1;

void solve(){
    int ans = INF;
    for(int i = 0; i < (1 << l); ++i){
        bool ok = true;
        int cnt = 0;
        vector <string> v2;
        for(int j = 0; j < n; ++j){
            string tmp = a[j];
            for(int k = 0; k < l; ++k){
                if(i & (1 << k)){
                    ++cnt;
                    tmp[k] = (tmp[k] == '0' ? '1' : '0');
                }
            }
            v2.push_back(tmp);
        }
        sort(v2.begin(), v2.end());
        #ifdef debug
            for(int j = 0; j < v2.size(); ++j){
                cout << v2[j] << "\n";
            }
            printf("----v2----\n");
        #endif
        for(int j = 0; j < n; ++j){
            if(v1[j] != v2[j]){
                ok = false;
                break;
            }
        }
        if(ok)
            ans = min(ans, cnt);
    }
    if(ans < INF)
        printf("%d\n", ans / n);
    else
        printf("NOT POSSIBLE\n");
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(int s = 1; s <= T; ++s){
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            v1.push_back(b[i]);
        }
        sort(v1.begin(), v1.end());
        #ifdef debug
            for(int i = 0; i < v1.size(); ++i){
                cout << v1[i] << "\n";
            }
            printf("----v1----\n");
        #endif // debug
        printf("Case #%d: ", s);
        solve();
        v1.clear();
    }
    return 0;
}
