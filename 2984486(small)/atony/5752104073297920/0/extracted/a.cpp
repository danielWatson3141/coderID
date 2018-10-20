#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 1011;
const int MAXM = 2000001;
const int MAXK = 50;
const int INF = 10005;

int a[MAXN];
int b[MAXN];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T,cas,i,j,flag,n;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			b[i]=i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		flag=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]==b[i])
				flag=1;
			else
			{
				for(j=i+1;j<n;j++)
					if(b[j]==a[i])
						break;
				swap(b[j],b[i]);
			}
		}
		printf("Case #%d: ",cas);
		if(flag==0)
			printf("GOOD\n");
		else
			printf("BAD\n");
	}
	return 0;
}