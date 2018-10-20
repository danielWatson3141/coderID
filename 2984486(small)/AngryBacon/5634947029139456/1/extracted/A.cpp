#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 100000 + 10;

int n, l;
string a[N], b[N];

int check(string c)
{
	vector<string> sa, sb;
	for(int i = 0; i < n; ++ i) {
		sa.push_back(a[i]);
		string tmp;
		for(int j = 0; j < l; ++ j) {
			char ch = b[i][j];
			if (c[j] == '1') {
				if (ch == '1') ch = '0';
				else ch = '1';
			} else {

			}
			tmp += ch;
		}
		sb.push_back(tmp);
	}
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	for(int i = 0; i < n; ++ i) {
		if (sa[i] != sb[i]) return false;
	}
	return true;
}

void solve(int test)
{
	cerr << test << endl;
	cin >> n >> l;
	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++ i) {
		cin >> b[i];
	}
	int ret = -1;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			string c;
			int cost = 0;
			for(int k = 0; k < l; ++ k) {
				if (a[i][k] != b[j][k]) {
					c += '1';
					++ cost;
				} else {
					c += '0';
				}
			}
			if (check(c)) {
				if (ret < 0) ret = cost;
				else ret = min(ret, cost);
			}
		}
	}
	printf("Case #%d: ", test);
	if (ret == -1) cout << "NOT POSSIBLE" << endl;
	else cout << ret << endl;
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) 
		solve(i);
	fclose(stdout);
	return 0;
}
