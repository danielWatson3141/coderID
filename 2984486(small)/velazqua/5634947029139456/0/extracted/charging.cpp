#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

char flipBit (char c) {
  if (c == '0')
    return '1';
  else
    return '0';
}

string flipBits (string s, vector<int> &ind) {
  REP(i, SZ(ind)) {
    s[ind[i]] = flipBit(s[ind[i]]);
  }
  return s;
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    int N, L;
    cin >> N >> L;
    vector<string> curr(N), des(N);
    REP(i, N) {
      cin >> curr[i];
    }
    REP(i, N) {
      cin >> des[i];
    }
    sort(des.begin(), des.end());

    int minn = 1000000;
    REP(i, N) {
      //determine which bits need to be flipped
      vector<int> flips;
      REP(k, L) {
        if (curr[0][k] != des[i][k]) {
          flips.push_back(k);
        }
      }

      vector<string> newBits;
      REP(j, N) {
        newBits.push_back(flipBits(curr[j], flips));
      }

      sort(newBits.begin(), newBits.end());
      // check if both vectors are the same
      if (newBits == des) {
        minn = min(minn, SZ(flips));
      }
    }
    cout << "Case #" << t+1 << ": ";
    if (minn == 1000000)
      cout << "NOT POSSIBLE" << endl;
    else
      cout << minn << endl;
  }
}
