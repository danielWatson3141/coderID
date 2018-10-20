#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define M 100000
#define N 1000
int a[M][N],b[N],n;

void gen()
{
	int i,p,j;
	FOR(j,0,M-1)
	{
		FOR(i,0,N-1)a[j][i]=i;
		FOR(i,0,N-1)
		{
			p=rand()%N;
			swap(a[j][i],a[j][p]);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,i,ii,count,j;
	srand(time(0));
	gen();
	scanf("%d",&T);
	FOR(ii,1,T)
	{
		scanf("%d",&n);
		FOR(i,0,N-1)scanf("%d",b+i);
		printf("Case #%d: ",ii);
		count=0;
		FOR(i,0,M-1)
		{
			FOR(j,0,N-1)
			{
				if(a[i][j]==b[j])count++;
			}
		}
		//cout<<count<<endl;
		if(count>M+850)puts("BAD");else puts("GOOD");
	}
}