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

int n, a[1111], f[1111];
pair<double, int> q[1111];
string ans[1111];

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int t = 0;
/*		for (int i = 0; i < n; i++) f[i] = 0;
		for (int i = 0; i < n; i++) if (!f[i]) {
			t++;
			f[i] = 1;
			int x = a[i];
			while (x != i) {
				f[x] = 1;
				x = a[x];
			}
		}*/
		for (int i = 0; i < n; i++) t += abs(i - a[i]);
		if (t > 327000) ans[tt] = "GOOD"; else ans[tt] = "BAD";
		q[tt] = mp(t, tt);
	}
	sort(q, q + T);
//	for (int i = 0; i < T; i++) cout << q[i].F << endl;
//	for (int i = 0; i < o; i++) ans[q[i].S] = "GOOD";
//	for (int i = o; i < T; i++) ans[q[i].S] = "BAD";
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": " << ans[i] << endl;
	}

	return 0;
}