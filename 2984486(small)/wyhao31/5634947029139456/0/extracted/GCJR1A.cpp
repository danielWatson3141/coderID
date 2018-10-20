#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

ifstream in("A-small-attempt0.in.txt");
ofstream out("A-small.out");
//#define in cin
//#define out cout

typedef long long ll;

string flow[155];
ll f[155][155];
string device[155];

int main()
{
	int T, N, L;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> N >> L;
		for (int i = 0; i < N; i++) in >> flow[i];
		for (int i = 0; i < N; i++) in >> device[i];
		int res = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ll t = 0;
				for (int k = 0; k < L; k++) {
					if (flow[i][k] != device[j][k])
						t = t | (1<<(L-k-1));
				}
				f[i][j] = t;
			}
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << f[i][j] << " ";
			}
			cout << endl;
		}
		*/
		for (int i = 0; i < N; i++) {
			int j, k;
			for (j = 1; j < N; j++) {
				for (k = 0; k < N; k++) {
					if (f[0][i] == f[j][k]) {
						break;
					}
				}
				if (k == N) break;
			}
			if (j == N) {
				if (!flag) {
					flag = true;
					int t = 0;
					for (k = 0; k < L; k++) {
						if (f[0][i] & (1<<k)) t++;
					}
					res = t;
				} else {
					int t = 0;
					for (k = 0; k < L; k++) {
						if (f[0][i] & (1<<k)) t++;
					}
					if (t < res) res = t;					
				}
			}
		}
		if (flag) out << "Case #" << cnt << ": " << res << endl;
		else out << "Case #" << cnt << ": " << "NOT POSSIBLE" << endl;
	}
	return 0;
}