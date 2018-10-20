#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <sys/time.h>
#include <vector>
using namespace std;
#define i64         int64_t
#define rep(i, n)   for(i64 i = 0; i < ((i64)(n)); ++i)
#define sz(v)       ((i64)((v).size()))
#define bit(n)      (((i64)1)<<((i64)(n)))
#define all(v)      (v).begin(), (v).end()

template <int POS, class TUPLE> void deploy(std::ostream &os, const TUPLE &tuple){}
template <int POS, class TUPLE, class H, class ...Ts> void deploy(std::ostream &os, const TUPLE &t){ os << (POS == 0 ? "" : ", ") << get<POS>(t); deploy<POS + 1, TUPLE, Ts...>(os, t); }
template <class ...Ts> std::ostream& operator<<(std::ostream &os, const std::tuple<Ts...> &t){ os << "("; deploy<0, std::tuple<Ts...>, Ts...>(os, t); os << ")"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "" : ", "); os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "" : ", "); os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> &q){ auto qq = q; os << "{"; for(; !qq.empty(); qq.pop()){ os << qq.front() << (qq.size() != 1 ? ", " : ""); } os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> &q){ auto qq = q; os << "{"; for(; !qq.empty(); qq.pop()){ os << qq.top() << (qq.size() != 1 ? ", " : ""); } os << "}"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> &p){ os << "(" << p.first << ", " << p.second << ")"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> &mp){ int remain = mp.size(); os << "{"; for(auto e: mp) os << "(" << e.first << " -> " << e.second << ")" << (--remain == 0 ? "" : ", "); os << "}"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> &mp){ int remain = mp.size(); os << "{"; for(auto e: mp) os << "(" << e.first << " -> " << e.second << ")" << (--remain == 0 ? "" : ", "); os << "}"; return os; }
#define DEBUG0() { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << std::endl; }
#define DEBUG1(var0) { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << (#var0) << "=" << (var0) << std::endl; }
#define DEBUG2(var0, var1) { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << std::endl; }
#define DEBUG3(var0, var1, var2) { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << std::endl; }
#define DEBUG4(var0, var1, var2, var3) { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << ", " << (#var3) << "=" << (var3) << std::endl; }
#define DEBUG5(var0, var1, var2, var3, var4) { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << ", " << (#var3) << "=" << (var3) << ", " << (#var4) << "=" << (var4) << std::endl; }
#define DEBUG6(var0, var1, var2, var3, var4, var5) { char buf[100]; sprintf(buf, "line:%3d | ", __LINE__); std::cout << buf << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << ", " << (#var3) << "=" << (var3) << ", " << (#var4) << "=" << (var4) << ", " << (#var5) << "=" << (var5) << std::endl; }
#define ASSERT(f) { if(!(f)){ DEBUG0(); while(true); }}




vector<vector<i64>> edges;


i64 recur(i64 pos, i64 parent)
{
  vector<i64> v;
  for(auto next: edges[pos])if(next != parent) v.push_back(recur(next, pos));
  if(sz(v) < 2) return 1;
  sort(all(v));
  reverse(all(v));
  return 1 + v[0] + v[1];
}

int main()
{
  i64 T;
  cin >> T;
  rep(test_case, T){
    i64 n;
    cin >> n;
    edges = vector<vector<i64>>(n);
    rep(i, n - 1){
      i64 a, b;
      cin >> a >> b;
      edges[a - 1].push_back(b - 1);
      edges[b - 1].push_back(a - 1);
    }
    i64 ans = 0;
    rep(i, n) ans = max(ans, recur(i, -1));
    cout << "Case #" << test_case + 1 << ": " << n - ans << endl;
  }
}




















