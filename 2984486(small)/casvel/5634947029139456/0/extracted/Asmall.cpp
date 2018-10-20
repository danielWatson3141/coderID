#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <vector>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define MP make_pair
#define INF (1<<30)

using namespace std;

typedef pair <int, int> ii;

string outlet[15], device[15];
int N, L;

bool empareja(int i, int j, int mask)
{
	For(k, 0, L)
		if (mask & (1<<k))
		{
			if (device[i][k] == outlet[j][k])
				return false;
		}
		else
		{
			if (device[i][k] != outlet[j][k])
				return false;
		}

	return true;
}

int count(int mask)
{
	int r = 0;
	For(i, 0, 15)
		if (mask & (1<<i))
			r++;

	return r;
}

int check(int mask)
{
	bitset <15> usado;
	usado.reset();

	For(i, 0, N)
	{
		bool match = false;
		For(j, 0, N)
		{
			if (usado[j])
				continue;

			match = empareja(i, j, mask);
			if (match)
			{
				usado[j] = true;
				break;
			}
		}

		if (!match)
			return INF;
	}

	return count(mask);
}

int main()
{
	int T;

	scanf("%d", &T);

	For(caso, 1, T+1)
	{
		scanf("%d %d", &N, &L);

		For(i, 0, N)
			cin >> outlet[i];
		For(i, 0, N)
			cin >> device[i];

		int best = INF;
		For(mask, 0, 1<<10)
			best = min(best, check(mask));

		if (best != INF)
			printf("Case #%d: %d\n", caso, best);
		else
			printf("Case #%d: NOT POSSIBLE\n", caso);
	}

	return 0;
}