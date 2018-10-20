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

ll count_tree(std::vector<std::vector<int> > edges,
	      int i) {
  ll sum=0;
  for(int j : edges[i])
    sum += count_tree(edges, j);
  return sum+1;
}

ll solve_tree(std::vector<std::vector<int> > edges,
	      int i) {

  std::vector<std::pair<ll,ll> > vals; //solve,count
  for(int j : edges[i]) {
    vals.push_back(std::pair<ll,ll> (solve_tree(edges, j),
				     count_tree(edges, j))
		   );
  }

  if(vals.size()==1)
    return vals[0].second;

  if(vals.size() == 0)
    return 0;
    
  ll optsum = 0;
  std::vector<ll> optvals;
  for(auto x : vals) {
    optvals.push_back(x.first - x.second);
    optsum += x.second;
  }
    
  std::sort(optvals.begin(), optvals.end());
  
  return (optsum + optvals[0] + optvals[1]);
}

std::vector<std::vector<int> > gen_tree(std::vector<std::vector<int> > edges,
	      int i) {
  std::vector<std::vector<int> > edges_tree;
  for(int i=0; i<edges.size(); i++)
    edges_tree.push_back(std::vector<int>());

  bool visited[2000] = {0,};

  std::vector<int> stack;
  stack.push_back(i);
  visited[i] = 1;
  while(!stack.empty()) {
    int j = stack.back();
    stack.pop_back();
    for(int k : edges[j]) {
      if(visited[k]) continue;
      edges_tree[j].push_back(k);
      visited[k] = true;
      stack.push_back(k);
    }
  }
  return edges_tree;
}

ll solve() {
  int N;
  std::cin >> N;

  std::vector<std::vector<int> > edges;
  for(int i=0; i<N; i++)
    edges.push_back(std::vector<int>());

  for(int i=0; i<N-1; i++) {
    int X;
    int Y;
    std::cin >> X;
    std::cin >> Y;
    X--;
    Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }


  ll min=N;
  for(int i=0; i<N; i++) {
    std::vector<std::vector<int> > edges_tree =
      gen_tree(edges, i);
    
    ll val = solve_tree(edges_tree, i);
    if(val<min)
      min = val;

  }
  return min;
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
    //CHOOSE A
    auto res = solve();
    std::cout << "Case #" << i << ": " << res << "\n";
  }

  return 0;
}
