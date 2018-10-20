#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int N, L;
char str[50];
long long S[200], T[200], Tmp[200];

void Work()
{
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i ++)
	{
		scanf("%s", str);
		S[i] = 0;
		for (int p = 0; p < L; p ++)
			S[i] = S[i] * 2LL + (str[p] == '1');
	}
	for (int i = 0; i < N; i ++)
	{
		scanf("%s", str);
		T[i] = 0;
		for (int p = 0; p < L; p ++)
			T[i] = T[i] * 2LL + (str[p] == '1');
	}
	sort(T, T + N);
	int Ans = 1000000;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
		{
			long long G = S[i] ^ T[j];
			memcpy(Tmp, S, sizeof(S));
			int Cur = 0;
			for (int p = 0; p < L; p ++)
				if (G & (1LL << p))
				{
					Cur ++;
					for (int k = 0; k < N; k ++)
						Tmp[k] ^= 1LL << p;
				}
			if (Cur > Ans)
				continue;
			sort(Tmp, Tmp + N);
			int Flag = 1;
			for (int k = 0; k < N; k ++)
				if (Tmp[k] != T[k])
					Flag = 0;
			if (Flag)
				Ans = Cur;
		}
	if (Ans < 10000)
		printf("%d\n", Ans);
	else
		printf("NOT POSSIBLE\n");
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    for (int Case = 1; Case <= Cases; Case ++)
    {
		printf("Case #%d: ", Case);
		Work();
    }
    return 0;
}