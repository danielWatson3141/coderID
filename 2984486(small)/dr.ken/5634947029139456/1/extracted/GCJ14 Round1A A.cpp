#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef pair<long long, long long> pll;

#define MP make_pair
#define PB push_back
#define ALL(s) (s).begin(),(s).end()
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P) 
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << bitset<10>(P[i]); } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }



const ll INF = 10000;
int N, L;
vector<long long> s, t;

string str;
long long conv(string str) {
    ll res = 0;
    reverse(ALL(str));
    for (int i = 0; i < str.size(); ++i) {
        res *= 2;
        res += str[i] - '0';
    }
    return res;
}

void solve() {
    ll res = INF;
    sort(ALL(t));
    
    //COUT(s); COUT(t);
    for (int i = 0; i < N; ++i) {
        ll ch = s[0]^t[i];
        
        ll b = __builtin_popcountll(ch);
        vll ss(N);
        for (int j = 0; j < N; ++j) {
            ll num = s[j]^ch;
            ss[j] = num;
        }
        
        //cout << bitset<10>(ch) << " : " << ss;
        
        sort(ALL(ss));
        if (ss == t) chmin(res, b);
    }
    
    if (res < INF) cout << res << endl;
    else puts("NOT POSSIBLE");
}

int main() {
    freopen( "/Users/macuser/Dropbox/Contest/A-large.in", "r", stdin );
    freopen( "/Users/macuser/Dropbox/Contest/A-large.out", "w", stdout );
    
	//cout << fixed << setprecision(10);
    int T;
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        cin >> N >> L;
        s.clear(); t.clear();
        for (int i = 0; i < N; ++i) { cin >> str; s.PB(conv(str)); }
        for (int i = 0; i < N; ++i) { cin >> str; t.PB(conv(str)); }
        
        printf("Case #%d: ", id);
        solve();
    }
    
    return 0;
}




