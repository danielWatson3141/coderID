#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;
int T,n,l,ans;
char s1[200][200],s2[200][200];
bool vis[200];
bool check()
{
	int i,j,k;
	char tmp;
	for (i=2;i<=n;++i)
	{
		bool flag=1;
		for (j=1;j<=n && flag;++j)
		{
			for (k=1;k<=l;++k)
			{
				if (vis[k])
				{
					if (s1[j][k]=='0')
						tmp='1';
					else
						tmp='0';
				}
				else
					tmp=s1[j][k];
				if (tmp!=s2[i][k])
					break;
			}
			if (k>l) flag=0;
		}
		if (flag) return 0;
	}
	return 1;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		scanf("%d%d",&n,&l);
		for (i=1;i<=n;++i)
			scanf("%s",s1[i]+1);
		for (i=1;i<=n;++i)
			scanf("%s",s2[i]+1);
		ans=l+1;
		for (i=1;i<=n;++i)
		{
			int tmp=0;
			for (j=1;j<=l;++j)
				if (s1[i][j]!=s2[1][j])
					++tmp,vis[j]=1;
				else
					vis[j]=0;
			if (check())
				ans=min(ans,tmp);
		}
		printf("Case #%d: ",ii);
		if (ans==l+1) puts("NOT POSSIBLE");
		else
			printf("%d\n",ans);
	}
	
	//system("pause");
	return 0;
}
