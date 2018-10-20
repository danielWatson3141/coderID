#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <set>

using namespace std;

const int MAXN = 150;
const int MAXL = 45;

int n, L;
long long org[MAXN], obj[MAXN];
set<long long> sst;

inline int GetBit(long long x, int n)
{
	return (x >> n) & 1;
}

long long GetInput()
{
	string ss;
	cin >> ss;
	long long ret = 0;
	for (int i = 0; i < L; i ++)
		ret |= (ss[i] == '1'? 1LL: 0) << i;
	return ret;
}

int Check(long long base)
{
	sst.clear();
	for (int i = 0; i < n; i ++)
		sst.insert(obj[i]);
	for (int i = 0; i < n; i ++)
	{
		long long tmp = org[i] ^ base;
		if (sst.find(tmp) == sst.end())
			return 1000;
		sst.erase(tmp);
	}
	return 0;
}

int Work()
{
	cin >> n >> L;
	string ss;
	for (int i = 0; i < n; i ++)
		org[i] = GetInput();
	for (int i = 0; i < n; i ++)
		obj[i] = GetInput();
	int mn = 1000;
	for (int i = 0; i < n; i ++)
	{
		n --;
		swap(obj[i], obj[n]);
		int base = 0;
		long long res = 0;
		for (int j = 0; j < L; j ++)
			if (GetBit(org[n], j) != GetBit(obj[n], j))
				res |= (1LL << j), base ++;
		mn = min(mn, base + Check(res));
		swap(obj[i], obj[n]);
		n ++;
	}
	return mn;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, ret;
	cin >> T;
	for (int tt = 1; tt <= T; tt ++)
	{
		cout << "Case #" << tt << ": ";
		if ((ret = Work()) > 100) cout << "NOT POSSIBLE" << endl;
		else cout << ret << endl;
	}
	return 0;
}