#include <cstdio>
#include <algorithm>
#include <vector>
#include<iostream>
#include<map>
#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int MAXN = 1004;
vector<int> V[MAXN];
int n;

pii licz(int a,int s)//zostaje size
{
	int siz=1,wyn=1;
	int m1=-1,m2=-1;
	fru(i,V[a].size())
	{
		if(V[a][i]==s)continue;
		pii p=licz(V[a][i],a);
		siz+=p.y;
		if(m2>p.x)continue;
		if(m1>p.x){m2=p.x;continue;}
		m2=m1;m1=p.x;
	}
	if(m1!=-1 && m2!=-1)wyn=1+m1+m2;
	else wyn=1;
	return pii(wyn,siz);
}
void solve()
{
	int a,b;
	scanf("%d",&n);
	fru(i,n)V[i].clear();
	fru(i,n-1)
	{
		scanf("%d%d",&a,&b);a--;b--;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	int wyn=n;
	fru(i,n)wyn=min(n-licz(i,-1).x,wyn);
	printf("%d\n",wyn);
}
int main()
{
	int t;
	scanf("%d",&t);
	fru(i,t){printf("Case #%d: ",i+1);solve();}

    return 0;
}
