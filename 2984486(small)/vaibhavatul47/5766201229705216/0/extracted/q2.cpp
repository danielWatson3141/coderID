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

bool edge[20][20] = {0};
bool tmp[20][20];
int n;
int ans;

void solve(vector<bool> &flag, int i)
{
	if (i == n+1) {
		int a = 0;
		for (int k = 1; k <= n; k++) {
			if (flag[k]) a++;
		}

		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= n; k++) 
				tmp[j][k] = edge[j][k];

		for (int j = 1; j <= n; j++) {
			if (flag[j]) {
				for (int k = 1; k <= n; k++) {
					tmp[k][j] = 0;
					tmp[j][k] = 0;
				}
			}
		}
		int cnt[20] = {0};
		
		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= n; k++)
				if (tmp[j][k]) cnt[j]++;

		int cnt2[20] = {0};
		for (int j = 1; j <= n; j++) {
			cnt2[cnt[j]]++;
		}

		if (n-a == 1 || (cnt2[1] + cnt2[2] + cnt2[3] == n - a && 
				(cnt2[1] == 2 || cnt2[1] == 4 || cnt2[1] == 8)
				&& cnt2[2] == 1)) {
			ans = min(ans, a);
		}

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
		cin >> n;
		// cout << n << endl;
		int a, b;
		for (int i = 1; i <= n-1; i++) {
			cin >> a >> b;
		//	 cout << a << " " << b << endl;
			edge[a][b] = edge[b][a] = 1;
			tmp[a][b] = tmp[b][a] = 1;
		}
		vector<bool> flag(n+1, false);
		if (n > 1) {
			ans = 1000;
			solve(flag, 0);
		}
		else ans = 0;
		
		cout << "Case #" << t << ": " << ans << endl;
	}
	
	return 0;
}
