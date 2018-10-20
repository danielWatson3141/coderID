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
vector<int> itokens(string s, string sep);
vector<string> stokens(string s, string sep);

bool isBinaryTree(vector<vector<int> > &G, int b) {
  int N = G.size();
  for (int i = 0; i < N; i++) if (!((b>>i)&1)) {
    queue<int> q;
    int vis = b;
    vis |= 1<<i;
    q.push(i);
    bool ok = true;
    while (ok && !q.empty()) {
      int p = q.front(); q.pop();
      int ct = 0;
      for (int j = 0; j < N; j++) if (!((vis>>j)&1) && G[p][j]) {
        q.push(j);
        vis |= 1<<j;
        ct++;
      }
      if (ct && ct != 2) ok = false;
    }
    if (vis != (1<<N)-1) ok = false;
    if (ok) return true;
  }
  return false;
}

int pruneN(vector<vector<int> > &G, int s) {
  int N = G.size();
  vector<int> c;
  for (int i = 0; i < N; i++) if (G[s][i]) {
    c.push_back(i);
    G[s][i] = G[i][s] = 0;
  }
  if (c.empty()) return 1;
  vector<int> kp(c.size());
  for (int i = 0; i < c.size(); i++) {
    kp[i] = pruneN(G, c[i]);
  }
  sort(kp.rbegin(), kp.rend());
  for (int i = 0; i < c.size(); i++) G[s][c[i]] = G[c[i]][s] = 1;
  if (kp.size() <= 1) return 1;
  return 1 + kp[0] + kp[1];
}

void doit(bool print = true) {
  int N = readIntLine();
  vector<vector<int> > G(N, vector<int>(N, 0));
  for (int i = 0; i < N-1; i++) {
    int a, b;
    scanf("%d %d ", &a, &b);
    G[a-1][b-1] = G[b-1][a-1] = 1;
  }

  int mn = 100;
  for (int i = 0; i < N; i++) {
    int ct = N - pruneN(G, i);
    if (ct < mn) mn = ct;
  }

  printf("%d\n", mn);
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
vector<string> stokens(string s, string sep = " \n\r\t") {
	vector<string> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}
vector<int> itokens(string s, string sep = " \n\r\t") {
	vector<int> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}

