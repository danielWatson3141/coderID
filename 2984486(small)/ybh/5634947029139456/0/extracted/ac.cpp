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

#define maxn 200
//#define INF 100000000
//#define maxm 1000000
//#define MM 1000000007

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

LL a[maxn],c[maxn],a1[maxn];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		int n,len;
		cin>>n>>len;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		FOR(i,1,n)
			REP(j,len)
			{
				char bit;
				cin>>bit;
				a[i]=(a[i]<<1)+(bit-'0');
			}
		sort(a+1,a+n+1);
		FOR(i,1,n)
			REP(j,len)
			{
				char bit;
				cin>>bit;
				c[i]=(c[i]<<1)+(bit-'0');
			}
		sort(c+1,c+n+1);
		int ans=1000;
		FOR(p,1,n)
		{
			LL cha=a[p]^c[1];
			memset(a1,0,sizeof(a1));
			FOR(i,1,n)
				a1[i]=a[i]^cha;
			sort(a1+1,a1+n+1);
			bool flag=true;
			FOR(i,1,n)
				if (a1[i]!=c[i])
				{
					flag=false;
					break;
				}
			if (flag)
			{
				int count=0;
				while (cha)
				{
					count+=cha&1;
					cha>>=1;
				}
				ans=min(ans,count);
			}
		}
		if (ans==1000)
			cout<<"NOT POSSIBLE\n";
		else
			cout<<ans<<endl;
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
