#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[1000];
vector<int>ko[1000];
bool flag[1000];
#define INF 100000000
void dfs(int node)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
			//printf("pat:%d %d\n",node,pat[node][i]);
		}
	}
}
int calc(int node)
{
	if(ko[node].size()<=1)
	{
		return 1;
	}
	int m1=0,m2=0;
	for(int i=0;i<ko[node].size();i++)
	{
		int zan=calc(ko[node][i]);
		if(zan>=m1)
		{
			m2=m1;
			m1=zan;
		}
		else
		{
			if(zan>=m2)
			{
				m2=zan;
			}
		}
	}
	return m1+m2+1;
}
int main()
{
	FILE *fr=fopen("B-large.in","r");
	FILE *fw=fopen("out1.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		fprintf(fw,"Case #%d: ",p+1);
		int num;
		fscanf(fr,"%d",&num);
		for(int i=0;i<num;i++)
		{
			pat[i].clear();
		}
		for(int i=0;i<num-1;i++)
		{
			int za,zb;
			fscanf(fr,"%d%d",&za,&zb);
			za--;
			zb--;
			pat[za].push_back(zb);
			pat[zb].push_back(za);
		}
		int maxi=0;
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
			{
				ko[j].clear();
				flag[j]=false;
			}
			dfs(i);
			maxi=max(maxi,calc(i));
			//printf("ddd:%d\n",calc(i));
		}
		fprintf(fw,"%d\n",num-maxi);
	}
}