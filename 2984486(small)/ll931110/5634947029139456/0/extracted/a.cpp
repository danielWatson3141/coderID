#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

set<string> s;
int flip[55];
string device[205],outlet[205];
int n,L,T;

void solveCase(int it) {
	scanf("%d %d", &n, &L);
	for (int i = 0; i < n; i++) cin >> device[i];
	for (int i = 0; i < n; i++) cin >> outlet[i];
	s.clear();
	for (int i = 0; i < n; i++) s.insert(device[i]);
	
	int ret = 1 << 20;
	// device 0 must match some outlet i
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < L; j++) {
			flip[j] = (device[0][j] != outlet[i][j]);
			cnt += flip[j];			
		}
		if (cnt >= ret) continue;
		bool matched = true;
		for (int j = 0; j < n; j++) {			
			string perform = outlet[j];
			for (int k = 0; k < L; k++) if (flip[k]) {
				if (perform[k] == '1') perform[k] = '0'; else perform[k] = '1';
			}
			if (s.find(perform) == s.end()) matched = false;
		}
		if (!matched) continue;
		ret = cnt;
	}
	printf("Case #%d: ", it);
	if (ret > L) cout << "NOT POSSIBLE"; else cout << ret;
	cout << endl;
}

int main() {
	scanf("%d", &T);
	for (int it = 1; it <= T; it++) solveCase(it);
}
