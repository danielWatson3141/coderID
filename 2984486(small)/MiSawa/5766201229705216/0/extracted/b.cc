#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define repsz(i,v) rep(i,sz(v))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define bit(x) (1LL<<(x))
#define int long long
#define cauto const auto &
static const int INF = 1<<25;
static const double EPS = 1e-5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
template<class T> T mineq(T &a, const T &b){ return a = min(a, b); }
template<class T> T maxeq(T &a, const T &b){ return a = max(a, b); }
template<typename T> T s_to(string s){ //{{{
    stringstream ss;
    T res;
    ss << s;
    ss >> res;
    return res;
} //}}}
template<typename T> string to_s(T x){//{{{
    stringstream ss; ss << x; return ss.str();
}//}}}


struct E{
    int s, t;
    E(int s, int t) : s(s), t(t) {}
};
typedef vector<E> V;
typedef vector<V> G;
G g;

map<tuple<int, int>, int> memo1;
int count(int r, int p){
    if(memo1.count(mt(r, p))) return memo1[mt(r, p)];
    int &res = memo1[mt(r, p)];
    res = 1;
    for(cauto e : g[r]) if(e.t != p) res += count(e.t, r);
    return res;
}

map<tuple<int, int>, int> memo2;
int dfs(int r, int p){
    if(memo2.count(mt(r, p))) return memo2[mt(r, p)];
    int &res = memo2[mt(r, p)];
    res = 0;
    for(cauto e : g[r]) if(e.t != p) res += count(e.t, r);
    if(g[r].size() + (p == -1) <= 2){
    }else{
        vector<int> cnt;
        for(cauto e : g[r]) if(e.t != p) cnt.eb(count(e.t, r) - dfs(e.t, r));
        sort(rall(cnt));
        res -= cnt[0] + cnt[1];
        //if(p == -1){
        //    cout << res << endl;
        //    cout << count(0, 1) << ", " << count(2, 1) << endl;
        //    cout << cnt[0] << ", " << cnt[1] << endl;
        //}
    }
    return res;
}

void solve(){
    memo1.clear();
    memo2.clear();
    int n; cin >> n;
    g.clear();
    g.resize(n);
    rep(_, n-1){
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].eb(a, b);
        g[b].eb(b, a);
    }
    int res = 1LL<<40;
    rep(i, n){
        mineq(res, dfs(i, -1));
    }
    cout << res << endl;
}



signed main(){//{{{
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed); cout.precision(10);
    string s;
    getline(cin, s);
    int T = s_to<int>(s);
    rep(i, T){
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}//}}}
/* vim:set foldmethod=marker commentstring=//%s : */
