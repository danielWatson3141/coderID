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


const i64 MAX = 1000;
double probability[MAX][MAX];
double dat[MAX];
double good_probability;
void updateProbability()
{
  good_probability = log(1.0 / MAX) * MAX;
  rep(cur, MAX){
    rep(i, MAX) probability[cur][i] = 0.0;
    probability[cur][cur] = 1.0;
    rep(i, MAX){
      rep(j, MAX) dat[j] = probability[cur][j];
      rep(j, MAX) probability[cur][j] = (dat[i] + dat[j] * (MAX - 1.0)) / MAX;
      probability[cur][i] = 1.0 / MAX;
    }
  }
  //rep(i, MAX) cerr << probability[MAX - 1][i] << " "; cerr << endl;
}

void goodShuffle(vector<i64> &v)
{
  rep(i, sz(v)) swap(v[i], v[i + rand() % (sz(v) - i)]);
}

void badShuffle(vector<i64> &v)
{
  rep(i, sz(v)) swap(v[i], v[rand() % sz(v)]);
}

double calProbability(vector<i64> v)
{
  double total = 0.0;
  rep(i, sz(v)) total += log(probability[v[i]][i]);
  return total;
}

double getCriteria()
{
  i64 T = 2000;
  vector<double> scores[2];
  rep(i, 2){
    rep(loop, T){
      vector<i64> v;
      rep(j, MAX) v.push_back(j);
      if(i) badShuffle(v);
      else goodShuffle(v);
      scores[i].push_back(calProbability(v));
    }
  }
  sort(all(scores[0]));
  sort(all(scores[1]));
  /*
  DEBUG1(scores[0]);
  DEBUG1(scores[1]);
  printf("%0.20lf\n", scores[0][0]);
  printf("%0.20lf\n", scores[0].back());
  */
  return (scores[0][T / 2] + scores[1][T / 2]) * 0.5;
}

int main()
{
  updateProbability();
  double criteria = getCriteria();
  
  i64 T;
  cin >> T;
  rep(test_case, T){
    i64 n;
    cin >> n;
    vector<i64> v(n);
    rep(i, n) cin >> v[i];
    cout << "Case #" << test_case + 1 << ": " << (calProbability(v) < criteria ? "GOOD" : "BAD") << endl;
  }
}







