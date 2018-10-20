
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long LL;
const LL MAXSIZE = 10000;
long long a[MAXSIZE], b[MAXSIZE],c[MAXSIZE];
int L;
LL countbit(long long x)
{
	LL ans = 0;
	for (LL i = 0; i < 64; ++i)
	{
		ans += x % 2;
		x = x >> 1;
	}
	return ans;
}
int main()
{
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "in.txt", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	LL T;
	cin >> T;
	for (LL z = 1; z <= T; ++z)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cout << "Case #" << z << ": ";
		LL n;
		cin >> n>>L;
		for (LL i = 0; i < n; ++i)
		{
			string st;
			cin >> st;
			for (LL j = 0; j < L; ++j){
				a[i] = (st[j] - 48) + a[i] * 2;
			}

		}
		for (LL i = 0; i < n; ++i)
		{
			string st;
			cin >> st;
			for (LL j = 0; j < L; ++j){
				b[i] = (st[j] - 48) + b[i] * 2;
			}

		}
		sort(b, b + n);
		LL sol = MAXSIZE;
		for (LL i = 0; i < n; ++i)
		{
			long long temp = a[0] ^ b[i];
			if (countbit(temp) > sol)
				continue;
			for (LL j = 0; j < n; ++j)
			{
				c[j] = a[j] ^ temp;
			}
			sort(c, c + n);
			bool flag = false;
			for (LL j = 0; j < n; ++j)
			{
				if (c[j] != b[j])
					flag = true;
			}
			if (flag == false)
			{
				if (countbit(temp) < sol) sol = countbit(temp);
			}
		}
		if (sol == MAXSIZE)
			cout << "NOT POSSIBLE" << endl;
		else cout << sol << endl;
	}

}
