/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int n;
ld dp[1005][1005];
ld P[1005][1005];
int u[130];
ld res[130];
int ans[130];

bool cmp(int x,int y)
{
	return res[x]<res[y];
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	n=1000;
	ld p=1.0/n;
	for(int num=0;num<n;num++)
	{
		memset(dp,0,sizeof dp);
		dp[0][num]=1;
		for(int i=1;i<=n;i++)
		{
			//double cnt=0;
			for(int j=0;j<n;j++)
			{
				if (j==i-1)
				{
					dp[i][j]=p;
				} else
				{
					dp[i][j]=dp[i-1][j]*(1-p)+dp[i-1][i-1]*p;
				}
				//printf("%d %d %.3lf\n",i,j,dp[i][j]);
			//	cnt+=dp[i][j];
			}
			//if (fabs(cnt-1)>eps) fprintf(stderr,"Err %d\n",i);
		}
		for(int i=0;i<n;i++) P[num][i]=dp[n][i];
	}
	fputs("OK\n",stderr);
	
	int T=0;
	scanf("%d",&T);
	ld st=0;
	for(int i=1;i<=n;i++) st-=log(n);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		res[tt]=0;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			res[tt]+=log(P[x][i]);
		}
		if (res[tt]<=st) printf("Case #%d: GOOD\n",tt); else printf("Case #%d: BAD\n",tt);
	}
	/*
	for(int i=0;i<T;i++) u[i]=i;
	sort(u,u+T,cmp);
	for(int i=0;i<T/2;i++) ans[u[i]]=1;
	for(int i=0;i<T;i++) if (ans[i]) printf("Case #%d: GOOD\n",i+1); else printf("Case #%d: BAD\n",i+1);
	*/
	return 0;
}
