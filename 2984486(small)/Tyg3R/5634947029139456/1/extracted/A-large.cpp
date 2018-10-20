#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

string in[200];
string out[200];

bool flip[50];

int main ()
{
  DRI(T);
  FOR(t,0,T) {
  	DRII(N,L);
	  FOR(i,0,N) cin >> in[i];
		FOR(i,0,N) cin >> out[i];
		sort(out,out+N);
		int best = L+1;
		FOR(i,0,N) {
			int flips = 0;
			MM(flip,false);
			FOR(j,0,L) if(in[0][j] != out[i][j]) {flip[j] = true; flips++;}
			//cout << "xx" << flips << endl;
			vector<string> v;
			vector<string> v2;
			v.clear();
			v2.clear();
			FOR(n,0,N) if(n != i) v2.PB(out[n]);
			FOR(n,1,N) {
				string s = in[n];
				FOR(b,0,L) {
					if(flip[b]) {
						if(in[n][b] == '0') s[b] = '1';
						else s[b] = '0';
					}
				}
				v.PB(s);
				//cout << " " << s << endl;
			}
			sort(v.begin(),v.end());
			bool ok = true;
			FOR(n,0,N-1) {
				if(v[n] != v2[n]) ok = false;
			}
			if(ok) best = min(best,flips);
		}
		if(best == L+1) printf("Case #%d: NOT POSSIBLE\n", t+1);
		else printf("Case #%d: %d\n", t+1, best);

  }
  return 0;
}








