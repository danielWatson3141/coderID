#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<map>
#define  SS struct S
#define SN struct Nn
#define LL long long int

using namespace std;
SS
{
	char O[45];
};

SN
{
	LL n;
	int count;
};
SS S1[155];
SS S2[155];
SN ss[50005];
int nn;
int tt = 1;

int main(void)
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int N,L;
	int T;
	scanf("%d",&T);
	int i,j;
	int k;
	map<LL,int> m;
	map<LL,int>mn;
	while(T--)
	{
		m.clear();
		mn.clear();
		scanf("%d %d",&N,&L);
		for(i=0;i<N;i++)
			scanf("%s",S1[i].O);
		for(i=0;i<N;i++)
			scanf("%s",S2[i].O);
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				LL tmp = 1;
				LL an = 0;
				int ttt = 0;
				for(k=0;k<L;k++)
				{
					if(S1[i].O[k]!=S2[j].O[k])
					{
						ttt++;
						an+=tmp;
					}
					tmp*=2;
				}
				m[an]++;
				mn[an] = ttt;
			}
		int ok = 0;
		int minn = 1e8;
		map<LL,int>::iterator it;
		for(it = m.begin();it!=m.end();it++)
		{
			if(it->second==N)
			{
				if(mn[it->first]<minn)
					minn = mn[it->first];
			}
		}
		printf("Case #%d: ",tt++);
		if(minn==1e8)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			printf("%d\n",minn);
		}

	}


	return 0;
}
