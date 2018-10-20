#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int N;
int From[2005], To[2005], Next[2005], Node[1005], nE; 
int Size[1005];

void InsertEdge(int A, int B)
{
	From[nE] = A;
	To[nE] = B;
	Next[nE] = Node[A];
	Node[A] = nE ++;
}

void SizeForRoot(int x, int Par)
{
	Size[x] = 1;
	for (int i = Node[x]; i != -1; i = Next[i])
		if (To[i] != Par)
		{
			SizeForRoot(To[i], x);
			Size[x] += Size[To[i]];
		}
}

int AnsForRoot(int x, int Par)
{
	int Cnt = 0;
	for (int i = Node[x]; i != -1; i = Next[i])
		if (To[i] != Par)
			Cnt ++;
	if (Cnt == 0)
		return 0;

	int CntSize = 0;
	for (int i = Node[x]; i != -1; i = Next[i])
		if (To[i] != Par)
			CntSize += Size[To[i]];
	
	if (Cnt == 1)
		return CntSize;

	int Min1 = 10000000, Min2 = 10000000;
	for (int i = Node[x]; i != -1; i = Next[i])
		if (To[i] != Par)
		{
			int t = AnsForRoot(To[i], x) - Size[To[i]];
			if (t < Min1)
			{
				Min2 = Min1; 
				Min1 = t;
			}
			else if (t < Min2)
				Min2 = t;
		}
	return CntSize + Min1 + Min2;
}

void Work()
{
	scanf("%d", &N);
	memset(Node, -1, sizeof(Node));
	nE = 0;
	for (int i = 0; i < N - 1; i ++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		A --;
		B --;
		InsertEdge(A, B);
		InsertEdge(B, A);
	}
	int Ans = 1000000000;
	for (int i = 0; i < N; i ++)
	{
		SizeForRoot(i, -1);
		Ans = min(Ans, AnsForRoot(i, -1));
	}
	printf("%d\n", Ans);
	fflush(stdout);
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    for (int Case = 1; Case <= Cases; Case ++)
    {
		printf("Case #%d: ", Case);
		Work();
    }
    return 0;
}