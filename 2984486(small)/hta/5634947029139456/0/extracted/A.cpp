#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int get()
{
	int f=0;int v=0;char ch;
	while(!isdigit(ch=getchar()));v=ch-48;
	while(isdigit(ch=getchar()))v=v*10+ch-48;
	if(f==1)return -v;else return v;
}
const int maxn=200000;
int n,tot;
double p[maxn];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T=get();
	for(int t=1;t<=T;t++)
	{
		n=get();tot=get();
		double tp=1,ans=tot+2;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&p[i]);
			tp*=p[i];
			double x=tp*(n-i+tot-i+1)+(1-tp)*(n-i+tot-i+1+tot+1);
			//printf("%.10lf\n",x);
			ans=min(ans,x);
		}
		printf("Case #%d: %.10lf\n",t,ans);
	}
	return 0;
}
