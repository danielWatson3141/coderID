#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

template<class V, class E> struct Graph
{
    struct Ed : E
    {
        int v;
        Ed(E d, int w) : E(d), v(w) { }
    };
    struct Vs : V, vector<Ed> { };
    vector<Vs> g;
    Graph(int n) : g(n) { }
    void EdgeD(int b, int e, E d = E())
    {
        g[b].PB(Ed(d, e));
    }
    void EdgeU(int b, int e, E d = E())
    {
        Ed eg(d, e);
        eg.rev = SIZE(g[e]);
        g[b].PB(eg);
        eg.rev = SIZE(g[eg.v = b]) - 1;
        g[e].PB(eg);
    }
    void Write()
    {
        REP(x, SIZE(g))
        {
            cout << x << ": ";
            FOREACH(it, g[x]) cout << it->v << " ";
            cout << endl;
        }
    }
    void ComputeR(int v, int p)
    {
		int ed = 0, r = 0;
		FOREACH(it, g[v]) if(it->v != p)
		{
			ed++;
			ComputeR(it->v, v);
			r += g[it->v].r;
		}
		g[v].r = r + 1;
		g[v].t = 0;
		if(ed == 0) return;
		if(ed == 1)
		{
			FOREACH(it, g[v]) if(it->v != p) g[v].t = g[it->v].r;
			return;
		}
		if(ed == 2)
		{
			FOREACH(it, g[v]) if(it->v != p) g[v].t += g[it->v].t;
			return;
		}
		VI buf;
		FOREACH(it, g[v]) if(it->v != p) buf.PB(g[it->v].r - g[it->v].t);
		sort(ALL(buf));
		g[v].t = r - buf[SIZE(buf) - 1] - buf[SIZE(buf) - 2];
	}
    int Compute()
    {
		int w = INF;
		REP(x, SIZE(g))
		{
			ComputeR(x, -1);
			w = min(w, g[x].t);
		}
		return w;
	}
};
struct Vs
{
    int r, t;
};
struct Ve
{
    int rev;
};

int main()
{
	int t, n, b, e;
	scanf("%d", &t);
	FOR(o, 1, t)
	{
		scanf("%d", &n);
		Graph<Vs, Ve> g(n);
		REP(x, n - 1)
		{
			scanf("%d%d", &b, &e);
			g.EdgeU(b - 1, e - 1);
		}
		printf("Case #%d: %d\n", o, g.Compute());
	}
	return 0;
}
