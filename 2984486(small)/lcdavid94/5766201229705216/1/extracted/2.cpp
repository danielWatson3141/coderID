#include<cstdio>
#include<cstring>
using namespace std;
int f[1100][1100],t[1100][1100];
int check(int p,int r)
{
	if (t[p][r]>0) return t[p][r];
	if (r>0&&f[p][0]<3) return (t[p][r]=1);
	int m1=1,m2=1;
	for (int i=1;i<=f[p][0];++i)
	  if (f[p][i]!=r)
	  {
	  	if (check(f[p][i],p)>m2)
	  		if (t[f[p][i]][p]>=m1)
	  			{
	  				m2=m1;
	  				m1=t[f[p][i]][p];
	  			}
	  		else m2=t[f[p][i]][p];
	  }
	return (t[p][r]=m1+m2+1);
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		for (int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			f[x][++f[x][0]]=y;
			f[y][++f[y][0]]=x;
		}
		int m=1;
		for (int i=1;i<=n;++i)
			if (f[i][0]>1)
			{
				int x=check(i,0);
				if (x>m) m=x;
			}
		printf("Case #%d: %d\n",TT,n-m);
	}
}
