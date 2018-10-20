#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef short int sint;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define All(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));

const int N = 200;
const int L = 50;
string prad[N];
string lapki[N];
ll pp[N], qq[N];
bool maska[N];
int n, l;

ll trans(const string& x) {
	ll res = 0;
	REP(i, l) {
		res *= 2L;
		res += (x[i] - '0');
	}
	return res;
}

void solve() {
	cin >> n >> l;
	REP(i, n) {
			cin >> prad[i];
		pp[i] = trans(prad[i]);
	}
	REP(i, n) {
		cin >> lapki[i];
		qq[i] = trans(lapki[i]);
	}
	int res = N + 1;
	REP(wyb, n) {
		// wyb lapki[wyb]
		REP(j, n) {
			// pasuje do prad[j]
			ll mask = qq[wyb] ^ pp[j];
			vector<ll> lki, pki;
			REP(i, n) {
				lki.push_back(qq[i] ^ mask);
				pki.push_back(pp[i]);
			}
			sort(All(lki));
			sort(All(pki));
			bool ok = true;
			REP(i, n) {
				if (lki[i] != pki[i]) { ok = false; break;}
			}
			if (ok) {
				int s = 0;
				while (mask) {
					s += (mask&1);
					mask >>=1;
				}
				res = min(res, s);
			}
		}
	}
	if (res == N + 1) {
		cout << "NOT POSSIBLE";
	} else {
		cout << res;
	}
	cout << endl;
}

int main() {
	wez(t);
	REP(i, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}