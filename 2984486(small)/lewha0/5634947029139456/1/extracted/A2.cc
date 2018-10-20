#include<stdio.h>

long long A[150], B[150];
long long C;
int N, M;
int T;

long long P[50];
int Answer;

int main(void)
{
	int l0, l1, l2, l3, l4;
	int bit;

	P[0] = 1;
	for(l1 = 1; l1 < 50; l1++) P[l1] = P[l1-1] + P[l1-1];

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		fprintf(stderr, "...%d / %d\n", l0, T);
		scanf("%d %d", &N, &M);
		Answer = 1234;
		for(l1 = 0; l1 < N; l1++)
		{
			A[l1] = 0;
			for(l2 = 0; l2 < M; l2++)
			{
				scanf("%1d", &bit);
				if(bit) A[l1] += P[l2];
			}
		}
		for(l1 = 0; l1 < N; l1++)
		{
			B[l1] = 0;
			for(l2 = 0; l2 < M; l2++)
			{
				scanf("%1d", &bit);
				if(bit) B[l1] += P[l2];
			}
		}

		for(l1 = 0; l1 < N; l1++)
		{
			C = 0;
			int curr = 0;
			for(l2 = 0; l2 < M; l2++)
			{
				if((A[0] & P[l2]) != (B[l1] & P[l2]))
				{
					C += P[l2];
					curr++;
				}
			}
			if(curr >= Answer) continue;

			for(l2 = 0; l2 < N; l2++)
			{
				for(l3 = 0; l3 < N; l3++)
				{
					if(B[l2] == (A[l3]^C)) break;
				}
				if(l3 == N) break;
			}
			if(l2 < N) continue;

			Answer = curr;
		}

		printf("Case #%d: ", l0);
		if(Answer == 1234)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			printf("%d\n", Answer);
		}
	}
}
