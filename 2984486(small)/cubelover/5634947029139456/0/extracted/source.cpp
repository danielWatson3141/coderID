#include<cstdio>
#include<set>

char t[200][200];
char a[200][200];
char b[200][200];

struct str
{
	char s[200];
} temp;

inline bool operator <(const str &x,const str &y)
{
	int i;
	for(i=0;x.s[i]||y.s[i];i++)if(x.s[i]!=y.s[i])break;
	return x.s[i]<y.s[i];
}

std::multiset<str> S;
std::multiset<str>::iterator it;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int i,j,k,n,m,min=100,now;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)scanf("%s",t[i]);
		for(i=0;i<n;i++)scanf("%s",b[i]);
		for(i=0;i<n;i++)
		{
			now=0;
			for(j=0;j<n;j++)for(k=0;k<m;k++)a[j][k]=t[j][k];
			for(j=0;j<m;j++)if(a[0][j]!=b[i][j])
			{
				now++;
				for(k=0;k<n;k++)a[k][j]^=1;
			}
			S.clear();
			for(j=0;j<n;j++)
			{
				for(k=0;k<m;k++)temp.s[k]=a[j][k];
				S.insert(temp);
			}
			for(j=0;j<n;j++)
			{
				for(k=0;k<m;k++)temp.s[k]=b[j][k];
				it=S.find(temp);
				if(it==S.end())break;
				S.erase(it);
			}
			if(j<n)continue;
			if(min>now)min=now;
		}
		if(min==100)printf("Case #%d: NOT POSSIBLE\n",tc);
		else printf("Case #%d: %d\n",tc,min);
	}
	return 0;
}