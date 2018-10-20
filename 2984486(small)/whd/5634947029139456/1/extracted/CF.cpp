#include <iostream>
#include <map>
#include <bitset>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdio>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long big;
const int N=550,M=50;
int n,m,cas;
big from[N],to[N],now[N];
string str;
vector<big>a,b;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.txt","w",stdout);
	int cass,i,j,k;
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		printf("Case #%d: ",cass);
		scanf("%d%d",&n,&m);
		memset(from,0,sizeof(from));
		memset(to,0,sizeof(to));
		for(i=1;i<=n;i++)
		{
			cin>>str;
			for(j=0;j<m;j++)
			{
				from[i]<<=1;
				from[i]+=str[j]-'0';
			}
		}

		for(i=1;i<=n;i++)
		{
			cin>>str;
			for(j=0;j<m;j++)
			{
				to[i]<<=1;
				to[i]+=str[j]-'0';
			}
		}
		int ans=1<<20;
		for(i=1;i<=n;i++)
		{
			int cnt=0;
			for(j=1;j<=n;j++)
				now[j]=from[j];
			for(j=0;j<m;j++)
			if((from[1]>>j&1)^(to[i]>>j&1))
			{
				cnt++;
				for(k=1;k<=n;k++)
					now[k]^=(1<<j);
			}
			a.clear();
			b.clear();
			for(j=2;j<=n;j++)
				a.pb(now[j]);
			for(j=1;j<=n;j++)
				if(j!=i)
					b.pb(to[j]);
			sort(a.begin(),a.end());
			sort(b.begin(),b.end());
			if(a==b)
				ans=min(ans,cnt);
		}
		if(ans==(1<<20))puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
}
