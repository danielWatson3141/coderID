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
const int MAXN = 1024;
int N;
int a[MAXN];
double weight1(){
  double tot = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      tot += abs(i - j) * i;
    }
  }
  return tot / N;
}
double weight2(){
  double tot = 0;
  for (int i = 0; i < N; i++){
    tot += abs(a[i] - i) * i;
  }
  return tot;
}
string solve(){
  double W1 = weight1();
  double W2 = weight2();
  //cout << W1 << ", " << W2 << endl;
  return W1 < W2? "GOOD" : "BAD";
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    cout << "Case #" << ++TestNum << ": " << solve() << endl;
  }
}

