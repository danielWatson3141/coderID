#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int imx = 1000 * 1000 * 1000;

void change_bit(int bit, vector <string> &v) {
	for(int i = 0; i < v.size(); ++i) {
		v[i][bit] = (v[i][bit] - '0' + 1) % 2 + '0';
	}
}

int solve(int n, int l, vector <string> &given, vector <string> &needed) {
	int ans = imx;
	sort(needed.begin(), needed.end());
	for(int i = 0; i < n; ++i) {
		vector<string> v = given;
		int sw = 0;
		for(int j = 0; j < l; ++j) {
			if(v[i][j] != needed[0][j]) {
				change_bit(j, v);
				++sw;
			}
		}
		sort(v.begin(), v.end());
		for(int j = 0; j < n; ++j) {
			if(v[j] != needed[j]) {
				sw = imx;
				break;
			}
		}
		if(sw < ans) {
			ans = sw;
		}
	}
	if(ans == imx) return -1; else return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int n, l;
		cin >> n >> l;
		vector <string> given, needed;
		string s;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			given.push_back(s);
		}
		for(int i = 0; i < n; ++i) {
			cin >> s;
			needed.push_back(s);
		}
		int ans = solve(n, l, given, needed);
		cout << "Case #" << t + 1 << ": ";
		if(ans == -1) {
			cout << "NOT POSSIBLE";
		} else {
			cout << ans;
		}
		cout << endl;
	}
}