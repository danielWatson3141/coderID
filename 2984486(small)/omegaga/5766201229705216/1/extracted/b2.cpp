# include <iostream>
# include <cstdio>
#define PRETEST
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cstdio>
using namespace std;

#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFF
#define BIG 0x4F4F4F4F
#define PI acos(-1)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

typedef long long ll;
typedef unsigned long long ull;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<string, int> psi;

#define DEBUG(x) cout << #x << " : " << x << endl

#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define PB push_back
#define eps 1e-9
#define fst first
#define snd second
#define REP(I,N) for (int I = 0; I < (N); I++)
#define REPP(I,A,B) for (int I = (A); I < (B); I++)
#define REPE(I,A,B) for (int I = (A); I <= (B); I++)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define RS(X) scanf("%s", (X))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

# define MAXN 1002
# define MAXE 2002

struct node{
	int x;
  node *next;
} *g[MAXN], edge[MAXE];

int cnt = 0;

void add_edge(int x,int y) {
	node *p = &edge[cnt++];
	p->x = y;
  p->next = g[x];
  g[x] = p;
}

int DFS(int x,int fa) {
	int m1 = 0, m2 = 0;
	for(node *p=g[x]; p; p=p->next)
    if (p->x != fa) {
		int t = DFS(p->x, x);
		if(t >= m1) {
			m2 = m1;
      m1 = t;
    }
		else if(t > m2)
      m2 = t;
	}
	if(m2 == 0)
    return 1;
	return m1 + m2 + 1;
}

int n;

int getAns() {
  int res = 0;
  REPE(i, 1, n)
    res = max(res, DFS(i, -1));
  return n - res;
}

int main() {
  freopen("b.in","r",stdin);
	int T;
  cin >> T;
	for(int i=1; i<=T; i++) {
		scanf("%d", &n);
    RESET(g, 0);
    cnt = 0;
    for (int k = 1; k < n; k++) {
			int x, y; scanf("%d%d", &x, &y);
			add_edge(x, y); add_edge(y, x);
		}
		printf("Case #%d: %d\n", i, getAns());
	}
	return 0;
}
