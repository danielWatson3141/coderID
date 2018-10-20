#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int t;
int n;
vector <int> graf[1007];
int pom1, pom2;
int rozm[1007];
bool bylo[1007];
int korz;
int wyn;
int koszt[1007];
int oj[1007];

void licz(int v)
{
	rozm[v]=1;
	bylo[v]=true;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (!bylo[graf[v][i]])
		{
			oj[graf[v][i]]=v;
			licz(graf[v][i]);
			rozm[v]+=rozm[graf[v][i]];
		}
	}
}

void pacz(int v)
{
	bylo[v]=true;
	koszt[v]=0;
	if (graf[v].size()==3 || (graf[v].size()==2 && v==korz))
	{
		for (int i=0; i<graf[v].size(); i++)
		{
			if (!bylo[graf[v][i]])
			{
				pacz(graf[v][i]);
				koszt[v]+=koszt[graf[v][i]];
			}
		}
	}
	if (graf[v].size()==2 || (graf[v].size()==1 && v==korz))
	{
		for (int i=0; i<graf[v].size(); i++)
		{
			if (!bylo[graf[v][i]])
			{
				pacz(graf[v][i]);
				koszt[v]+=rozm[graf[v][i]];
			}
		}
	}
	if (graf[v].size()>3 || (graf[v].size()>2 && v==korz))
	{
		koszt[v]=rozm[v]-1;
		for (int i=0; i<graf[v].size(); i++)
		{
			if (!bylo[graf[v][i]])
			{
				pacz(graf[v][i]);
			}
		}
		for (int i=0; i<graf[v].size(); i++)
		{
			if (graf[v][i]==oj[v])
			continue;
			for (int j=i+1; j<graf[v].size(); j++)
			{
				if (graf[v][j]==oj[v])
				continue;
				if (rozm[v]-1+koszt[graf[v][i]]-rozm[graf[v][i]]+koszt[graf[v][j]]-rozm[graf[v][j]]<koszt[v])
				koszt[v]=rozm[v]-1+koszt[graf[v][i]]-rozm[graf[v][i]]+koszt[graf[v][j]]-rozm[graf[v][j]];
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	for (int h=1; h<=t; h++)
	{
		scanf("%d", &n);
		wyn=n-1;
		for (int i=1; i<=n; i++)
		{
			graf[i].clear();
		}
		for (int i=1; i<n; i++)
		{
			scanf("%d%d", &pom1, &pom2);
			graf[pom1].push_back(pom2);
			graf[pom2].push_back(pom1);
		}
		for (int i=1; i<=n; i++)
		{
			korz=i;
			oj[i]=0;
			for (int j=1; j<=n; j++)
			bylo[j]=false;
			licz(i);
			for (int j=1; j<=n; j++)
			bylo[j]=false;
			pacz(i);
			if (koszt[i]<wyn)
			wyn=koszt[i];
		}
		printf("Case #%d: %d\n", h, wyn);
	}
	return 0;
}
