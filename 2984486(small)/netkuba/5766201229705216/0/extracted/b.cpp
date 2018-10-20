#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<unordered_map>
#include<iostream>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>

#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for(int i=(a); i>=(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define VAR(v,i) __typeof(i) v = (i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define debug(x) { cerr << #x <<" = " << (x) << endl; }
#define debugv(x) { cerr << #x << " = "; FORE(it, x) cerr << *it << ", "; cerr << endl;  }
#define dprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef pair<int, int> PII;;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;
template<class C> void mini(C&a4, C b4) { a4 = min(a4,b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4,b4); }

template<class T1, class T2> ostream& operator<<(ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", "<< pair.Y << ")"; };

const int N = 1002;

int n;
vector<int> edges[N];
bool vis[N];

PII dfs(int v) {
    vis[v] = true;
    int best[3];
    REP(i, 3) best[i] = N;
    best[0] = 0;

    int mysize = 0;
    REP(j, SZ(edges[v])) {
        int u = edges[v][j];
        if (vis[u]) continue;
        
        PII curr = dfs(u);
        int size = curr.X;
        int nec = curr.Y;

        mysize += size;

        best[2] = min(best[2] + size, best[1] + nec);
        best[1] = min(best[1] + size, best[0] + nec);
        best[0] = best[0] + size;
    }

    return MP(mysize+1, min(best[0], best[2]));
}

int tryDel(int v) {
    REP(i, n) vis[i] = false;
    PII res = dfs(v);
    return res.second;
}

void doit() {
    scanf("%d", &n);
    REP(i, n-1) {
        int x,y; scanf("%d %d", &x, &y); --x; --y;
        edges[x].PB(y);
        edges[y].PB(x);
    }

    int best = N;
    REP(i, n) mini(best, tryDel(i));

    printf("%d\n", best);

    REP(i, n) edges[i].clear();
}

int main() {
    ios_base::sync_with_stdio();
    cout << fixed << setprecision(10);
    
    int ttt; scanf("%d", &ttt);
    REP(tttt, ttt) {
        printf("Case #%d: ", tttt+1);
        doit();
    }
    
    return 0;
}
