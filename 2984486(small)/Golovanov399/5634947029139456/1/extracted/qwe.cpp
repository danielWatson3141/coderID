#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int

using namespace std;

int main(){

	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cout << "Case #" << _ + 1 << ": ";
		int n, l;
		cin >> n >> l;
		vector<string> s(n), t(n);
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int i = 0; i < n; i++) cin >> t[i];
		int ans = -1;
		sort(s.begin(), s.end());
		vector<string> tt(n);
		for (int i = 0; i < n; i++) tt[i] = t[i];
		for (int i = 0; i < n; i++){
			string st = "";
			for (int j = 0; j < l; j++) if (s[0][j] == t[i][j]) st = st + "0"; else st = st + "1";
			int m = 0;
			for (int ii = 0; ii < n; ii++){
				for (int j = 0; j < l; j++) if (st[j] == '1'){
					t[ii][j] = (t[ii][j] == '0') ? '1' : '0';
					if (ii == i) m++;
				}
			}
			sort(t.begin(), t.end());
			bool flag = false;
			for (int j = 0; j < n; j++) if (s[j] != t[j]) flag = true;
			if (!flag && (ans == -1 || ans > m)) ans = m;
			for (int ii = 0; ii < n; ii++) t[ii] = tt[ii];
		}
		if (ans == -1) cout << "NOT POSSIBLE\n"; else cout << ans << "\n";
	}

	return 0;
	
}