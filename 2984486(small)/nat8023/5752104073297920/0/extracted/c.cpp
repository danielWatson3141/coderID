#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
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
#define ran2 rand()
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
int K[10000];

int tree[10000];

void add(int P) {
	for (; P < 3000; P += (P & (-P)))
		tree[P] ++;
}

int get(int P) {
	int ret = 0;
	for (; P > 0; P -= (P & (-P)))
		ret += tree[P];
	return ret;
}

pint sos[10101];

int List[100001][1001];

int main() {
	freopen("c.in","r",stdin);
	freopen("d4.out","w",stdout);
	
	srand(time(NULL));
	
	
	
	int k[1010];
	LL total = 0;
	rep(t, 1, 100000) {
		for (int i = 0; i < 1000; i ++) k[i] = i;
		rep(i, 0, 999){
			//int z = ran2 % (999 - i + 1) + i;
			int z = ran2 % 1000;
			//166747328083
			//170632323348
			swap(k[z], k[i]);
		}
		rep(i, 0, 999)
			List[t][i] = k[i];
		//LL temp = 0;
		//rep(i, 0, 999)
		//	temp += k[i] * (i + 1) * (i + 1);
		//total += temp;
	}
	/*
	printf("%lld %.8lf\n", total, total / (1.0 * 1000000));
	*/
	
	const double g1 = 166747328083, g2 = 170632323348;
	
	/*cin >> id;
	for (int h = 1; h <= 120; h ++) {
		int total = 0;
		cin >> m;
		memset(tree, 0 , sizeof (tree));
		rep(i, 1, m) {
			cin >> K[i]; K[i] ++;
			total += get(K[i]);
			add(K[i]);
		}
		sos[h] = make_pair(total, h);
	}
	sort(sos + 1, sos + 1 + 120);
	bool flag[1230] = {0};
	rep(i, 1, 60)
		flag[sos[i].second] = 1;

	rep(i, 1, 120) {
		cout << "Case #" << i << ": ";
		if (flag[i]) cout << "GOOD" << endl;
		else 
			cout << "BAD" << endl;
	}*/
	
	int cas = 1, id;
	for (cin >> id; id --; cas ++) {
		//cout << "Case #" << cas << ": ";
		cin >> m;
		cerr << cas << endl;
		memset(tree, 0 ,sizeof tree);
		LL total = 0;
		rep(i, 0, m - 1) {
			cin >> K[i]; //K[i] ++;
			//total += i * K[i] * i;
			//total += get(K[i]);
			//add(K[i]);
		}
		rep(i, 1, 100000)
			rep(j, 0, 999)
				if (K[j] == List[i][j]) total ++;
		sos[cas] = make_pair((int)total, cas);
		continue;
		//if (fabs(fabs(total - g1) - fabs(total - g2)) < 3000) {
		//	int u = rand() % 2;
		//	if (u) cout << "GOOD" << endl; else cout << "BAD" << endl;
		//} else 
		if (fabs(total - g1) < fabs(total - g2))
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;
	}
	sort(sos + 1, sos + 1 + 120);
	bool flag[1230] = {0};
	rep(i, 1, 60)
		flag[sos[i].second] = 1;

	rep(i, 1, 120) {
		cout << "Case #" << i << ": ";
		if (flag[i]) cout << "GOOD" << endl;
		else 
			cout << "BAD" << endl;
	}
	//fclose(stdin); fclose(stdout);
}
