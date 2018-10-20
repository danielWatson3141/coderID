#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXL 200
#define MAXN 200

int T,N,L;
char Buf[MAXL];
struct array
{
	int D[MAXL];
	int &operator [] (int n)
	{
		return D[n];
	}
	
	const int &operator [] (int n) const
	{
		return D[n];
	}
	
}A[MAXN],B[MAXN],C,D[MAXN];


void array_xor(array &A, const array &B)
{
	int i;
	for (i=0;i<L;i++)
	{
		A[i] ^= B[i];
	}
}

void array_scan(array *A)
{
	int i,j;
	for (i=0;i<N;i++)
	{
		scanf("%s",Buf);
		for (j=0;j<L;j++)
		{
			A[i][j] = Buf[j] == '1';
		}
	}
}

int Ans;

bool cmp(const array &A,const array &B)
{
	int i;
	for (i=0;i<L;i++)
	{
		if (A[i] < B[i])
		{
			return true;
		}
		if (A[i] > B[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%d%d",&N,&L);
		array_scan(A);
		array_scan(B);
		sort(B,B + N,cmp);
		Ans = L + 1;
		for (i=0;i<N;i++)
		{
			int flip = 0;
			for (j=0;j<L;j++)
			{
				if (A[0][j] != B[i][j])
				{
					C[j] = 1;
					flip ++;
				}
				else
				{
					C[j] = 0;
				}
			}
			memcpy(D,A,sizeof A[0] * N);
			for (j=0;j<N;j++)
			{
				array_xor(D[j],C);
			}
			sort(D,D + N, cmp);
			bool same = 1;
			for (j=0;j<N;j++)
				for (k=0;k<L;k++)
				{
					if (D[j][k] != B[j][k])
					{
						same = 0;
						goto ANS;
					}
				}
		ANS:
			if (same)
			{
				Ans = min(Ans, flip);
			}
		}
		printf("Case #%d: ",cases);
		if (Ans < L+1)
		{
			printf("%d",Ans);
		}
		else
		{
			printf("NOT POSSIBLE");
		}
		printf("\n");
	}
    return 0;
}
