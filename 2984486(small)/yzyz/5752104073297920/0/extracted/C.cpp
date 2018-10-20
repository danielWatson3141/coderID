#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

ofstream fout ("Csmall.out");
ifstream fin ("Csmall.in");

int T;
int n,a[1010];

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fin >> n;
		int ct = 0;
		for (int i = 0; i < n; i++) {
			fin >> a[i];
			for (int j = 0; j < i; j++)
				if (a[j] > a[i]) ct++;
		}
		fout << "Case #" << tc << ": ";
		fout << (abs(ct - n/2) < 2 ? "BAD\n" : "GOOD\n");
		cout << ct << endl;
	}
    return 0;
}