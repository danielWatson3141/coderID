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

#define flip hogehogefugafuga

void solve(){
    int n, l; cin >> n >> l;
    vector<vector<int> > a(n, vector<int>(l)), b(n, vector<int>(l));
    rep(i, n){
        rep(j, l){
            char c; cin >> c; a[i][j] = c == '1';
        }
    }
    rep(i, n){
        rep(j, l){
            char c; cin >> c; b[i][j] = c == '1';
        }
    }
    int res = 1LL<<40;
    rep(j, n){ // 0 -> j
        vector<int> flip(l);
        rep(x, l) flip[x] = a[0][x] != b[j][x];
        bool ok = true;
        set<vector<int> > hoge;
        rep(i, n){
            vector<int> tmp(l);
            rep(x, l) tmp[x] = flip[x] ^ a[i][x];
            hoge.insert(tmp);
        }
        rep(i, n) if(!hoge.count(b[i])) ok = false;
        if(ok) res = min(res, (ll)accumulate(all(flip), 0));
    }
    if(res > (1LL<<20)){
        cout << "NOT POSSIBLE" << endl;
    }else{
        cout << res << endl;
    }
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
