#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int n=1000;
double p[2][n][n];
void print(double a[n][n])
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%f%c",a[i][j]*n,j<n-1?'\t':'\n');

		}
	}
	printf("\n");
}
int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	freopen("C-table.out","w",stdout);
	ios::sync_with_stdio(false);
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			p[0][i][j]=i==j;
		}
	}
	for (k=0;k<n;k++)
	{
		memset(p[1],0,sizeof(p[1]));
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (i!=k)
				{
					p[1][i][j]+=1.0/n*(n-1)*p[0][i][j];
					p[1][i][j]+=1.0/n*1*p[0][k][j];
				}
				else
				{
					int l;
					for (l=0;l<n;l++)
					{
						p[1][i][j]+=1.0/n*1*p[0][l][j];
					}
				}
			}
		}
		memcpy(p[0],p[1],sizeof(p[0]));
	}
	print(p[0]);
	return 0;
}
