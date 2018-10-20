#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	freopen("A-large.in", "r", stdin);
	freopen("large.txt", "w", stdout);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, L;
		cin >> N >> L;
		vector<string> src, des;
		int ans = -1;
		for (int i = 0; i < N; ++i) {
			string str;
			cin >> str;
			src.push_back(str);
		}
		for (int i = 0; i < N; ++i) {
			string str;
			cin >> str;
			des.push_back(str);
		}
		sort(des.begin(), des.end());
		for (int i = 0; i < N; ++i) {
			vector<string> temp;
			
			for (int j = 0; j < i; ++j) {
				string str = src[j];
				for (int l = 0; l < L; ++l) {
					if (src[i][l] != des[0][l]) {
						str[l] = (str[l]=='1')?'0':'1';
					}
				}
				temp.push_back(str);
			}
			for (int j = i+1; j < N; ++j) {
				string str = src[j];
				for (int l = 0; l < L; ++l) {
					if (src[i][l] != des[0][l]) {
						str[l] = (str[l]=='1')?'0':'1';
					}
				}
				temp.push_back(str);
			}
			int op = 0;
			for (int l = 0; l < L; ++l) {
					if (src[i][l] != des[0][l]) op++;
			}
			
			if (ans >= 0 && op >= ans) continue;
			
			sort(temp.begin(), temp.end());
			
			bool ok = true;
			for (int i = 1; i < N && ok; ++i) {
				if (des[i] != temp[i-1]) ok = false;
			}
			if (ok) {
				if (ans == -1 || ans > op) ans = op;
			} 
		}
		cout << "Case #" << t << ": ";
		if (ans == -1) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}
}
