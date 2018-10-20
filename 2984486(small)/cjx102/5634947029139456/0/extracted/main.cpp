#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int n,l,ans,i,j,k,c[100];
string a[100],tmp[100],b[100];
bool found;

void check(int st)
{
	for (int i = 0; i < n; ++i) tmp[i] = a[i];
	sort(tmp, tmp + n);
	for (int i = 0; i < n; ++i)
		if (tmp[i] != b[i]) return;
	ans = min(ans, st);
}

void swp(int k)
{
    for (int i = 0; i < n; ++i) {
			if (a[i][k] == '0') a[i][k] = '1';
			else a[i][k] = '0';
    }
}

void dfs(int k, int st)
{
	if (k >= l) {
		check(st);
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt +=a[i][k] - '0';
	if (cnt == c[k])
		dfs(k + 1, st);
	if (cnt == n - c[k]) swp(k);

		dfs(k + 1, st + 1);
		swp(k);
	}


int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	//freopen("", "w", stdout);
	int T, cas = 0;
	fin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		fin >> n >> l;
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; ++i)
			fin >> a[i];
		for (int i = 0; i < n; ++i) {
			fin >> b[i];
			for (int j = 0; j < l; ++j)
				c[j] += b[i][j] - '0';
		}
		sort(b, b + n);
		ans = 0x3f3f3f;
		fout << "Case #" << cas << ": ";
		check(0);
		if (ans == 0) fout << ans << endl;
		else {
			dfs(0, 0);
			if (ans <= l) fout << ans << endl;
			else fout << "NOT POSSIBLE" << endl;
		}
	}
	return 0;
}
