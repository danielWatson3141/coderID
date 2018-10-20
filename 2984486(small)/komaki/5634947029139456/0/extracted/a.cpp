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






int main()
{
  i64 T;
  cin >> T;
  rep(test_case, T){
    i64 n, l;
    cin >> n >> l;
    vector<string> v0(n);
    vector<string> v1(n);
    rep(i, n) cin >> v0[i];
    rep(i, n) cin >> v1[i];
    sort(all(v0));
    sort(all(v1));
    
    i64 best = bit(50);
    rep(target0, n){
      i64 cnt = 0;
      bool ok = true;
      vector<string> cur = v0;
      rep(i, l)if(v0[0][i] != v1[target0][i]){
        ++cnt;
        rep(j, n) cur[j][i] = cur[j][i] == '0' ? '1' : '0';
      }
      sort(all(cur));
      if(cur == v1) best = min(best, cnt);
    }
    stringstream ans;
    if(best == bit(50)) ans << "NOT POSSIBLE";
    else ans << best;
    cout << "Case #" << test_case + 1 << ": " << ans.str() << endl;
  }
}

















