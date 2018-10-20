#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;
 int B[170],D[100];
char S[100];
int L;	
int pow2()
{
	int k,t=1;
	int ans=0;
	
	for(k=L-1;k>=0;k--)
	{
		ans += (S[k]-'0')*t;
		t *=2;
	}
	return ans;
}

int re(int x)
{
	int i;
	i = 0;
	while(x)
	{
		i += x%2;
		x /=2;
	}
	return i;
}


int main()
{
	int T,N,i,j,k;
	int C[100];
	int x;
	int min = 1000;
	
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		min = 1000;
		scanf("%d %d",&N,&L);
		for(i=0;i<N;i++)
		{
			B[i] = 0;
			scanf("%s",S);
			B[i] = pow2();
		}
		for(i=0;i<N;i++)
		{
			D[i] = 0;
			scanf("%s",S);
			D[i] = pow2();
		}
		sort(D,D+N);
		for(i=0;i<N;i++)
		{
			x = B[0]^D[i];
			C[0]= D[i];
			for(j=1;j<N;j++)
			{
				C[j] = B[j]^x; 
			}
			sort(C,C+N);
 			j=0;
			while( j<N && (C[j]==D[j]) )
			j++;
			if(j==N)
			{
				if(min>re(x))
				min = re(x);
			}
		}	
		if(min==1000)	
		printf("Case #%d: NOT POSSIBLE\n",k);
		else
		printf("Case #%d: %d\n",k,min);
	}
	return 0;
}
