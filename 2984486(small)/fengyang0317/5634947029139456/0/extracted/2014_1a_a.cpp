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

void read(int &x)
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
bool eq(int *a,int *b,int l)
{
	for(int i=0;i<l;i++)
		if(a[i]!=b[i])return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cout<<(1<<1);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out1.txt","w",stdout);
	int cas;
	int ki,i,j;
	int n,l,r,sum;
	int a[N],b[N],c[N];
	scanf("%d",&cas);
	for(ki=1;ki<=cas;ki++)
	{
		printf("Case #%d: ",ki);
		cin>>n>>l;
		r=9999;
		for(i=0;i<n;i++)
			read(a[i]);
		for(i=0;i<n;i++)
			read(b[i]);
		sort(b,b+n);
		for(i=0;i<(1<<l);i++)
		{
			for(j=0;j<n;j++)
				c[j]=a[j]^i;
			sort(c,c+n);
			if(eq(b,c,n))
			{
				sum=0;
				for(j=0;j<l;j++)
					if(i&(1<<j))sum++;
				if(sum<r)r=sum;
			}
		}
		if(r==9999)puts("NOT POSSIBLE");
		else cout<<r<<endl;
	}
	return 0;
}