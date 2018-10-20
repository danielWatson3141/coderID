/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some C++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including the library in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>
#include <cmath>

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <gmpxx.h>

typedef long long ll;
typedef unsigned long long ull;

typedef mpz_class mpz;

template<typename T>
void read_to_vector(size_t N, std::vector<T> &v) {
  for(size_t i=0; i<N; i++) {
    T tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
}
template<typename T>
void print_vector(const std::vector<T> &v) {
  for(auto it = v.begin(); it<v.end(); it++) {
    if(it==v.begin())
      std::cout << " ";
    std::cout << (*it);
  }
}

//Copy functions from TCR here.



//Solution:

void solve() {
  int N, L;
  std::cin >> N;
  std::cin >> L;

  std::vector<ll> devs;
  for(int i=0; i<N; i++) {
    std::string s;
    std::cin >> s;
    ll tmp = 0;
    for(int j=0; j<L; j++)
      tmp += (s[j]-'0') * (1LLU<<(L-1-j));
    devs.push_back(tmp);
  }
  std::vector<ll> vals;
  for(int i=0; i<N; i++) {
    std::string s;
    std::cin >> s;
    ll tmp = 0;
    for(int j=0; j<L; j++)
      tmp += (s[j]-'0') * (1LLU<<(L-1-j));
    vals.push_back(tmp);
  }


  //Small
  std::array<int,2000> devcounts;
  for(int i=0;i<2000;i++) 
    devcounts[i]=0; 
  for(ll i : devs) 
    devcounts[i]++;

  ll min=L+1;
  for(ull i=0; i<(1LLU<<L); i++) {
    if(__builtin_popcountll(i)>=min)
      continue;
    auto thiscounts = devcounts;
    bool valid=true;
    for(int j=0; j<N; j++) {
      thiscounts[vals[j] ^ i]--;
      if(thiscounts[vals[j] ^ i]<0)
	valid=false;
    }
    if(valid) {
      min = __builtin_popcountll(i);
    }
  }

  if(min==L+1)
    std::cout << "NOT POSSIBLE";
  else
    std::cout << min;
}

//This is executed before any input is read.
void pre_compute() {
  
}

int main() {
  std::cout << std::setprecision(15);
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    std::cout << "Case #" << i << ": ";
    solve();
    std::cout << "\n";
  }

  return 0;
}
