#include <bits/stdc++.h>
#include <cassert>
#include <climits>
#include <cfloat>

#include "prettyprint98.hpp"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

/*
srand((unsigned)time(NULL));
inline unsigned int rand16(){return ((rand()) << 15) ^ rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
inline ULL rand64(){return ((LL)rand32() << 32) | rand32();}
inline ULL random(LL l, LL r){return l == r ? l : rand64() % (r - l) + l;}
*/

const int INF = 0x3f3f3f3f;
const LL INFF = 1LL << 60;
const double EPS = 1e-9;
const double PI = acos(-1.0); //2*acos(0.0); //M_PI;

//4 dirs: int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
//8 dirs: int dx[]={1,1,0,-1,-1,-1,0,1}, dy[]={0,1,1,1,0,-1,-1,-1};
//hex: int dx[6]={2,1,-1,-2,-1,1}, dy[6]={0,1,1,0,-1,-1};
//knight: int dx[]={2,1,-1,-2,-2,-1,1,2}, dy[]={1,2,2,1,-1,-2,-2,-1};

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)
#define RFOR(i,a,b)  for(int(i)=(a),_b(b);(i)>=_b;--(i))
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define FILL(arr,val) memset((arr),(val),sizeof(arr))
#define CLR(a)        memset((a),0,sizeof(a))
#define CPY(dest,src) memcpy((dest),(src),sizeof(dest))

#define ALL(a)       (a).begin(),(a).end()
#define SZ(a)        ((int)(a).size())
#define UNIQ(a)      sort(ALL(a)); (a).erase(unique(ALL(a)),(a).end())
#define IDX(arr,ind) (lower_bound(ALL(arr),ind)-arr.begin())

#define fst first
#define snd second
#define pb  push_back
#define mp  make_pair

inline LL __lcm(LL a, LL b){return a*b/__gcd(a,b);}
inline double dist(double x1, double y1, double x2, double y2)
	{return hypot(x1-x2,y1-y2);}

int N, L;
char l[45];
vector<vector<int> > g, f, gg;

int main()
{
	int T; scanf("%d", &T);
	FOREQ(t,1,T)
	{
		scanf("%d%d", &N,&L);
		g.clear(); f.clear();
		FOR(i,0,N)
		{
			vector<int> row(L,0); g.pb(row);
			vector<int> roww(L,0); f.pb(roww);
		}
		FOR(i,0,N)
		{
			scanf("%s", &l);
			FOR(j,0,L)
			{
				if (l[j] == '1')
					g[i][j] = 1;
			}
		}
		FOR(i,0,N)
		{
			scanf("%s", &l);
			FOR(j,0,L)
			{
				if (l[j] == '1')
					f[i][j] = 1;
			}
		}
		sort(ALL(g)); sort(ALL(f));

		ULL start = 0ULL, end = 1<<L;
		int nflips = INT_MAX;
		while(start<end)
		{
			gg.clear(); FOR(i,0,N) gg.pb(g[i]);
			int num_flips = 0;
			FOR(i,0,L)
			{
				if (start & (1<<i))
				{
					FOR(j,0,N)
					{
						gg[j][i] = 1 - gg[j][i];
					}
					num_flips++;
				}
			}
			sort(ALL(gg)); sort(ALL(f));

			bool won = true;
			FOR(i,0,N)
			{
				FOR(j,0,L)
				{
					if (gg[i][j] != f[i][j])
					{
						won = false;
						break;
					}
				}
				if (!won) break;
			}
			if (won) {
				nflips = min(nflips, num_flips);
			}
			start++;
		}

		printf("Case #%d: ", t);
		if (nflips == INT_MAX)
		{
			printf("NOT POSSIBLE");
		}
		else
		{
			printf("%d", nflips);
		}
		printf("\n");
	}
	return 0;
}
