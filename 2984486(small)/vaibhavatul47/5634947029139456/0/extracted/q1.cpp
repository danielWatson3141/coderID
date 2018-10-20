#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <stack>
#include <queue>

#define PB push_back
#define MP make_pair
#define all(v) v.begin(), v.end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, b, a) for (int i = b; i > a; i--)
#define Si(a) scanf("%d", &(a))
#define Sl(a) scanf("%lld", &(a))
#define SZ size()
#define F first
#define S second
#define B begin()
#define E end()

#define mod 1000000007

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T>
T power(T a, int n)
{
	T res = 1;
	while (n) {
		if (n % 2 == 1) res = (res * a) % mod;
		n /= 2;
		a = (a * a) % mod;
	}
	return res;
}

string ini[11];
string fin[11];
string tmp[11];
int n, l;
int ans;

void solve(vector<bool> &flag, int i)
{
	if (i == l) {
		int c = 0, a = 0;
		for (int k = 0; k < l; k++)
			if (flag[k]) a++;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < l; k++) {
				tmp[j][k] = !flag[k] ? ini[j][k] : (ini[j][k] == '0' ? '1' : '0');
			}
		}
		sort(tmp, tmp + n);
		for (int j = 0; j < n; j++) {
			if (tmp[j] == fin[j]) {
				c++;
			}
		}
		if (c == n) ans = min(ans, a);
		return;
	}

	solve(flag, i+1);
	flag[i] = !flag[i];
	solve(flag, i+1);
	flag[i] = !flag[i];
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> ini[i];
			tmp[i] = ini[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> fin[i];
		}
		sort(fin, fin + n);
		ans = 1000000;
		vector<bool> flag(l, false);

		solve(flag, 0);
		if (ans == 1000000) {
			cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
		}
		else {
			cout << "Case #" << t << ": " << ans << endl;
		}
	}
	
	return 0;
}
