#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAXN=160;
const int MAXL=50;
char ini[MAXN][MAXL];
char fim[MAXN][MAXL];
long long int x[MAXN][MAXN];
int bits[MAXN];
int marc[MAXN];
int main()
{
	int teste;
	scanf("%d",&teste);
	for(int t=1;t<=teste;t++)
	{
		printf("Case #%d: ",t);
		int n,l;
		scanf("%d %d",&n,&l);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
			{
				scanf(" %c",&ini[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
			{
				scanf(" %c",&fim[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				x[i][j]=0;
				int b=0;
				for(int k=0;k<l;k++)
				{
					long long int pot=(1LL<<k);
					if(fim[i][k]!=ini[j][k]) 
					{
						x[i][j]+=pot;
						b++;
					}
				}
				if(j==0) bits[i]=b;	
			}
		}
		int resp=l+1;
		for(int i=0;i<n;i++)
		{
			long long int cur=x[i][0];
			int ok=1;
			for(int j=0;j<n;j++)
			{
				marc[j]=0;
				for(int k=0;k<n;k++)
				{
					if(x[k][j]==cur)
					{
						marc[j]=1;
						break;
					}
				}
				if(marc[j]==0) ok=0;
			}
					
			if(ok==1 && resp>bits[i]) resp=bits[i];
		}	
		if(resp==l+1) printf("NOT POSSIBLE\n");
		else printf("%d\n",resp);
	}
	return 0;
}

