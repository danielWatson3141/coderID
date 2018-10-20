#include <bits/stdc++.h>
#define fi "A.INP"
#define fo "A.OUT"
#define nmax 150+5
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,ll> II;
typedef vector<II> VII;
typedef map<ll,int> MM;
//VARIABLES
int n,m,res,x[nmax],y[nmax],test;
ll val,a[nmax],b[nmax];
bool check[nmax];
VII c[nmax];
MM my_map;
char s[nmax];
//PROTOTYPES

void Process();

//MAIN
int main()
{
	int tc;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&tc);
       while (tc--)
	{
		Process();
		fprintf(stderr,"%d\n",test);
	}
       return 0;
}

//FUNCTIONS
bool DFS(int k)
{
	VII::iterator it;
	if (k==0) return true;
	check[k]=false;
	for (it=c[k].begin();it!=c[k].end();++it)
	if (it->second==val)
	if (check[y[it->first]])
	if (DFS(y[it->first]))
	{
		x[k]=it->first;
		y[it->first]=k;
		return true;
	}
	return false;
}
bool Matching()
{
	int cnt=0,cnt_=1;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	while (cnt!=cnt_)
	{
		cnt_=cnt;
		memset(check,true,sizeof(check));
		for (int i=1;i<=n;++i)
		if (x[i]==0)
		if (DFS(i)) ++cnt;
	}
	return (cnt==n);
}
int Get(string st)
{
	ll S=0;
	for (int i=0;i<m;++i) S=S*2+ll(st[i]-'0');
	return S;
}
void Process()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%s",s);
		a[i]=Get(string(s));
	}
	for (int i=1;i<=n;++i)
	{
		scanf("%s",s);
		b[i]=Get(string(s));
	}
	my_map.clear();
	res=INF;
	for (int i=1;i<=n;++i) c[i].clear();
	for (int i=1;i<=n;++i)
	for (int j=1;j<=n;++j)
	{
		++my_map[a[i]^b[j]];
		c[i].push_back(II(j,a[i]^b[j]));
	}
	for (MM::iterator it=my_map.begin();it!=my_map.end();++it)
	if ((it->second>=n) && (__builtin_popcount(it->first)<res))
	{
		val=it->first;
		if (Matching()) res=__builtin_popcount(it->first);
	}
	if (res!=INF) printf("Case #%d: %d\n",++test,res); else printf("Case #%d: NOT POSSIBLE\n",++test);
}
