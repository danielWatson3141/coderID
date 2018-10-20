#include <stdio.h>

const int N = 1005;

struct Node
{
	int v;
	Node *next;
} *G[N];

void ME(int a, int b) { Node *p = new Node; p->v = b; p->next = G[a]; G[a] = p; }

int dfs(int r, int from)
{
	int fst = N, snd = N;
	int cnt = 0, tmp;
	Node *p;
	for (p = G[r]; p; p = p->next)
		if (p->v != from)
		{
			tmp = dfs(p->v, r);
			if (tmp < fst)
			{
				snd = fst;
				fst = tmp;
			}
			else if (tmp < snd)
				snd = tmp;
			cnt++;
		}

	if (cnt <= 1) return -1;
	else return fst + snd - 1;
}

int main()
{
	int T, C;
	int n, a, b, i;
	int tmp, ans;
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) G[i] = NULL;
		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &a, &b);
			ME(a-1, b-1);
			ME(b-1, a-1);
		}

		ans = N;
		for (i = 0; i < n; i++)
		{
			tmp = dfs(i, -1);
			if (tmp <= ans)
				ans = tmp;
		}
		printf("Case #%d: ", C);
		printf("%d\n", n + ans);
	}
	return 0;
}
