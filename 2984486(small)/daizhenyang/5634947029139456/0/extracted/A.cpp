#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
vl a,b;
int main()
{
	freopen("C:\\competition\\R1A\\A-small-attempt0.in","r",stdin);
	freopen("C:\\competition\\R1A\\A.out","w",stdout);
	int i,j,k;
	int cas,cc=0,n,l;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&l);
		a.clear();
		b.clear();
		for (i=0;i<n;i++)
		{
			char s[50];
			scanf("%s",s);
			ll x=0;
			for (j=0;j<l;j++)
			{
				x=x*2+s[j]-'0';
			}
			a.pb(x);
		}
		for (i=0;i<n;i++)
		{
			char s[50];
			scanf("%s",s);
			ll x=0;
			for (j=0;j<l;j++)
			{
				x=x*2+s[j]-'0';
			}
			b.pb(x);
		}
		sort(all(a));
		sort(all(b));
		int ans=100;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				ll t=a[i]^b[j];
				vl c;
				for (k=0;k<n;k++)
				{
					c.pb(a[k]^t);
				}
				sort(all(c));
				if (c==b)
				{
					ans=min(ans,__builtin_popcountll(t));
				}
			}
		}
		if (ans==100)printf("Case #%d: NOT POSSIBLE\n",++cc);
		else printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
		