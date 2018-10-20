#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define coutpoint6 setiosflags(ios::fixed)<<setprecision(6)

#define maxn 1010
//#define INF 100000000
//#define maxm 1000000
//#define MM 1000000007

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

short a[20000][1000],b[20000][1000],p[1000],x[1000];

int main()
{
	srand((int)time(NULL));
	
	freopen("C-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	const int N=1000;
	REP(i,20000)
	{
		REP(k,N)
			a[i][k] = k;
		REP(k,N)
		{
			int pp = (rand()%(N-k))+k;
			swap(a[i][k], a[i][pp]);
		}
	}
	
	REP(i,20000)
	{
		REP(k,N)
			b[i][k] = k;
		REP(k,N)
		{
			int pp = (rand()%N);
			swap(b[i][k], b[i][pp]);
		}
	}
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		int n;
		cin>>n;
		REP(i,n)
			cin>>p[i];
		LL w1=0,w2=0;
		/*REP(i,20000)
			REP(j,n)
				w1+=(p[j]-a[i][j])*(p[j]-a[i][j]);
		REP(i,20000)
			REP(j,n)
				w2+=(p[j]-b[i][j])*(p[j]-b[i][j]);*/
		/*memset(x,0,sizeof(x));
		REP(i,n)
			x[p[i]]=i;
		REP(i,20000)
			REP(j,n)
				w1+=abs(x[a[i][j]]-j);
		REP(i,20000)
			REP(j,n)
				w2+=abs(x[b[i][j]]-j);*/
		REP(i,20000)
			REP(j,n)
				w1+=(a[i][j]==p[j])?1:0;
		REP(i,20000)
			REP(j,n)
				w2+=(b[i][j]==p[j])?1:0;
		if (w1<=w2)
			cout<<"GOOD\n";
		else
			cout<<"BAD\n";
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
