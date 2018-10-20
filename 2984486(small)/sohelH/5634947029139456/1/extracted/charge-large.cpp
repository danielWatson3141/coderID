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
int N, L;
vector<string> v1, v2;
int res;

string findXor(string s1, string s2) {
	string res = "";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) res += "0";
		else res += "1";
	}
	return res;
}
int vis[200];

int countOne(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) if (s[i] == '1') cnt++;
	return cnt;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		cin >> N >> L;
		v1.clear(); v2.clear();
		for (int i = 0; i < N; i++) {
			string a; cin >> a; v1.push_back(a);
		}

		for (int i = 0; i < N; i++) {
			string a; cin >> a; v2.push_back(a);
		}

		res = 1000000000;
		for (int j = 0; j < N; j++) {
			string Xor = findXor(v1[0], v2[j]);
			memset(vis, 0, sizeof(vis));
			vis[j] = 1;
			int i;
			for (i = 1; i < N; i++) {
				string can = findXor(v1[i], Xor);
				int k;
				for (k = 0; k < N; k++) {
					if (vis[k] == 0 && v2[k] == can) {
						vis[k] = 1;
						break;
					}
				}
				if (k == N) break;
			}
			if (i == N) {
				res = min(res, countOne(Xor));
			}
		}

		printf("Case #%d: ", cases);
		if (res == 1000000000) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << res << endl;
		}



	}
	return 0;
}
