#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int casenum,T;
int n, len, ans;
string start[160];
string tmp[160];
string end[160];
bool flip[50];

int main() {
	freopen("gcj14.in","r",stdin);
	freopen("gcj14.out","w",stdout);
	cin >> T;
	for (casenum = 1; casenum <= T; casenum++) {
		cout << "Case #" << casenum << ": ";
		cin >> n >> len;
		for (int i = 0; i < n; i++)
			cin >> start[i];
		for (int i = 0; i < n; i++)
			cin >> end[i];
		sort(end, end + n);
		ans = 1000;
		for (int i = 0; i < n; i++) {
			memset(flip, 0, sizeof(flip));
			int cnt = 0;
			for (int j = 0; j < len; j++)
				if (start[0][j] != end[i][j])
					{
						flip[j] = true;
						cnt ++;

					}
			if (cnt > ans) continue;
			for (int j = 0; j < n; j++) {
				tmp[j] = start[j];
				for (int k = 0; k < len; k++)
					if (flip[k])
						tmp[j][k] = (tmp[j][k]=='0')?'1':'0';
			}
			sort(tmp, tmp + n);
			bool flag = true;
			for (int j = 0; j < n; j++)
				if (tmp[j] != end[j]) {
					flag = false;
					break;
				}
			if (flag) ans = cnt;
		}
		if (ans == 1000) cout<<"NOT POSSIBLE";
		else cout << ans;
		cout << endl;
	}
	return 0;
}
