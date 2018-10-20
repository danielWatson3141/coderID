#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define real int

bool findTimes;
vector<string> outletSet;
vector<string> deviceSet;
int N,L;
vector<bool> switchSet;
int innerCount;

struct record
{
	vector<string> cset;
	vector<bool> sset;
};

void changeOneFlip(int pos)
{
	for(int i=0;i<outletSet.size();i++)
	{
		if(outletSet[i][pos]=='0')
		{
			outletSet[i][pos]='1';
		}
		else outletSet[i][pos]='0';
	}
}

bool checkEqual()
{
	sort(outletSet.begin(),outletSet.end());
	for(int i=0;i<outletSet.size();i++)
	{
		if(outletSet[i]!=deviceSet[i])
		{
			return false;
		}
	}
	return true;
}


int checkoutlet0(int pos)
{
	int count=0;
	for(int i=0;i<outletSet.size();i++)
	{
		if(outletSet[i][pos]=='0') count++;
	}
	return count;
}

int checkDevice0(int pos)
{
	int count=0;
	for(int i=0;i<deviceSet.size();i++)
	{
		if(deviceSet[i][pos]=='0') count++;
	}
	return count;
}

void DFS(bool* whether,int depth,int count)
{
	if(findTimes) return;

	if(checkEqual())
	{
		findTimes=true;
		innerCount=count;
		return;
	}


	changeOneFlip(depth);
	if(checkEqual())
	{
		findTimes=true;
		innerCount=count+1;
		return;
	}
	changeOneFlip(depth);

	int next=-1;
	for(int i=depth+1;i<L;i++)
	{
		if(whether[i]==true)
		{
			next=i;
			break;
		}
	}
	if(next==-1) return;
	DFS(whether,next,count);
	changeOneFlip(depth);
	DFS(whether,next,count+1);
	changeOneFlip(depth);
	return;
	
}

int getTimes()
{
	sort(deviceSet.begin(),deviceSet.end());
	int count=0;
	bool* whether=new bool[L];
	memset(whether,0,L);
	for(int i=0;i<L;i++)
	{
		int k1=checkoutlet0(i);
		int k2=checkDevice0(i);

		if(k1==k2)
		{
			if((k1+k2)==N) whether[i]=true;
			else continue;
		}
		else if((k1+k2)==N)
		{
			count++;
			changeOneFlip(i);
		}
		else return -1;
	}

	if(checkEqual())
	{
		return count;
	}
	innerCount=0;
	int start=0;
	for(int i=0;i<L;i++)
	{
		if(whether[i])
		{
			start=i;
			break;
		}
	}
	DFS(whether,start,0);
	if(findTimes) return innerCount+count;
	return -1;
}

void main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	
	int times;
	scanf("%d",&times);
	for(int time=1;time<=times;time++)
	{
		scanf("%d %d",&N,&L);
		char s[150];
		findTimes=false;
		outletSet.clear();
		deviceSet.clear();
		for(int i=0;i<N;i++)
		{
			scanf("%s",s);
			string str=s;
			outletSet.push_back(str);
		}
		
		for(int i=0;i<N;i++)
		{
			scanf("%s",s);
			string str=s;
			deviceSet.push_back(str);
		}


		printf("Case #%d: ",time); 
		
		int k=getTimes();
		if(k>=0) printf("%d\n",k);
		else printf("NOT POSSIBLE\n");

	}
}