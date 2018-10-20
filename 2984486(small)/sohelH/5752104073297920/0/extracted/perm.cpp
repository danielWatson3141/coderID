/*
* Google Code Jam 2014
* @author: Sohel Hafiz
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

int main() {
	int test, cases = 1;
	cin >> test;
	vector<int> v;
	for (cases = 1; cases <= test; cases++) {
		int n;
		cin >> n;
		int ok = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (a == i) ok++;
		}
		v.push_back(ok);
	}
	vector<int> v2 = v;
	sort(v2.begin(), v2.end());
	int mid = v2[ v2.size() / 2] - 1;

	int cnt0 = 0;
	for (int i = 0; i < 1000; i++) if (v[i] >= mid) cnt0++;

	mid++;
	int cnt1 = 0;
	for (int i = 0; i < 1000; i++) if (v[i] >= mid) cnt1++;

	mid++;
	int cnt2 = 0;
	for (int i = 0; i < 1000; i++) if (v[i] >= mid) cnt2++;

	cnt0 = abs(500 - cnt2);
	cnt1 = abs(500 - cnt1);
	cnt2 = abs(500 - cnt2);

	int m = mid - 2;
	if (cnt1 < cnt0) m = mid - 1;
	if (cnt2 < cnt1 && cnt2 < cnt0) m = mid;

	mid = m;

	for (int cases = 1; cases <= test; cases++) {
		if (v[cases-1] >= mid) printf("Case #%d: GOOD\n", cases);
		else printf("Case #%d: BAD\n", cases);
	}
	return 0;
}
