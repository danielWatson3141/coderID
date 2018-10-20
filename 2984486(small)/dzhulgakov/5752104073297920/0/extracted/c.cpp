#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 1024

//int q[10][10];

double d[2][N][N];
int cur = 0, nw = 1;

int aa[N];
int n = 1000;

void genfair()
{
	REP(i,n) aa[i]=i;
	REP(i,n)
	{
		int p = i+rand()%(n-i);
		swap(aa[i],aa[p]);
	}
}

void genbad()
{
	REP(i,n) aa[i]=i;
	REP(i,n)
	{
		int p = rand()%n;
		swap(aa[i],aa[p]);
	}
}

bool solve() {
	double prgood = 0;
	double prbad = 0;
	REP(i,n)
	{
		prbad += log(d[cur][aa[i]][i]);
		prgood += log(1.0/n);
	}
	//cout << prgood << " - " << prbad << endl;
	return prgood > prbad;
}

int main(int argc, char **argv)
{
	//freopen("q.out","w",stdout);
	/*cin>>n;
	int pw = 1;
	REP(i,n) pw*=n;
	int fact = 1;
	REP(i,n) fact *= i+1;
	map<string,int> pr;
	CLEAR(q);
	REP(mask,pw)
	{
		int a[10];
		REP(i,n) a[i]=i;
		int x = mask;
		REP(i,n)
		{
			int rnd = x%n;
			x/=n;
			swap(a[rnd],a[i]);
		}
		stringstream ss;
		REP(i,n) ss << a[i];
		pr[ss.str()]++;
		REP(i,n)
			q[a[i]][i]++;
	}
	double s = 0;
	int cnt = 0;
	for (map<string,int>::iterator it = pr.begin(); it != pr.end(); it++)
	{
		s += it->second*1.0/pw - 1.0/fact;
		if (it->second*(LL)fact - pw > 0)
		{
			//printf("%s %d %.10lf\n",it->first.data(), it->second, it->second*1.0/pw - 1.0/fact);
			++cnt;
		}
	}
	cerr << cnt << endl;
	cerr << s << endl;
	REP(i,n)
	{
		printf("%d:", i);
		REP(j,n) printf(" %d", q[i][j]);
		printf("\n");
	}*/



	
	CLEAR(d);
	REP(i,n) d[cur][i][i]=1.0;
	double ppp = 1.0/n;
	double qqq = 1.0-ppp;
	REP(step,n)
	{
		CLEAR(d[nw]);
		REP(pos,n)
		{
			if (pos == step)
			{
				REP(val,n)
					REP(newpos,n)
						d[nw][val][newpos] += ppp*d[cur][val][pos];
			}
			else
			{
				REP(val,n)
				{
					d[nw][val][step] += ppp*d[cur][val][pos];
					d[nw][val][pos] += qqq*d[cur][val][pos];
				}
			}
		}
		swap(cur,nw);
	}

	/*REP(i,n)
	{
		printf("%d:", i);
		REP(j,n) printf(" %.6lf", d[cur][i][j]);
		printf("\n");
	}*/

	int TESTS = 100;

	double s1=0,s2=0;
	REP(i,TESTS)
	{
		genbad();
		//REP(j,n) printf("%d ",aa[j]);
		//printf("\n");
		if (!solve())
			s2 += 1.0/TESTS;
	}
	REP(i,TESTS)
	{
		genfair();
		if (solve())
			s1 += 1.0/TESTS;
	}
	cerr << s1 << " " << s2 << endl;

	//return 0;

	string FN = "C-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		int k;
		scanf("%d",&k);
		if (k!=n) { cerr << "BAD\n"; return 1; }
		REP(i,n) scanf("%d",aa+i);
		printf("%s\n",solve()?"GOOD":"BAD");
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}