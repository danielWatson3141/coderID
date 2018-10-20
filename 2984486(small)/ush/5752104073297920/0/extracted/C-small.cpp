
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>
#include <limits>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;


inline unsigned long xor128(){ 
    static unsigned long x=123456789,y=362436069,z=521288629,w=88675123; 
    unsigned long t; 
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); 
} 

int as[1010];
int n;

bool isGood() {
  const int C1 = 102;
  const int C2 = 108;
  double v = 0;
  REP(i, n){
    int d = as[i] - i;
    if(1 <= d && d <= C1){
      v++;
    }
  }
  return v < C2;
}


// bool isGood() {
//   const int C1 = 30;
//   const int C2 = 10;
//   double v = 0;
//   for(int i = 0; i < n/10; ++i){
//     int d = as[i] - i;
//     if(1 <= d && d <= C1){
//       v++;
//     }
//   }
//   for(int i = n-n/10; i < n; ++i){
//     int d = as[i] - i;
//     if(1 <= d && d <= C1){
//       v++;
//     }
//   }
//   return v < C2;
// }

// bool isGood() {
//   const double C1 = 100;
//   const double C2 = 1;
//   double v = 0;
//   REP(i, n){
//     double d = as[i] - i;
//     if(1 <= d && d <= C1){
//       v += 1/d/d;
//     }
//   }
//   return v < C2;
// }


void generate(bool good) {
  REP(k, n)
    as[k] = k;
  REP(k, n){
    int p;
    if(good){
      p = xor128() % (n-k) + k;
    }else{
      p = xor128() % n;
    }
    swap(as[k], as[p]);
  }
}



int hist[1010][1010];
int main(void) {
//   n = 100;
//   int nTry = 100000;
//   REP(i, nTry){
//     REP(k, n)
//       as[k] = k;
//     REP(k, n){
//       int p = xor128() % n;
//       swap(as[k], as[p]);
//     }
//     REP(k, n){
// //       cerr << as[k] << " ";
//       hist[as[k]][k]++;
//     }
// //     cerr << endl;
//   }
//   REP(k, n){
//     cerr << k << ": ";
//     REP(i, n){
//       if(hist[k][i] > nTry * 1.3 / n){
// 	cerr << "(pos=" << i << " with hist=" << hist[k][i] << ")";
//       }
// //       cerr << hist[k][i] << " ";
//     }
//     cerr << endl;
//   }
  
//   int nTry = 10000;
//   n = 1000;
//   int acGB = 0;
//   int acGG = 0;
//   int acBB = 0;
//   int acBG = 0;
//   REP(i, nTry){
//     bool good = xor128() % 2 == 1;
//     generate(good);
//     bool res = isGood();
//     if(good && res){
//       acGG++;
//     }else if(good && !res){
//       acGB++;
//     }else if(!good && res){
//       acBG++;
//     }else{
//       acBB++;
//     }
//   }
//   cerr << (acGG+acBB) << "/" << nTry << endl;
//   cerr << "acGG = " << acGG << endl;
//   cerr << "acGB = " << acGB << endl;
//   cerr << "acBG = " << acBG << endl;
//   cerr << "acBB = " << acBB << endl;


  int nCase;
  cin >> nCase;
  REP(iCase, nCase){
    cin >> n;
    double v = 0;
    REP(i, n){
      cin >> as[i];
    }
    printf("Case #%d: %s\n", iCase+1, isGood() ? "GOOD" : "BAD");
  }
  return 0;
}
