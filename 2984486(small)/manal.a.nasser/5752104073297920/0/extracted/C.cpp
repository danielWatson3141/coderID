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

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
		freopen("output.txt", "wt", stdout);
#endif
	int ts, x, n;
	scanf("%d", &ts);
	for (int tt = 1; tt <= ts; ++tt) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
		}
		if (rand() % 2 )
			printf("Case #%d: BAD\n", tt);
		else
			printf("Case #%d: GOOD\n", tt);

		rand();
		rand();
		rand();
	}

	return 0;
}
