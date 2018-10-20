#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
#define INF 10000000
int count(ll a)
{
	int ret=0;
	for(int i=0;i<50;i++)
	{
		ret+=a%2;
		a/=2;
	}
	return ret;
}
int main()
{
	FILE *fr=fopen("A-large.in","r");
	FILE *fw=fopen("out1.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		fprintf(fw,"Case #%d: ",p+1);
		int num,len;
		fscanf(fr,"%d%d",&num,&len);
		vector<ll>v1,v2;
		for(int i=0;i<num;i++)
		{
			ll now=0;
			for(int j=0;j<len;j++)
			{
				char zan;
				fscanf(fr," %c",&zan);
				now*=2;
				now+=zan-'0';
			}
			v1.push_back(now);
		}
		for(int i=0;i<num;i++)
		{
			ll now=0;
			for(int j=0;j<len;j++)
			{
				char zan;
				fscanf(fr," %c",&zan);
				now*=2;
				now+=zan-'0';
			}
			v2.push_back(now);
		}
		int mini=INF;
		sort(v2.begin(),v2.end());
		for(int i=0;i<num;i++)
		{
			ll tim=v1[0]^v2[i];
			vector<ll>vec;
			for(int j=0;j<num;j++)
			{
				vec.push_back(v1[j]^tim);
			}
			sort(vec.begin(),vec.end());
			if(vec==v2)
			{
				mini=min(mini,count(tim));
			}
		}
		if(mini==INF)
		{
			fprintf(fw,"NOT POSSIBLE\n");
		}
		else
		{
			fprintf(fw,"%d\n",mini);
		}
	}
}