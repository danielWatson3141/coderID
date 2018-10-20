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
string S[200][2];
LL rev[200][2];

void reve(int j, int p) {
	LL bit = 1;
	for (int i = S[j][p].length() - 1; i >= 0; i --, bit *= 2LL)
		rev[j][p] += bit * ((LL)(S[j][p][i] - '0'));
}
int calc(LL i) {
	int ret = 0;
	for (; i > 0; i -= (i & (-i)))
		ret ++;
	return ret;
}
int id, flag[1000];

map<LL, int> total, now;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int cas = 1, id;
	for (cin >> id; id --; cas ++) {
		cout << "Case #" << cas << ": ";
		cin >> m >> n;
		memset(rev, 0, sizeof rev);
		rep(i, 1, m) {
			cin >> S[i][0];
			reve(i, 0);
		}
		vint sorti;
		total.clear();
		rep(i, 1, m) {
			cin >> S[i][1];
			reve(i, 1);
			total[rev[i][1]] ++;
		}
		int price = 100000000;

		rep(i, 1, 1)
		rep(j, 1, m) {
			LL xorx = rev[i][0] ^ rev[j][1];
			int l = calc(xorx);
			if (l < price) {
				now.clear();
				bool flag = 1;
				rep(k, 1, m) {
					LL def = rev[k][0] ^ xorx;
					now[def] ++;
					if (now[def] > total[def]) {
						flag = 0;
						break;
					}
				}
				if (flag) price = l;
			}
		}

		if (price == 100000000) {
			cout << "NOT POSSIBLE" << endl;
		} else 
		cout << price << endl;

	}

	//fclose(stdin); fclose(stdout);
}
