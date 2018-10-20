#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int n, l;
long long a[333], b[333], c[333];
string s;

long long f(string s) {
	long long r = 0;
	for (int i = 0; i < s.size(); i++) r = r * 2 + s[i] - '0';
	return r;
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> s;
			a[i] = f(s);
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			b[i] = f(s);
		}
		sort(b, b + n);
		int ans = 1e9;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			long long o = a[i] ^ b[j];
			int t = 0;
			for (int k = 0; k < l; k++) if (o & pw(k)) t++;
			for (int k = 0; k < n; k++) c[k] = a[k] ^ o;
			sort(c, c + n);
			int bad = 0;
			for (int k = 0; k < n; k++) if (b[k] != c[k]) bad = 1;
			if (!bad) ans = min(ans, t);
		}
		cout << "Case #" << tt << ": ";
		if (ans == 1e9) puts("NOT POSSIBLE"); else
		cout << ans << endl;

	}
	return 0;
}