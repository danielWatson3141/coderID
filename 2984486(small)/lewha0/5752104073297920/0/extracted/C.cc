#include<stdio.h>

int A[120][1000], B[120], C[120], N, T;

void FindMin(int M)
{
	int l1, l2, idx;

	for(l1 = 0; l1 < M; l1++)
	{
		idx = -1;
		for(l2 = 0; l2 < T; l2++)
		{
			if(C[l2]) continue;
			if(idx == -1 || B[l2] < B[idx]) idx = l2;
		}
		if(idx == -1) return;
		C[idx] = 1;
	}
}

void FindMax(int M)
{
	int l1, l2, idx;

	for(l1 = 0; l1 < M; l1++)
	{
		idx = -1;
		for(l2 = 0; l2 < T; l2++)
		{
			if(C[l2]) continue;
			if(idx == -1 || B[l2] > B[idx]) idx = l2;
		}
		if(idx == -1) return;
		C[idx] = 1;
	}
}

int main(void)
{
	int l0, l1;

	scanf("%d", &T);
	for(l0 = 0; l0 < T; l0++)
	{
		scanf("%d", &N);
		for(l1 = 0; l1 < N; l1++)
		{
			scanf("%d", &A[l0][l1]);
		}
		for(l1 = 0; l1+1 < N; l1++)
		{
			int delta;

			if(A[l0][l1] >= l1+1) delta = (l1+1)-A[l0][l1];
			else delta = A[l0][l1];
			B[l0] += delta * delta;
		}
	}

	FindMin(60);

	for(l0 = 0; l0 < T; l0++)
	{
		printf("Case #%d: ", l0+1);
		if(C[l0]) printf("BAD");
		else printf("GOOD");
		printf("\n");
	}
	return 0;
}
