#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;

const int INF = 1000000000;

int N;
Mi net;
Mi dp_sum, dp_fun;

int sum(int n, int p) {
  int& res = dp_sum[n][p];
  if (res != -1) return res;
  res = 1;
  for (int i = 0; i < int(net[n].size()); ++i) {
    int m = net[n][i];
    if (m == p) continue;
    res += sum(m, n);
  }
  return res;
}

int fun(int n, int p) {
  int& res = dp_fun[n][p];
  if (res != -1) return res;
  int s = 0;
  Vi v;
  for (int i = 0; i < int(net[n].size()); ++i) {
    int m = net[n][i];
    if (m == p) continue;
    int ts = sum(m, n);
    int tf = fun(m, n);
    s += ts;
    v.push_back(tf - ts);
  }
  res = s;
  if (int(v.size()) >= 2) {
    sort(v.begin(), v.end());
    res = min(res, v[0] + v[1] + s);
  }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cin >> N;
    net = Mi(N);
    for (int i = 0; i < N - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      net[x].push_back(y);
      net[y].push_back(x);
    }
    
    dp_sum = Mi(N, Vi(N + 1, -1));
    dp_fun = Mi(N, Vi(N + 1, -1));
    
    int res = INF;
    for (int i = 0; i < N; ++i)
      res = min(res, fun(i, N));
    
    cout << "Case #" << cas << ": " << res << endl;
  }
}
