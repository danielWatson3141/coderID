#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN (160)
#define MAXL (44)
#define MAXN2 (MAXN * MAXN)

typedef long long ll;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef vector <PII> VP;

int T;
int N, L;

char O[MAXN][MAXL];
char D[MAXN][MAXL];
PIP B[MAXN2];
int bn;

int V[MAXN * 2];
VP edge[MAXN * 2];
int from[MAXN * 2];
int rit;

int cap[MAXN2];
int flow[MAXN2];
int sume[MAXN2];
int used[MAXN2];
int en;

inline int nbits(int a)
{
	int c = 0;
	while(a > 0)
	{
		++c;
		a -= a & -a;
	}
	return c;
}

bool cmpf(PIP a, PIP b)
{
	int na = nbits(a.first);
	int nb = nbits(b.first);
	if(na != nb)
		return na < nb;

	if(a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

int check()
{
	int f = 0;
	int i;

	for(i = 0; i < 2*N; ++i)
		used[i] = 0;

	while(f < N)
	{
/*
		printf("\nLoop %d\n", f);

		printf("Edges\n");
		for(i = 0; i < 2*N; ++i)
		{
			int sz = edge[i].size();
			for(j = 0; j < sz; ++j)
			{
				int e = edge[i][j].first;
				printf("%d -> %d   e %d  flow %d\n", i, sume[e] - i, e, flow[e]);
			}
		}
		printf("\n");
//*/

		queue <int> Q;

		++rit;

		for(i = 0; i < N; ++i) // source side
		{
			if(!used[i])
			{
				Q.push(i);
				V[i] = rit;
				from[i] = -1;
			}
		}

		int r = -1;
		while(!Q.empty() && r == -1)
		{
			int p = Q.front();
			Q.pop();

//			printf("pop %d\n", p);

			int sz = edge[p].size();
			for(i = 0; i < sz; ++i)
			{
				PII ee = edge[p][i];
				int e = ee.first;
				int s = ee.second;

//				printf("%d -> %d,%d\n", p, e, s);

				if((s == 0 && cap[e]) || (s == 1 && flow[e]))
				{
					int a = sume[e] - p;
//					printf("%d -> %d\n", p, a);

					if(a >= N && !used[a])
					{
						from[a] = e;
						r = a;
						break;
					}

					if(V[a] != rit)
					{
						V[a] = rit;
						from[a] = e;
						Q.push(a);
					}
				}
			}
		}

		if(r == -1)
			break;

//		printf("\nr %d\n", r);
		used[r] = 1;

		while(from[r] != -1)
		{
//			printf("%d -- %d\n", r, from[r]);
			int e = from[r];
			int rr = sume[e] - r;

			cap[e] = !cap[e];
			flow[e] = !flow[e];

			r = rr;
		}

//		printf("end %d\n", r);
		used[r] = 1;

		++f;
	}

//	printf("f %d\n", f);

	return f == N;
}

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i, j, k;
		scanf("%d %d", &N, &L);
		for(i = 0; i < N; ++i)
			scanf("%s", O[i]);
		for(i = 0; i < N; ++i)
			scanf("%s", D[i]);

//		int N2 = N*N;

		bn = 0;
		for(i = 0; i < N; ++i)
		{
			for(j = 0; j < N; ++j)
			{
				int b = 0;
				for(k = 0; k < L; ++k)
				{
					b <<= 1;
					b += (O[i][k] != D[j][k]);
				}

				B[bn++] = PIP(b, PII(i, j));
			}
		}

		int sol = -1;

		sort(B, B + bn, cmpf);
		for(i = j = 0; i < bn; j = i)
		{
			while(i < bn && B[i].first == B[j].first)
				++i;

			if(i - j < N) // impossible for B[i].first
				continue;

			for(k = 0; k < N; ++k)
			{
				V[k] = 0;
				edge[k].clear();
			}
			en = 0;

//			printf("%d (%d):\n", B[j].first, nbits(B[j].first));
			for(k = j; k < i; ++k)
			{
//				printf("%s - %s\n", O[B[k].second.first], D[B[k].second.second]);

				int a = B[k].second.first;
				int b = B[k].second.second + N;

				edge[a].push_back(PII(en, 0));
				edge[b].push_back(PII(en, 1));
				cap[en] = 1;
				flow[en] = 0;
				sume[en] = a + b;
				++en;
			}

			int okay = 1;
			for(k = 0; k < 2*N; ++k)
			{
				if(edge[k].size() == 0)
				{
					okay = 0;
					break;
				}
			}

			if(okay && check())
			{
				sol = nbits(B[j].first); // solution found
				break;
			}
		}

		printf("Case #%d: ", TT);
		if(sol == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", sol);
	}

	return 0;
}
