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
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }



const int MAX = 2010;
const int INF = 100000;

int N, x, y;
vint tree[MAX];


bool seen[MAX];
int num[MAX];
int dp[MAX][MAX];

int rec(int r, int v) {
    int res = INF;
    
    seen[v] = true;
    vint child;
    for (int i = 0; i < tree[v].size(); ++i) {
        int ch = tree[v][i];
        if (!seen[ch]) {
            child.PB(ch);
            rec(r, ch);
            num[v] += num[ch];
        }
    }
     
    if (child.size() == 0) { res = 0; }
    else if (child.size() == 1) { res = num[child[0]]; }
    else if (child.size() >= 2) {
        vint alt( (int)(child.size()) );
        for (int i = 0; i < child.size(); ++i) {
            alt[i] = dp[r][child[i]] - num[child[i]];
        }
        sort(ALL(alt));
        int tmp = num[v] - 1 + alt[0] + alt[1];
        chmin(res, tmp);
    }
    
    //cout << r << ", " << v << " : " << MP(res, num[v]) << endl;
    
    return dp[r][v] = res;
}

int solve() {
    int res = INF;
    for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) dp[i][j] = INF;
    for (int i = 0; i < N; ++i) {
        memset(seen, 0, sizeof(seen));
        for (int j = 0; j < MAX; ++j) num[j] = 1;
        int tmp = rec(i, i);
        chmin(res, tmp);
    }
    return res;
}

int main() {
    freopen( "/Users/macuser/Dropbox/Contest/B-large.in", "r", stdin );
    freopen( "/Users/macuser/Dropbox/Contest/B-large.out", "w", stdout );
    
	//cout << fixed << setprecision(10);
    int T;
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        for (int i = 0; i < MAX; ++i) tree[i].clear();
        cin >> N;
        for (int i = 0; i < N-1; ++i) {
            cin >> x >> y;
            --x; --y;
            tree[x].PB(y);
            tree[y].PB(x);
        }
        
        printf("Case #%d: ", id);
        cout << solve();
        printf("\n");
    }
    
    return 0;
}




