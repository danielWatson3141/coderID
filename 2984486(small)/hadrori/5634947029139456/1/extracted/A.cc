#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <complex>

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);

int N, L;
int change[64];
int tcnt[64], fcnt[64];
vector<ll> from, to;
set<ll> S;

void init(){
    from.clear();
    to.clear();
    S.clear();
}

void input(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        ll t = 0;
        for(int j = 0; j < L; j++){
            t <<= 1LL;
            t |= (s[j] == '1');
        }
        from.push_back(t);
    }
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        ll t = 0;
        for(int j = 0; j < L; j++){
            t <<= 1LL;
            t |= (s[j] == '1');
        }
        to.push_back(t);
    }
}

void solve(){
    int ans = inf;
    sort(from.begin(), from.end());
    sort(to.begin(), to.end());
    for(int i = 0; i < N; i++){
        S.clear();
        ll t = from[0] ^ to[i];
        for(int j = 0; j < N; j++)
            if(i != j) S.insert(to[j]);
        for(int j = 1; j < N; j++){
            ll gen = from[j] ^ t;
            set<ll>::iterator it = S.find(gen);
            if(it != S.end()) S.erase(it);
            else break;
        }
        if(S.size() == 0) ans = min(ans, __builtin_popcount(t));
    }
    if(ans == inf) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        init(); input();
        solve();
    }
    return 0;
}
