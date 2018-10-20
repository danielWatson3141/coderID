#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAXN=1010;
vector<int> grafo[MAXN];
int marc[MAXN];
int qtd[MAXN];
int r[MAXN];
void dfs(int v)
{
	marc[v]=1;
	qtd[v]=1;
	r[v]=0;
	int a1=1;
	int a2=1;
	for(int i=0;i<grafo[v].size();i++)
	{
		int prox=grafo[v][i];
		if(marc[prox]==0)
		{
			dfs(prox);
			r[v]+=qtd[prox];
			qtd[v]+=qtd[prox];
			int cur=r[prox]-qtd[prox];
			if(cur<a1)
			{
				a2=a1;
				a1=cur;
			}
			else if(cur<a2) a2=cur;
		}
	}
	if(a2<1) r[v]+=a1+a2;
	//printf("r de %d eh %d  e qtd= %d\n",v,r[v],qtd[v]);
	//if(a2==1) r[v]=qtd[v];
}
int main()
{
	int teste;
	scanf("%d",&teste);
	for(int t=1;t<=teste;t++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		int resp=n;
		for(int i=1;i<=n;i++)
		{
			//printf("III= %d\n",i);
			for(int j=1;j<=n;j++)
			{
				marc[j]=0;
				qtd[j]=-1;
				r[j]=-1;
			}
			dfs(i);
			resp=min(resp,r[i]);
		}
		for(int i=1;i<=n;i++) grafo[i].clear();
		printf("Case #%d: %d\n",t,resp);
	}
	return 0;
}
