#include <bits/stdc++.h>
#include <cassert>
#include <climits>
#include <cfloat>

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

int v[1005] = {0};

int main()
{
	int T; scanf("%d", &T);
	FOREQ(t,1,T)
	{
		int N; scanf("%d", &N);
		CLR(v);

		ULL sum = 0ULL;
		FOR(i,0,N)
		{
			scanf("%d", &v[i]);
			if (i<100) sum+=v[i];
		}

		if (sum <= 49950ULL)
		{
			printf("Case #%d: BAD\n", t);
		}
		else
		{
			printf("Case #%d: GOOD\n", t);
		}
	}
	return 0;
}
