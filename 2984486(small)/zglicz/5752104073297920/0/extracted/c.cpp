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
#define ALL(c) c.begin(),c.end()
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

const int T = 121;
const int N = 1000;
pii tab[T];
int perm[T][N];
bool res[T];

int main() {
	wez(t);
	REP(i, t) {
		wez(x)
		REP(j, x) {
			cin >> perm[i][j];
		}
		int sum = 0;
		REP(j, x) if (perm[i][j] == j-1) ++sum;
		tab[i] = mp(sum, i);
	}
	sort(tab, tab + t);
	REP(i, t / 2) {
		res[tab[i].ND] = true;
	}
	REP(i, t) {
		printf("Case #%d: %s\n", i+1, res[i] ? "GOOD" : "BAD");
	}
}