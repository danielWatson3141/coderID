#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 150+5;
string s1[MAXn], s2[MAXn];
const int INF = 1e9;
string tmp[MAXn];

char rev(char c) { return (c=='1')?'0':'1'; }

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int n, l;
		cin >> n >> l;
		for(int i = 0; i < n; i++)
			cin >> s1[i];
		for(int i = 0; i < n; i++)
			cin >> s2[i];
		sort(s2, s2 + n);
		int best = INF;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				int dist = 0;
				for(int k = 0; k < l; k++)
					dist += (s1[i][k] != s2[j][k]);
				for(int k = 0; k < n; k++) {
					tmp[k] = s1[k];
					for(int h = 0; h < l; h++) {
						if(s1[i][h] != s2[j][h])
							tmp[k][h] = rev(tmp[k][h]);
					}
				}
				sort(tmp, tmp + n);
				bool f = true;
				for(int k = 0; k < n; k++)
					if(tmp[k] != s2[k]) {
						f = false;
						break;
					}
				if(f)
					best = min(best, dist);
			}
		cout << "Case #" << t << ": ";
		if(best == INF)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << best << endl;
	}
	return 0;
}
