#include <iostream>
#include <vector>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::set;
using std::string;

const int maxn = 150;

int n, l;
long long outlet[maxn];
long long device[maxn];
static_assert(sizeof(long long)>=8, "long long too short.");

long long read() {
  string s;
  cin >> s;
  long long res = 0;
  for(size_t i=0, slen=s.size();i<slen;i++)
    res = (res << 1) + (s[i] - '0');
  return res;
}

const int impossible = maxn + 1;

int ones(long long x) {
  int res = 0;
  for(;x;x>>=1)
    res += x % 2;
  return res;
}

int solve() {
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
      if(device[i] == device[j])
	return impossible;
  vector<set<long long> > edges(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      edges[i].insert(device[j] ^ outlet[i]);
  /*
  for(int i=0;i<n;i++) {
    std::cerr << i << ':';
    for(auto x : edges[i])
      std::cerr << ' ' << x;
    std::cerr << '\n';
  }
  */
  int best = impossible;
  for(auto edge : edges[0]) {
    const int cur = ones(edge);
    //std::cerr << edge << " (" << cur << ")\n";
    if(cur >= best) continue;
    bool good = true;
    for(int i=0;i<n;i++)
      good = good && edges[i].count(edge);
    if(good)
      best = cur;
  }
  return best;
}

int main() {
  int T;
  cin >> T;
  for(int tcase=1;tcase<=T;tcase++) {
    cin >> n >> l;
    for(int i=0;i<n;i++)
      outlet[i] = read();
    for(int i=0;i<n;i++)
      device[i] = read();
    const int sol = solve();
    cout << "Case #" << tcase << ": ";
    if(sol == impossible)
      cout << "NOT POSSIBLE\n";
    else
      cout << sol << '\n';
  }
}
