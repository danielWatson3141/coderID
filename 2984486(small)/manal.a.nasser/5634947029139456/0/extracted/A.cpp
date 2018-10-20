#include <map>
#include <set>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define OO ((int)1e9)
#define sz 10010

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

void flip(int idx, vector<int> &v) {
	for (int i = 0; i < v.size(); ++i)
		v[i] ^= (1 << idx);
}

bool doesMatch(vector<int> v1, vector<int> v2) {
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	int TS, N, L;
	scanf("%d", &TS);
	for (int ts = 1; ts <= TS; ++ts) {
		scanf("%d %d", &N, &L);
		int minFlips = 100;
		char ch;
		vector<int> v, r;
		for (int i = 0; i < N; ++i) {
			int x = 0;
			for (int j = 0; j < L; ++j) {
				cin >> ch, x |= ((ch - '0') << j);

			}
			v.push_back(x);
		}

		for (int i = 0; i < N; ++i) {
			int x = 0;
			for (int j = 0; j < L; ++j) {
				cin >> ch, x |= ((ch - '0') << j);
			}
			r.push_back(x);
		}

		sort(all(r));
		for (int i = 0; i < (1 << L); ++i) {
			int flips = 0;
			for (int j = 0; j < L; ++j) {
				if (i & (1 << j)) {
					flips++;
					flip(j, v);
				}
			}
			sort(all(v));
			if (doesMatch(v, r))
				minFlips = min(flips, minFlips);
			for (int j = 0; j < L; ++j) {
				if (i & (1 << j)) {
					flip(j, v);
				}
			}
		}
		if (minFlips < 100)
			printf("Case #%d: %d\n", ts, minFlips);
		else
			printf("Case #%d: NOT POSSIBLE\n", ts);
	}
	return 0;
}
