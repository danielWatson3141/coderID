#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int a[N], b[N], c[N];
map<int, int> ma;
bool used[N];

bool can(int n, int mask) {
  for (int i = 0; i < n; i++)
    c[i] = b[i] ^ mask;

  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++) {
    if (!ma.count(c[i]))
      return false;
    else {
      if (used[ma[c[i]]])
        return false;
      used[ma[c[i]]] = true;
    }
  }

  return true;
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

    ma.clear();
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      a[i] = strtol(s.c_str(), NULL, 2);
      ma[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      b[i] = strtol(s.c_str(), NULL, 2);
    }

    int ans = int(1e9);
    for (int mask = 0; mask < (1 << l); mask++) {
      if (can(n, mask))
        ans = min(ans, __builtin_popcount(mask));
    }

    cout << "Case #" << tc << ": ";
    if (ans == int(1e9))
      cout << "NOT POSSIBLE\n";
    else
      cout <<  ans << '\n';
  }

  return 0;
}
