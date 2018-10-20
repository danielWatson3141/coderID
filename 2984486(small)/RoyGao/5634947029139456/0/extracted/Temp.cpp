#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int n, l;
int ans;

string ol[100];
string tmp[100];
string tar[100];
int num[100];
bool found;

void check(int st)
{
	for (int i = 0; i < n; ++i) tmp[i] = ol[i];
	sort(tmp, tmp + n);
	for (int i = 0; i < n; ++i)
		if (tmp[i] != tar[i]) return;
	ans = min(ans, st);
}

void dfs(int k, int st)
{
	if (k >= l) {
		check(st);
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += ol[i][k] - '0';
	if (cnt == num[k])
		dfs(k + 1, st);
	if (cnt == n - num[k]) {
		for (int i = 0; i < n; ++i) {
			if (ol[i][k] == '0') ol[i][k] = '1';
			else ol[i][k] = '0';
		}
		dfs(k + 1, st + 1);
		for (int i = 0; i < n; ++i) {
			if (ol[i][k] == '0') ol[i][k] = '1';
			else ol[i][k] = '0';
		}
	}
}

int main()
{
	ifstream fin("A-small-attempt3.in");
	ofstream fout("A-small-attempt3.out");
	//freopen("", "w", stdout);
	int T, cas = 0;
	fin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		fin >> n >> l;
		memset(num, 0, sizeof num);
		for (int i = 0; i < n; ++i)
			fin >> ol[i];
		for (int i = 0; i < n; ++i) {
			fin >> tar[i];
			for (int j = 0; j < l; ++j)
				num[j] += tar[i][j] - '0';
		}
		sort(tar, tar + n);
		ans = 1000;
		check(0);
		fout << "Case #" << cas << ": ";
		if (ans == 0) fout << ans << endl;
		else {
			dfs(0, 0);
			if (ans <= l) fout << ans << endl;
			else fout << "NOT POSSIBLE" << endl;
		}
	}
	return 0;
}