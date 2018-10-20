//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 256;
int N, L;

int TestNum;
i64 getI64(){
  string s; cin >> s;
  i64 i = 0;
  for (auto ch: s) i = i * 2 + ch - '0';
  return i;
}

bool trySolve(vector<i64> src, vector<i64> dst, i64 mask){
  for (auto &it: dst) it ^= mask;
  sort(src.begin(), src.end());
  sort(dst.begin(), dst.end());
  return src == dst;
}
int solve(vector<i64> src, vector<i64> dst){
  int best = 64;
  for (auto it: dst) {
    i64 mask = src[0] ^ it;
    if (trySolve(src, dst, mask)){
      best = min(best, __builtin_popcount(mask));
    }
  }
  if (best == 64) return -1;
  return best;
}

int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    cin >> N >> L;
    vector<i64> src(N);
    vector<i64> dst(N);
    for (auto &it: src) it = getI64(); 
    for (auto &it: dst) it = getI64(); 
    cout << "Case #" << ++TestNum << ": ";
    int ans = solve(src, dst);
    if (ans == -1) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
  }
}

