#include <cstdio>
#include <cstring>
#define MAXN 152
#define MAXL 42
using namespace std;

// Candinate
typedef struct{
	int k,len;
	int dig[MAXL];
}CD;
CD cd[MAXN][MAXN];

// outlet
char ol[MAXN][MAXL];

// device
char dv[MAXN][MAXL];

// Used
bool used[MAXN];

// Main
int main(void)
{
	int tc,cs,n,L,i,j,k,d,ans;
	bool ok;

	// Read input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d%d",&n,&L);
		for(i=0;i<n;i++)
			scanf("%s",ol[i]);
		for(i=0;i<n;i++)
			scanf("%s",dv[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cd[i][j].k=j;
				cd[i][j].len=0;
				for(k=0;k<L;k++)
					if(ol[i][k]!=dv[j][k])
						cd[i][j].dig[cd[i][j].len++]=k;
			}
		}

		ans=(int)1e9;
		ok=false;
		for(i=0;i<n;i++)
		{
			memset(used,false,n*sizeof(bool));
			used[cd[0][i].k]=true;
			for(j=1;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(cd[0][i].len==cd[j][k].len)
					{
						for(d=0;d<cd[0][i].len;d++)
							if(cd[0][i].dig[d]!=cd[j][k].dig[d]) break;
						if(d<cd[0][i].len) continue;
						break;
					}
				}
				if(k<n) used[cd[j][k].k]=true;
				else break;
			}
			if(j<n) continue;
			else
			{
				ok=true;
				if(cd[0][i].len<ans) ans=cd[0][i].len;
			}
		}
		printf("Case #%d: ",cs);
		if(!ok) puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
	return 0;
}