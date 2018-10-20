#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;
vector<int>grand(int num)
{
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		vec.push_back(i);
	}
	for(int i=0;i<num;i++)
	{
		swap(vec[i],vec[rand()%(num-i)+i]);
	}
	return vec;
}
vector<int>brand(int num)
{
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		vec.push_back(i);
	}
	for(int i=0;i<num;i++)
	{
		swap(vec[i],vec[rand()%num]);
	}
	return vec;
}
map<vector<int>,int>ma;
typedef pair<int,vector<int>>piv;/*
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<100000;i++)
	{
		ma[brand(num)]++;
	}
	vector<piv>vec;
	map<vector<int>,int>::iterator it=ma.begin();
	for(;;)
	{
		if(it==ma.end())
		{
			break;
		}
		vec.push_back(make_pair((*it).second,(*it).first));
		it++;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<vec[i].second.size();j++)
		{
			printf("%d",vec[i].second[j]);
		}
		printf("   %d",vec[i].first);
		printf("\n");
	}
}*/
typedef pair<int,int>pii;
bool ans[120];
int main()
{
	FILE *fr=fopen("C-small-attempt10.in","r");
	FILE *fw=fopen("out1.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	vector<pii>vec;
	for(int p=0;p<data;p++)
	{
		int num;
		fscanf(fr,"%d",&num);
		int sum=0;
		vector<int>arr;
		for(int i=0;i<num;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			arr.push_back(zan);
			sum+=abs(i-zan);
		}
		vec.push_back(make_pair(sum,p));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size()/2;i++)
	{
		ans[vec[i].second]=false;
	}
	for(int i=vec.size()/2;i<vec.size();i++)
	{
		ans[vec[i].second]=true;
	}
	for(int i=0;i<vec.size();i++)
	{
		printf("%d\n",vec[i].first);
		if(ans[i])
		{
			fprintf(fw,"Case #%d: GOOD\n",i+1);
		}
		else
		{
			fprintf(fw,"Case #%d: BAD\n",i+1);
		}
	}
}