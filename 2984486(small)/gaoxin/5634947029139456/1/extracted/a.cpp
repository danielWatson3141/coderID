#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

int tests,n,m;
int cg[155];
char a[155][45],b[155][45],c[155][45];
char *p[155], *q[155];

int cmp(char *a, char *b)
{
	for (int i=0;i<m;i++)
		if (a[i]<b[i]) return 1;
		else if (a[i]>b[i]) return 0;
	return 0;
}

int main()
{
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%s",a[i]);
		for (int i=1;i<=n;i++) scanf("%s",b[i]);
		int ans = m+1;
		for (int gx=1;gx<=n;gx++)
		{
			//printf("gx=%d\n",gx);
			for (int j=0;j<m;j++)
				if (a[1][j]==b[gx][j]) cg[j] = 0;
				else cg[j] = 1;
			for (int i=1;i<=n;i++)
			{
				for (int j=0;j<m;j++)
					if (cg[j])
						if (a[i][j]=='0') c[i][j] = '1';
						else c[i][j] = '0';
					else
						c[i][j] = a[i][j];
				c[i][m] = 0;
			}
			//for (int i=1;i<=n;i++) printf("a:%s\n",a[i]);
			//for (int i=1;i<=n;i++) printf("b:%s\n",b[i]);
			//for (int i=1;i<=n;i++) printf("c:%s\n",c[i]);
			
			for (int i=1;i<=n;i++) p[i] = c[i], q[i] = b[i];
			sort(p+1,p+n+1,cmp);
			sort(q+1,q+n+1,cmp);
			//for (int i=1;i<=n;i++) printf("%s %s\n",p[i],q[i]);
			int same = 1;
			for (int i=1;i<=n;i++) if (cmp(q[i],p[i]) || cmp(p[i],q[i])) same = 0;
			if (same)
			{
			//printf("@\n");
				int cnt = 0;
				for (int j=0;j<m;j++)
					if (cg[j])
						cnt++;
				//printf("cnt=%d\n",cnt);
				ans = min(ans, cnt);
			}
		}
		if (ans==m+1)
			printf("Case #%d: NOT POSSIBLE\n", test);
		else
			printf("Case #%d: %d\n", test, ans);
	}

	
	return 0;
}
