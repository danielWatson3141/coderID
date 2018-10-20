
// @snippet<sh19910711/contest-base-simple:header.cpp>
// #define __THIS_IS_CPP11__
/* default headers {{{ */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdio>
#include <cmath>

#ifdef __THIS_IS_CPP11__
#include <memory>
#include <array>
#endif
/* }}} */


// @snippet<sh19910711/contest-base-simple:solution/template-typedef.cpp>
namespace solution {
  using namespace std;
  /* primitives {{{ */
  typedef long long Int;
  typedef long double Double;
  /* }}} */
}

// @snippet<sh19910711/contest-base-simple:solution/template-constants.cpp>
namespace solution {
  const Int MAX_N = 200 + 11;
  const Int MAX_L = 40 + 11;
  const Int NONE = -1;
}

// @snippet<sh19910711/contest-base-simple:solution/template-storages.cpp>
namespace solution {
  struct Input {
    Int N;
    Int L;
    string A[2][MAX_N];
  };
  
  struct Output {
    Int res;
  };
}

// @snippet<sh19910711/contest-base-simple:solution/solution-io.cpp>
namespace solution {
  struct SolutionIO {
    Input in;
    Output out;
    
    template <class Stream> bool input( Stream& s ) {
      s >> in.N >> in.L;
      for ( int i = 0; i < 2; ++ i ) {
        for ( int j = 0; j < in.N; ++ j ) {
          s >> in.A[i][j];
        }
      }
      return true;
    }
    
    template <class Stream> bool output( Stream& s ) {
      if ( out.res == NONE ) {
        s << "NOT POSSIBLE";
      } else {
        s << out.res;
      }
      return s << endl;
    }
  };
}

// @snippet<sh19910711/contest-base-simple:solution/solution.cpp>
namespace solution {
  struct Solution: SolutionIO {
    //
    // Implement here
    //

    typedef queue <Int> IntQueue;
    typedef map <Int, Int> IntMap;
    
    Int N;
    Int L;
    string A[2][MAX_N];
    Int C[2][MAX_L];

    IntQueue Q;
    IntMap M;

    string T[MAX_N];

    Solution() {}

    void init() {
      N = in.N;
      L = in.L;
      for ( int i = 0; i < 2; ++ i ) copy(in.A[i], in.A[i] + in.N, A[i]);
    }
    
    bool solve() {
      init();
      out.res = find();
      return true;
    }

    bool need_update( const Int& mask, const Int& steps ) {
      if ( ! M.count(mask) ) return true;
      return steps < M[mask];
    }

    bool check( const Int& mask ) {
      copy(A[0], A[0] + N, T);
      for ( int k = 0; k < N; ++ k ) {
        for ( Int i = 0; i < L; ++ i ) {
          Int bi = Int(1) << i;
          if ( mask & bi ) {
            T[k][i] = '1' - ( A[0][k][i] - '0' );
          } else {
            T[k][i] = A[0][k][i];
          }
        }
      }
      sort(T, T + N);
      for ( Int i = 0; i < N; ++ i ) {
        if ( T[i] != A[1][i] ) return false;
      }
      return true;
    }

    Int find() {
      sort(A[1], A[1] + N);
      Q = IntQueue();
      M.clear();

      Q.push(Int(0));
      M[Int(0)] = Int(0);
      while ( ! Q.empty() ) {
        Int mask = Q.front();
        Q.pop();
        Int steps = M[mask];

        if ( check(mask) ) {
          return steps;
        }

        for ( Int k = 0; k < L; ++ k ) {
          Int next_mask = mask | ( Int(1) << k );
          Int next_steps = steps + 1;
          if ( ! need_update(next_mask, next_steps) ) continue;
          M[next_mask] = next_steps;
          Q.push(next_mask);
        }
      }
      return NONE;
    }
    
    /* action methods {{{ */
    void before_action( const int& t_id ) {
      cout << "Case #" << (t_id + 1) << ": ";
    }
    
    void after_action( const int& t_id ) {}
    
    bool action( const int& t_id = -1 ) {
      before_action(t_id);
      bool res = input(std::cin) && solve() && output(std::cout);
      after_action(t_id);
      return res;
    }
    /* }}} */
  };
}

// @snippet<sh19910711/contest-base-simple:solution/runner-multi-test.cpp>
namespace solution {
  /* Runner Class {{{ */
  struct Runner {
    static int run() {
      int tests;
      std::cin >> tests;
      for ( int i = 0; i < tests; ++ i ) {
        Solution* sol = new Solution;
        sol->action(i);
        delete sol;
      };
      return 0;
    }
  };
  /* }}} */
}

// @snippet<sh19910711/contest-base-simple:main_func.cpp>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  return solution::Runner::run();
}

// @snippet<sh19910711/contest-base-simple:main.cpp>


