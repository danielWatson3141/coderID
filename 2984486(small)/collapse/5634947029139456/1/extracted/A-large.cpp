#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#define LL long long int
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
using namespace std;
int n,l,lim;
int num[50];
char o[200][50],d[200][50];
map<string,int> look;
int calc(int j,int k)
{
	int i,c=0;
	for (i=0;i<l;i++)
		if (o[j][i]!=d[k][i])
		{
			num[c] = i;
			c++;
		}
	return c;
}
bool exist(int in,int co)
{
	int i,j;
	char s[50];
	for (i=0;i<l;i++)
		s[i] = o[in][i];
	s[l] = 0;
	for (i=0;i<co;i++)
	{
		j = num[i];
		if (s[j]=='0')
			s[j] = '1';
		else
			s[j] = '0';
	}
	string st(s);
	if (look.find(st)!=look.end())
		return true;
	return false;
	
}
int solve(void)
{
	int i,j,c,min=-1,co=0,k;
	int cur[20];
	for (i=0;i<n;i++)
	{
		co = calc(i,0);
		c = 0;
		for (j=0;j<n;j++)
		{
			if (exist(j,co))
				c++;
		}

		if (c==n)
		{
			if (min==-1)
				min = co;
			else
				min = (min<co)?min:co;
		}
	}
	return min;
}
int main()
{
	int t,ca=0,ans,i;
	char ch;
	pair<string,int> p;
	s(t);
	while(t--)
	{
		look.clear();
		ca++;
		scanf("%d%d%c",&n,&l,&ch);
		for (i=0;i<n;i++)
			scanf("%s",o[i]);
		for (i=0;i<n;i++)
		{
			scanf("%s",d[i]);
			p = make_pair(d[i],1);
			look.insert(p);
		}
		ans = solve();
		if (ans==-1)
			printf("Case #%d: NOT POSSIBLE\n",ca);
		else
			printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
