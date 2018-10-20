#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

char buf[1000];

LL read()
{
	scanf("%s", buf);
	int n = strlen(buf);
	LL res = 0;
	for (int i = 0; i < n; i++)
	{
		res *= 2;
		if (buf[i] == '1') res++;
	}
	return res;
}

inline bool bit(int n, LL x)
{
	return (x & (1 << n)) != 0;
}

int solvecase()
{
	int n, l;
	scanf("%d%d", &n, &l);
	vector<LL> devs;
	for (int i = 0; i < n; i++) devs.push_back(read());
	vector<LL> outs;
	for (int i = 0; i < n; i++) outs.push_back(read());
	sort(devs.begin(), devs.end());
	int res = 1000;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int k = 0;
			for (int z = 0; z < l; z++)
				if (bit(z, devs[i]) != bit(z, outs[j]))
					k++;
			LL mask = devs[i] ^ outs[j];
			vector<LL> outs2;
			for (int q = 0; q < n; q++)
				outs2.push_back(outs[q] ^ mask);
			sort(outs2.begin(), outs2.end());
			if (outs2 == devs)
				res = min(res, k);
		}
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int res = solvecase();
		if (res == 1000)
			printf("Case #%d: NOT POSSIBLE\n", i + 1);
		else
			printf("Case #%d: %d\n", i + 1, res);
	}
	return 0;
}
