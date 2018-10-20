#include <cstdio>
#include <set>

using namespace std;
set<long long> Sety;
long long convert(char *p)
{
	int i=0;
	long long r=0;
	while(p[i])
	{
		if(p[i]=='1')
		r|=(1<<i);
		i++;
	}
	return r;
}

int main()
{
	//freopen("ainput","r",stdin);
	int t,T,i,j,k,r,w,N,L;
	char s[64];
	long long u,v,x[150],y[150];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d",&N,&L);
		for(i=0;i<N;i++)
		{
			scanf("%s",s);
			x[i]=convert(s);
		}
		Sety.clear();
		for(i=0;i<N;i++)
		{
			scanf("%s",s);
			y[i]=convert(s);
			Sety.insert(y[i]);
		}
		r = L+1;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				u = x[i]^y[j];
				for(k=0;k<N;k++)
				{
					v=x[k]^u;
					if(Sety.find(v)==Sety.end())
						break;
				}
				if(k!=N) continue;
				w=0;
				for(k=0;k<L;k++)
				{
					if(u&(1<<k)) w++;
				}
				if(w<r) r=w;
			}
		}
		printf("Case #%d: ",t);
		if(r>L) printf("NOT POSSIBLE\n");
		else printf("%d\n",r);
	}
	return 0;
}
