#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n,m;
char ch1[200][50],ch2[200][50];
bool com(string s1[],string s2[])
{
	sort(s1+1,s1+n+1);
	sort(s2+1,s2+n+1);
	for(int i=1;i<=n;i++)
	{
		if(s1[i]!=s2[i])
		{
			return false;
		}
	}
	return true;
}
int solve(string s1[],string s2[],int now,int step)
{
	if(com(s1,s2)==true)
	{
		return step;
	}
	if(now>=m) return inf;
	int cal1=0,cal2=0;
	for(int i=1;i<=n;i++)
	{
		cal1+=s1[i][now]-'0';
		cal2+=s2[i][now]-'0';
	}
	if(cal1==cal2 && n-cal1==cal2)
	{
		int get1=solve(s1,s2,now+1,step);
		string nows1[200];
		 
		for(int i=1;i<=n;i++)
		{
			nows1[i]=s1[i];
			if(nows1[i][now]=='0') nows1[i][now]='1';
			else nows1[i][now]='0';
		}
		int get2=solve(nows1,s2,now+1,step+1);
		return min(get1,get2);
	}
	else if(cal1==cal2)
	{
		return solve(s1,s2,now+1,step);
	}
	else if(n-cal1==cal2)
	{
		string nows1[200];
		 
		for(int i=1;i<=n;i++)
		{
			nows1[i]=s1[i];
			if(nows1[i][now]=='0') nows1[i][now]='1';
			else nows1[i][now]='0';
		}
		return solve(nows1,s2,now+1,step+1);
	}
	else return inf;
}
string s1[200],s2[200];
int main()
{
    int i,j,k;
    int t;
    freopen("A-small-attempt1.in","r",stdin);
	freopen("A-output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			//scanf("%s",ch1[i]);
			cin>>s1[i];
		}
		for(i=1;i<=n;i++)
		{
			//scanf("%s",ch2[i]);
			cin>>s2[i];
		}
		sort(s2+1,s2+n+1);
		int get=solve(s1,s2,0,0);
		if(get==inf)
		{
			printf("Case #%d: NOT POSSIBLE\n",tcase);
		}
		else
		{
			printf("Case #%d: %d\n",tcase,get);
		}
    }
    fclose(stdin);
    fclose(stdout);
}
