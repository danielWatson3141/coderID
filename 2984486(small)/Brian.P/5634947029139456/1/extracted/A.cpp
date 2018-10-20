#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <tuple>
using namespace std;

typedef long long int64;
//typedef __int128_t int128;
typedef vector<int> veci;
typedef vector<string> vecs;

#define VAR(a, b) __typeof(b) a=(b)
#define FOREACH(it, c) for (VAR(it, (c).begin()); it != (c).end(); ++it)
#define TRACE(x) cout << #x << endl
#define DEBUG(x) cout << #x " = " << (x) << endl
#define DEBUGA(a, n) VAR(__p, a); cout << #a " = {"; for (int __i = 0; __i < n; ++__i, ++__p) cout << (__i == 0 ? "" : ", ") << *(__p); cout << "}" << endl
#define CLR(a, val) memset(a, val, sizeof(a))

template<class T1, class T2> ostream& operator << (ostream &o, const pair<T1, T2> &p)
{
  return o << "(" << p.first << ", " << p.second << ")";
}

template<class T> ostream& operator << (ostream &o, const vector<T> &v)
{
  o << '{';
  FOREACH(it, v) o << (it == v.begin() ? "" : ", ") << *it;
  return o << '}';
}

int N, L, best;

bool isgood(const vector<veci> &flows, const vector<veci> &targets, int pos) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= pos; j++)
      if (flows[i][j] != targets[i][j])
        return false;
  return true;
}

void find(int pos, vector<veci> &flows, const vector<veci> &targets, int sofar) {
  if (best >= 0 && sofar >= best)
    return;
  if (pos >= L) {
    best = sofar;
    return;
  }
  sort(flows.begin(), flows.end());
  if (isgood(flows, targets, pos))
    find(pos + 1, flows, targets, sofar);

  for (int i = 0; i < N; i++)
    flows[i][pos] = 1 - flows[i][pos];
  sort(flows.begin(), flows.end());
  if (isgood(flows, targets, pos))
    find(pos + 1, flows, targets, sofar+1);

  for (int i = 0; i < N; i++)
    flows[i][pos] = 1 - flows[i][pos];
}

void run(int tc)
{
  cin >> N >> L;
  vector<veci> flows(N, veci(L)), targets(N, veci(L));
  for (int i = 0; i < N; i++) {
    string flow; cin >> flow;
    for (int j = 0; j < L; j++)
      flows[i][j] = flow[j] - '0';
  }
  for (int i = 0; i < N; i++) {
    string target; cin >> target;
    for (int j = 0; j < L; j++)
      targets[i][j] = target[j] - '0';
  }

  sort(targets.begin(), targets.end());
  sort(flows.begin(), flows.end());
  best = -1;
  find(0, flows, targets, 0);

  cout << "Case #" << (tc + 1) << ": ";
  if (best < 0) cout << "NOT POSSIBLE" << endl;
  else cout << best << endl;
}

int main()
{
  int T = 0, tc = 0;
  for (cin >> T; tc < T; tc++) run(tc);
  return 0;
}
