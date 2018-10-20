#include <cstdio>
#include <algorithm>
#include <vector>

#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;

const int MAXN = 1005,inf=1<<20;
int n;
vector<int> V[MAXN];

pii dfs(int u, int pr) //(zeby u zostal korzeniem, rozmiar poddrzewa u)
{
	vector<int> D;
	pii ans(0,1);
	tr(it,V[u]) if(*it!=pr)
	{
		pii c=dfs(*it,u);
		ans.y+=c.y;
		D.push_back(c.x-c.y);
	}
	sort(D.begin(),D.end());
	ans.x=ans.y-1;
	if(D.size()>=2) ans.x+=D[0]+D[1];
	return ans;
}
int rozmiar(int a)
{
	return (1<<(a+1))-1;
}
int solve()
{
	int ret=n-1;
	fru(i,n)
	{
		pii c=dfs(i,-1);
		ret=min(ret,c.x);
	}
	return ret;
}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 scanf("%d",&n);
		 fru(i,n) V[i].clear();
		 fru(i,n-1)
		 {
			 int a,b;
			 scanf("%d%d",&a,&b);
			 --a;--b;
			 V[a].push_back(b);
			 V[b].push_back(a);
		 }
		 printf("%d\n",solve());
	}
    return 0;
}
