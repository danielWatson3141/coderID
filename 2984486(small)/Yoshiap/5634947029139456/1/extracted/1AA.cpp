#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1AA.out");
ifstream fin ("1AA.in");

int N,L;


int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		vector<string> a;
		vector<string> b;
		fin >> N >> L;
		for (int i = 0; i < N; i++) {
			string input;
			fin >> input;
			a.push_back(input);
		}
		for (int i = 0; i < N; i++) {
			string input;
			fin >> input;
			b.push_back(input);
		}
		int ans = 1000;
		for (int i = 0; i < N; i++) {
			vector<string> atemp;
			vector<string> btemp;
			for (int j = 0; j < N; j++) {
				atemp.push_back(a[j]);
				btemp.push_back(b[j]);
			}
			int cnt = 0;
			for (int j = 0; j < L; j++) {
				if (a[0][j] != b[i][j]) {
					cnt++;
					for (int k = 0; k < N; k++) {
						if (btemp[k][j] == '0') btemp[k][j] = '1';
						else btemp[k][j] = '0';
					}
				}
			}
			sort(atemp.begin(),atemp.end());
			sort(btemp.begin(),btemp.end());
			bool flag = true;
			for (int j = 0; j < N; j++) {
				if (atemp[j] != btemp[j]) {
					flag = false;
					break;
				}
			}
			if (flag) ans = min(ans,cnt);
		}
		fout << "Case #" << t << ": ";
		if (ans == 1000) fout << "NOT POSSIBLE\n";
		else fout << ans << "\n";
	}
    return 0;
}