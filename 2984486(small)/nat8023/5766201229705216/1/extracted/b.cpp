#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
//#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pint;
typedef pair<LL,LL> pll;
#define fi first
#define se second
typedef map<int,int> mapint;
typedef vector<int> vint;
typedef vector<vint> vintp;
#define rep(i,j,k) for (int i = (j);i <= (k);i ++)
#define repd(i,j,k) for (int i = (j);i >= (k);i --)
#define ran2 (rand() % 32000 * 32000 + rand() % 32000)
#define pb push_back
#define mp make_pair
#define SIZE(i) ((int)(i.size()))
int m,n,j,k,l,i,o,p,__t;
char ch;
void read(int &a) {
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}

#define mx 101010

struct  Graph {
	int Be[mx], E[mx], N[mx], T, size[mx];
	int dp[2000], temp[2][3];
	void clear() {
		T = 0;
		memset(Be, 0, sizeof Be);
		memset(E, 0, sizeof E);
	}
	void make(int i, int j, int k) {
		N[++ T] = Be[i], Be[i] = T, E[T] = j;
		if (k) make(j, i, 0);
	}

	/*void DFS(int P, int father) {
		int leave = 1;
		for (int i = Be[P]; i ; i = N[i]) if (E[i] != father) {
			DFS(E[i], P);
			leave = 0;
		}
		if (leave) {
			dp[P][0] = 1;
			dp[P][1] = 0;
			return;
		}

		int price = 1;
		for (int i = Be[P]; i; i = N[i]) if (E[i] != father) {
			int k = 200000;
			if (dp[E[i]][0] != -1) k = min(k, dp[E[i]][0]);
			if (dp[E[i]][1] != -1) k = min(k, dp[E[i]][1]);
			price += k;
		}
		if (price <= m)
			dp[P][0] = price;

		memset(temp, 61, sizeof temp);
		int suf = 0, pre = 1;
		temp[suf][0] = 0;
		for (int i = Be[P]; i; i = N[i]) if (E[i] != father) {
			int def = E[i];
			swap(suf, pre);
			memset(temp[suf], 61, sizeof temp[suf]);

			for (int son = 0; son <= 2; son ++) {
				if (dp[def][0] != -1)
					temp[suf][son] = min(temp[suf][son], temp[pre][son] + dp[def][0]);
				if (son < 2 && dp[def][1] != -1)
					temp[suf][son + 1] = min(temp[suf][son + 1], temp[pre][son] + dp[def][1]);
			}
		}
		if (min(temp[suf][2], temp[suf][0]) <= m)
			dp[P][1] = min(temp[suf][2], temp[suf][0]);
	}*/
	void DFS(int P, int father) {
		int leave = 1;
		size[P] = 1;
		for (int i = Be[P]; i ; i = N[i]) if (E[i] != father) {
			DFS(E[i], P);
			size[P] += size[E[i]];
			leave = 0;
		}
		if (leave == 1) {
			dp[P] = 0;
			return;
		}
		memset(temp, 61, sizeof temp);
		int suf = 0, pre = 1;
		temp[suf][0] = 0;

		for (int i = Be[P]; i; i = N[i]) if (E[i] != father) {
			int def = E[i];
			swap(suf, pre);
			memset(temp[suf], 61, sizeof temp[suf]);

			for (int son = 0; son <= 2; son ++) {
				temp[suf][son] = min(temp[suf][son], temp[pre][son] + size[def]);
				if (son < 2)
					temp[suf][son + 1] = min(temp[suf][son + 1], temp[pre][son] + dp[def]);
			}
		}
		if (min(temp[suf][2], temp[suf][0]) <= m)
			dp[P] = min(temp[suf][2], temp[suf][0]);

	}
	void solve() {
		int ret = 1000000000;
		for (int i = 1; i <= m; i ++) {
			memset(dp, 55, sizeof dp);
			DFS(i, 0);
			if (dp[i] < ret) ret = dp[i];
		}
		cout << ret << endl;
	}
} pic;

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int cas = 1, id;
	for (cin >> id; id --; cas ++) {
		cout << "Case #" << cas << ": ";
		
		cin >> m;
		pic.clear();
		rep(i, 1, m - 1) {
			cin >> j >> k;
			pic.make(j, k, 1);
		}
		pic.solve();
	}

	//fclose(stdin); fclose(stdout);
}
