#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 160;
const int maxlen = 50;

char a[maxn+1][maxlen+1],b[maxn+1][maxlen+1],
	yao[maxn+1][maxlen+1];
bool done[maxn+1];
bool fan[maxn+1];
int n,L;
int result;

void init()
{
	int i;
	scanf("%d%d",&n,&L);
	for (i=1; i<=n; ++i)
		scanf("%s",a[i]);
	for (i=1; i<=n; ++i)
		scanf("%s",yao[i]);
}

bool pp() //b and yao
{
	int i,j,k;
	bool same;
	for (i=1; i<=n; ++i)
		done[i]=false;
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=n; ++j)
			if (!done[j])
			{
				same=true;
				for (k=0; k<L; ++k)
					if (b[i][k]!=yao[j][k])
					{
						same=false;
						break;
					}
				if (same)
				{
					done[j]=true;
					break;
				}
			}
		if (j>n)
			return false;
	}
	return true;
}

void work()
{
	int i,j,k,cur;
	bool success;
	result=-1;
	for (i=1; i<=n; ++i)
	{
		cur=0;
		for (j=0; j<L; ++j)
			if (a[1][j]==yao[i][j])
				fan[j]=false;
			else {
				fan[j]=true;
				++cur;
			}
		if ((result!=-1)&&(cur>=result))
			continue;
		for (j=1; j<=n; ++j)
		{
			strcpy(b[j],a[j]);
			for (k=0; k<L; ++k)
				if (fan[k])
				{
					if (b[j][k]=='0')
						b[j][k]='1';
					else b[j][k]='0';
				}
		}
		if (pp())
			if ((result==-1)||(cur<result))
				result=cur;
	}
}

void output()
{
	if (result==-1)
		printf("NOT POSSIBLE\n");
	else printf("%d\n",result);
}

int main()
{
	int i,T;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (i=1; i<=T; ++i)
	{
		printf("Case #%d: ",i);
		init();
		work();
		output();
	}
	return 0;
}