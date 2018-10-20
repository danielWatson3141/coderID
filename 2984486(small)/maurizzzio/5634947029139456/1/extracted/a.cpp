#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

int solve(vector<string> &a, vector<string> &b) {
	F(i, n) if (a[i] != b[i]) return false;
	return true;
}

int main() {
	int cas;
	int req;
	cin >> cas;
	F(cc, cas) {
		cin >> n >> req;
		vector<string> input(n);
		vector<string> output(n);

		F(i, n) cin >> input[i];
		F(i, n) cin >> output[i];

		sort(ALL(output));
		// F(z, n) printf("%s ", output[z].c_str()); NL;
				
		int mn = INF;
		F(i, n) {
			// try with output[i]
			F(j, n) {
				int changes = 0;
				vector<int> sol(req, 0);
				// vector<string> incp = input;
				F(k, req) {
					if (output[i][k] != input[j][k]) sol[k] = 1, changes += 1;
				}
				
				F(k, req) {
					if (sol[k])
						F(z, n) {
							if (input[z][k] == '0') input[z][k] = '1';
							else input[z][k] = '0';
						}
				}

				sort(ALL(input));
				// puts("start");
				// F(z, n) printf("%s ", output[z].c_str()); NL;
				// F(z, n) printf("%s ", input[z].c_str()); NL;

				if (solve(output, input)) mn = min(mn, changes);

				F(k, req) {
					if (sol[k])
						F(z, n) {
							if (input[z][k] == '0') input[z][k] = '1';
							else input[z][k] = '0';
						}
				}
			}
		}

		printf("Case #%d: ", cc + 1);
		if (mn == INF) puts("NOT POSSIBLE");
		else printf("%d\n", mn);
	}
	return 0;
}