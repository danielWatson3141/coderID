#include<stdio.h>
#include<vector>

using namespace std;

vector< int > A[1000];
int N;
int T;
int B[1000], D[1000];
int Ret;

void Go(int l1, int par)
{
	int index, l2;
	int idx1 = -1, idx2 = -1;

	B[l1] = 1;
	for(index = 0; index < (int)A[l1].size(); index++)
	{
		l2 = A[l1][index];
		if(l2 == par) continue;
		Go(l2, l1);
		B[l1] += B[l2];

		if(idx1 == -1)
		{
			idx1 = l2;
		}
		else
		{
			if(idx2 == -1)
			{
				if(B[idx1]-D[idx1] < B[l2]-D[l2])
				{
					idx2 = idx1;
					idx1 = l2;
				}
				else
				{
					idx2 = l2;
				}
			}
			else
			{
				if(B[idx1] - D[idx1] < B[l2]-D[l2])
				{
					idx2 = idx1;
					idx1 = l2;
				}
				else if(B[idx2] - D[idx2] < B[l2]-D[l2])
				{
					idx2 = l2;
				}
			}
		}
	}

	if(idx1 == -1 || idx2 == -1)
	{
		D[l1] = B[l1]-1;
	}
	else
	{
		D[l1] = B[l1]-1 - B[idx1] + D[idx1] - B[idx2] + D[idx2];
	}
}

int main(void)
{
	int l0, l1, t1, t2;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d", &N);
		for(l1 = 0; l1 < N; l1++) A[l1].clear();
		for(l1 = 1; l1 < N; l1++)
		{
			scanf("%d %d", &t1, &t2);
			t1--;
			t2--;
			A[t1].push_back(t2);
			A[t2].push_back(t1);
		}

		Ret = N;
		for(l1 = 0; l1 < N; l1++)
		{
			Go(l1, -1);
			if(D[l1] < Ret) Ret = D[l1];
		}

		printf("Case #%d: %d\n", l0, Ret);
	}
}
