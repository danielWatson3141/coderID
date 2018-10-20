#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <utility>
#include <algorithm>
using namespace std;

#define clr(a, x)  memset(a, x, sizeof(a))
#define REP(i, n)  for(int i = 0; i < (n); i++)
#define DEBUG

typedef long long LL;

const int N = 150;
int T, n, l;
string s[N+5], t[N+5];
bool x[45];
vector <string> tmp;
	
void solve() {
	cin >> T;
	REP(Case, T) {
		cin >> n >> l;
		REP(i, n)  cin >> s[i];
		REP(i, n)  cin >> t[i];
		sort(t, t+n);
		int ans = 100;
		REP(i, n) REP(j, n) {
			clr(x, false);
			int cnt = 0;
			REP(k, l)  if(s[i][k] != t[j][k]) {
				x[k] = true; cnt++;
			}
			tmp.clear();
			REP(k, n) {
				string str = s[k];
				REP(p, l) {
					if(x[p])  str[p] = (str[p]-'0')^1 + '0';
				}
				tmp.push_back(str);
			}
			sort(tmp.begin(), tmp.end());
			REP(k, n)  if(tmp[k] != t[k]) {
				cnt = -1; break;
			}
			if(cnt != -1)  ans = min(cnt, ans);
		}
		printf("Case #%d: ", Case+1);
		if(ans == 100)  printf("NOT POSSIBLE\n");
		else  printf("%d\n", ans);
	}
}

int main() {
#ifdef DEBUG
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	solve();
#ifdef DEBUG
	fclose(stdin);
	fclose(stdout);
#endif
	return  0;
}













