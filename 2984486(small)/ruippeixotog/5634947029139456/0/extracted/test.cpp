#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXN 10
#define MAXL 10
#define INF 1e8

using namespace std;

int n, l;

int devices[MAXN], flows[MAXN];

int readBin() {
  int b; cin >> b;
  int d = 0, mult = 1;
  while(b != 0) {
    d += b % 2 ? mult : 0;
    mult *= 2;
    b /= 10;
  }
  return d;
}

bool check(int mask) {
  int fs[MAXN];
  for(int i = 0; i < n; i++) {
    fs[i] = flows[i] ^ mask;
  }
  sort(fs, fs + n);

  return memcmp(devices, fs, n * sizeof(int)) == 0;
}

int dfs(int k, int mask, int flips) {
  if(k == l) {
    return check(mask) ? flips : INF;
  }

  return min(
    dfs(k + 1, mask, flips),
    dfs(k + 1, mask | (1 << k), flips + 1));
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n >> l;

    for(int i = 0; i < n; i++)
      flows[i] = readBin();

    for(int i = 0; i < n; i++)
      devices[i] = readBin();

    sort(devices, devices + n);
    int res = dfs(0, 0, 0);

    cout << "Case #" << tc << ": ";
    if(res == INF)  cout << "NOT POSSIBLE" << endl;
    else cout << res << endl;
  }
  return 0;
}
