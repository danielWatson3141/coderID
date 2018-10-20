#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

int tc;
void solve() {
	int N;
	scanf("%d", &N);
	
	double lho = 0.0;
	REP(i, N) {
		int bil;
		scanf("%d", &bil);
		if (i == 0 || i == N-1) continue;
		int left, right;
		left = i+1;
		right = left + 200;
		if (left <= bil && bil <= right) lho += 1;
		else lho -= 0.25;
	}
	printf("Case #%d: ", tc);
	if (lho >= 0) puts("BAD");
	else puts("GOOD");
}

int main() {
	int T;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) solve();
	return 0;
}
