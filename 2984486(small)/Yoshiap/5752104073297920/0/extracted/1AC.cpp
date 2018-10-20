#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <ctime>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1AC.out");
ifstream fin ("1AC.in");
double chances[1000][1000];
int N;
int input[1000];

int main() {
	for (int i = 0; i < 1000; i++) {
		if (i == 999) {
			cout << "HI" << endl;
		}
		double c[1000][2];
		for (int j = 0; j < 1000; j++) {
			if (i == j) c[j][0] = 1;
			else c[j][0] = 0;
			c[j][1] = 0;
		}
		for (int j = 0; j < 1000; j++) {
			double val = c[j][j%2];
			c[j][j%2] = 0;
			for (int k = 0; k < 1000; k++) {
				c[k][(j+1)%2] = c[k][j%2]*999./1000.+val/1000.;
			}
			c[j][(j+1)%2] = 1./1000.;
		}
		for (int j = 0; j < 1000; j++) {
			chances[i][j] = c[j][1];
		}
	}
	
	int T;
	fin >> T;
	int anstot = 0;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fin >> N;
		for (int i = 0; i < N; i++) fin >> input[i];
		double sum = 0;
		for (int i = 0; i < N; i++) sum += chances[input[i]][i];
		fout << "Case #" << t << ": ";
		if (abs(sum-1) < .005) fout << "GOOD\n";
		else fout << "BAD\n";

		if (abs(sum-1) < .005) anstot++;
	}
	cout << anstot << "\n";
	system("pause");
}