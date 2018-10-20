#include <bits/stdc++.h>

using namespace std;

const int N = 150;

string a[N], b[N], c[N];
map<string, vector<int>> ma;
bool used[N];

void toggle(int pos, int n, vector<string> & d) {
  for (int i = 0; i < n; i++)
    d[i][pos] = (d[i][pos] == '0')? '1' : '0';
}

void print(vector<string> d) {
  cerr << "d => ";
  for (string x : d)
    cerr << x << ' ';
  cerr << '\n';
}

bool can(int n, int len, vector<string> d) {
  ma.clear();
  for (int i = 0; i < n; i++) {
    c[i] = d[i].substr(0, len);
    ma[a[i].substr(0, len)].push_back(i);
  }

  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++) {
    if (!ma.count(c[i]))
      return false;
    else {
      vector<int> v = ma[c[i]];
      bool ok = false;
      for (int x : v) {
        if (!used[x]) {
          used[x] = true;
          ok = true;
          break;
        }
      }

      if (!ok) return false;
    }
  }
  return true;
}

int solve(int pos, vector<string> d, int l, int n) {
  if (pos == l)
    return 0;

  // no toggle;
  int r = int(1e9);
  if (can(n, pos+1, d)) {
    r = solve(pos+1, d, l, n);
  }

  toggle(pos, n, d);
  if (can(n, pos+1, d)) {
    r = min(r, 1 + solve(pos+1, d, l, n));
  }

  return r;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    int n, l;
    cin >> n >> l;

    vector<string> d(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      d[i] = b[i];
    }

    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans = solve(0, d, l, n);

    cout << "Case #" << tc << ": ";
    if (ans >= int(1e9))
      cout << "NOT POSSIBLE\n";
    else
      cout <<  ans << '\n';
  }

  return 0;
}
