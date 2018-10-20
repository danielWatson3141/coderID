#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cctype>
#include <ctime>
#include <strstream>
#define min(a,b) ((a) < (b) ? (a) : (b)) 
#define max(a,b) ((a) > (b) ? (a) : (b)) 
using namespace std;
#define N 200
#define L 50
typedef long long ll;
int n,l;
ll a[N],b[N],c[N],one;
bool y[L];
void read(ll &x)
{
	char s[999];
	scanf("%s",s);
	x=0;
	int i;
	for(i=0;s[i];i++)
	{
		x=x+x;
		x+=s[i]-'0';
	}
}
bool eq(ll *a,ll *b,int l)
{
	for(int i=0;i<l;i++)
		if(a[i]!=b[i])return 0;
	return 1;
}

bool eq1(int d)
{
	sort(a,a+n);
	int i;
	for(i=0;i<n;i++)
		if((a[i]&(one<<d))!=(b[i]&(one<<d)))return 0;
	return 1;
}
void yh(int p)
{
	ll t=one<<p;
	int i;
	for(i=0;i<n;i++)
		a[i]^=t;
}

int dfs(int p)
{
	int i,r,c0=-10,c1=-10;
	if(p==-1)
	{
		r=0;
		for(i=0;i<l;i++)
			if(y[i])r++;
		return r;
	}
	if(eq1(p))
	{
		y[p]=0;
		c0=dfs(p-1);
	}
	yh(p);
	if(eq1(p))
	{
		y[p]=1;
		c1=dfs(p-1);
	}
	yh(p);
	if(c1==-10&&c0==-10)return -10;
	if(c0==-10)return c1;
	if(c1==-10)return c0;
	return min(c0,c1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cout<<(1<<1);
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	int ki,i,j;
	int sum;
	one=1;
	ll r;
	scanf("%d",&cas);
	for(ki=1;ki<=cas;ki++)
	{
		printf("Case #%d: ",ki);
		cin>>n>>l;
		for(i=0;i<n;i++)
			read(a[i]);
		for(i=0;i<n;i++)
			read(b[i]);
		sort(b,b+n);
		r=dfs(l-1);

		//for(i=0;i<(1<<l);i++)
		//{
		//	for(j=0;j<n;j++)
		//		c[j]=a[j]^i;
		//	sort(c,c+n);
		//	if(eq(b,c,n))
		//	{
		//		sum=0;
		//		for(j=0;j<l;j++)
		//			if(i&(1<<j))sum++;
		//		if(sum<r)r=sum;
		//	}
		//}
		if(r==-10)puts("NOT POSSIBLE");
		else cout<<r<<endl;
	}
	return 0;
}