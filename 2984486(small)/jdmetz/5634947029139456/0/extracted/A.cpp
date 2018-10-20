#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;
string readLine();
int readIntLine();
vector<int> readVI(int n);
vector<string> readVS(int n);
vector<int> itokens(string s, string sep = " \n\r\t");
vector<string> stokens(string s, string sep = " \n\r\t");

void doit(bool print = true) {
  int N, L;
  scanf("%d %d ", &N, &L);
  vector<long long> f(N), e(N);
  vector<string> flows = stokens(readLine());
  vector<string> needs = stokens(readLine());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < L; j++) if (flows[i][j] == '1') f[i] |= 1LL<<j;
    for (int j = 0; j < L; j++) if (needs[i][j] == '1') e[i] |= 1LL<<j;
  }

  sort(e.begin(), e.end());
  sort(f.begin(), f.end());
  int mn = 100;
  for (int i = 0; i < (1<<L); i++) {
    int b = 0;
    for (int j = 0; j < L; j++) b += (i>>j)&1;
    if (b > mn) continue;
    vector<long long> pf = f;
    for (int j = 0; j < N; j++) pf[j] ^= i;
    sort(pf.begin(), pf.end());
    if (pf == e) mn = b;
  }

  if (mn < 100) printf("%d\n", mn);
  else printf("NOT POSSIBLE\n");
}




/**
 * Library code
 */

int main(int argc, char **argv) {
  int wcase = 0;
  if (argc > 1) wcase = atoi(argv[1]);

	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
    bool print = !wcase || wcase == cn;
		if (print) printf("Case #%d: ", cn);
		doit(print);
	}
	return 0;
}

string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}
int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}
vector<int> readVI(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}
vector<string> readVS(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<string> v(n);
	for (int i = 0; i < n; i++) v[i] = readLine();
	return v;
}
vector<string> stokens(string s, string sep) {
	vector<string> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}
vector<int> itokens(string s, string sep) {
	vector<int> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}

