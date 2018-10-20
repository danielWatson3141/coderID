#include<stdio.h>

int T;
int A[11][11];
int B[11][11];
int C[11], D[11];
int E[11];
int N, M;
int Answer;

void Go(int Dep)
{
	int l1, l2;

	if(Dep == N)
	{
		for(l1 = 0; l1 < M; l1++) E[l1] = 0;
		for(l1 = 0; l1 < N; l1++)
		{
			for(l2 = 0; l2 < M; l2++)
			{
				if(A[D[l1]][l2] != B[l1][l2]) E[l2] = 1;
			}
		}

		for(l1 = 0; l1 < N; l1++)
		{
			for(l2 = 0; l2 < M; l2++)
			{
				if(B[l1][l2] != (A[D[l1]][l2] + E[l2]) % 2) break;
			}
			if(l2 < M) break;
		}
		if(l1 < N) return;

		int curr = 0;
		for(l1 = 0; l1 < M; l1++) if(E[l1]) curr++;
		if(curr < Answer) Answer = curr;
		// A[D[l1]
	}
	else
	{
		int l1;

		for(l1 = 0; l1 < N; l1++)
		{
			if(C[l1]) continue;
			C[l1] = 1;
			D[Dep] = l1;
			Go(Dep+1);
			C[l1] = 0;
		}
	}
}

int main(void)
{
	int l0, l1, l2;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d %d", &N, &M);
		for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++) scanf("%1d", &A[l1][l2]);
		for(l1 = 0; l1 < N; l1++) for(l2 = 0; l2 < M; l2++) scanf("%1d", &B[l1][l2]);
		for(l1 = 0; l1 < N; l1++) C[l1] = 0;
		Answer = 12341234;
		Go(0);

		printf("Case #%d: ", l0);
		if(Answer == 12341234)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			printf("%d\n", Answer);
		}
	}
	return 0;
}
