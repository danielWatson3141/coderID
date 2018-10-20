#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

const int inf=999999999;

string st[200],st0[200],solution[200];
int judge[200];
int T,n,l,cs=0;

int main()
{
	freopen("123.in","r",stdin);
	freopen("123.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;i++)cin>>st[i];
		for(int i=1;i<=n;i++)cin>>solution[i];
		sort(solution+1,solution+n+1);
		int ans=inf;
		for(int i=1;i<=n;i++)
		{
			bool flag=true;
			for(int j=0;j<l;j++)if(st[1][j]==solution[i][j])judge[j]=0;else judge[j]=1;
			int cnt=0;
			for(int j=0;j<l;j++)cnt+=judge[j];
			for(int j=1;j<=n;j++)
			{
				st0[j]="";
				for(int k=0;k<l;k++)if(judge[k])st0[j]=st0[j]+char(97-st[j][k]);else st0[j]=st0[j]+st[j][k];
			}
			sort(st0+1,st0+n+1);
			for(int j=1;j<=n;j++)if(st0[j]!=solution[j]){flag=false;break;}
			if(flag)ans=min(ans,cnt);
		}
		printf("Case #%d: ",++cs);
		if(ans==inf)printf("NOT POSSIBLE\n");else printf("%d\n",ans);
	}
	return 0;
}
