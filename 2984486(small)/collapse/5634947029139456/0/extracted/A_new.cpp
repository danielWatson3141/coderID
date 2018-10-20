#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<cmath>
#include<iostream>
#include<algorithm>
#define LL long long int
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
using namespace std;
int a[20],n,l,d[20];
int calc(char s[],int l)
{
	int i,sum=0;
	for (i=l-1;i>=0;i--)
	{
		if (s[i]=='1')
			sum += (1<<(l-1-i));
	}
	return sum;
	
}
int solve(void)
{
	int i,lim,j,c,min=-1,num=0,co=0,k;
	int cur[20];
	for (i=0;i<n;i++)
	{
		num = d[0]^a[i];
		for (j=0;j<n;j++)
			cur[j] = a[j]^num;
		c=0;
		for (j=0;j<n;j++)
			for (k=0;k<n;k++)
				if (cur[j]==d[k])
					c++;
		if (c==n)
		{
			co=0;
			for (j=0;j<l;j++)
				if (num&(1<<j))
					co++;
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
	char s[200];
	s(t);
	while(t--)
	{
		ca++;
		scanf("%d%d%c",&n,&l,&ch);
		for (i=0;i<n;i++)
		{
			scanf("%s",s);
			a[i] = calc(s,l);
		}
		for (i=0;i<n;i++)
		{
			scanf("%s",s);
			d[i] = calc(s,l);
		}
		ans = solve();
		if (ans==-1)
			printf("Case #%d: NOT POSSIBLE\n",ca);
		else
			printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
