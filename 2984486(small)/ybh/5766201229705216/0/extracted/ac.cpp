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

struct node
{
	int v,next;
}mapp[maxn*2];

int V[maxn],e;

void addedge(int i,int j)
{
	e++;
	mapp[e].v=j;
	mapp[e].next=V[i];
	V[i]=e;
	
	e++;
	mapp[e].v=i;
	mapp[e].next=V[j];
	V[j]=e;
}

bool cmp(int x,int y)
{
	return x>y;
}

int fa[maxn],q[maxn];
bool b[maxn];

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		int n;
		cin>>n;
		e=0;
		memset(V,0,sizeof(V));
		FOR(i,1,n-1)
		{
			int r1,r2;
			cin>>r1>>r2;
			addedge(r1,r2);
		}
		int ans=0;
		FOR(root,1,n)
		{
			int h=0,t=1;
			memset(q,0,sizeof(q));
			memset(b,0,sizeof(b));
			memset(fa,0,sizeof(fa));
			q[1]=root;
			b[root]=true;
			fa[root]=0;
			while (h<t)
			{
				h++;
				int i=q[h];
				for (int u=V[i];u;u=mapp[u].next)
				{
					int j=mapp[u].v;
					if (!b[j])
					{
						t++;
						q[t]=j;
						b[j]=true;
						fa[j]=i;
					}
				}
			}
			//FORD(v,n,1)
			//	cout<<v<<" "<<fa[v]<<endl;
			VI f[maxn];
			FORD(v,n,1)
			{
				int i=q[v];
				int w=1;
				if (f[i].size()>=2)
					w+=f[i][0]+f[i][1];
				if (f[fa[i]].size()<=2)
					f[fa[i]].PB(w);
				else
					f[fa[i]][2]=w;
				if (f[fa[i]].size()>=3)
					sort(f[fa[i]].begin(),f[fa[i]].end(),cmp);
			}
			ans=max(ans,f[0][0]);
		}
		cout<<n-ans<<endl;
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
