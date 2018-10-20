#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

string outlet[200];
string device[200];

int go(int cnt, int depth, int N, int L)
{
	if (L == depth) {
		sort(outlet, outlet+N);
		sort(device, device+N);
		int matched = 0;

		for(int i = 0; i < N; ++i) {
			if(outlet[i] == device[i]) ++matched;
		}
		if(matched == N) {
			return cnt;
		}
		return 10000;
	}

	int ret = go(cnt, depth+1, N, L);

	for(int i = 0; i < N; ++i) {
		outlet[i][depth] = (outlet[i][depth] == '1') ? '0' : '1';
	}

	int ret2 = go(cnt+1, depth+1, N, L);

	for(int i = 0; i < N; ++i) {
		outlet[i][depth] = (outlet[i][depth] == '1') ? '0' : '1';
	}	

	return min(ret, ret2);

}


void solve()
{
	int N,L;
	cin >> N >> L;

	for(int i = 0; i < N; ++i) {
		cin >> outlet[i];
	}
	for(int i = 0; i < N; ++i) {
		cin >> device[i];
	}

	int cnt = go(0, 0, N, L);
	if (cnt == 10000) {
		cout << "NOT POSSIBLE" << endl;
	}
	else {
		cout << cnt << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}