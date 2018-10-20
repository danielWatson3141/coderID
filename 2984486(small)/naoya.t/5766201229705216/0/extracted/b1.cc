#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

// #include "cout.h"

;
vector<vector<bool> > m;
vector<bool> vs(15), pt(15);
int N;

bool sub(int rt){
  //printf("sub(%d)...\n", rt);
  int c=0;
  vs[rt] = true;
  rep(n,N) {
    if(n==rt)continue;
    if(!pt[n])continue;
    if (!m[rt][n]) continue;
    if(vs[n])continue;
    //printf("looking %d - %d\n", rt, n);
    ++c; if(c>2) return false;
    if(!sub(n)) return false;
  }
  return (c==0 || c==2);
}

bool ok(int rt){
  //printf("ok(rt=%d)...\n", rt);
  //cout << pt << endl;
  //if (!pt[rt]) return false;
  vs.assign(N, false);

  if (!sub(rt)) {
    // printf("NG\n");
    return false;
  }

  rep(i,N) {
    if (!pt[i]) continue;
    if (!vs[i]) {
      //printf("%d not visited\n", i);
      return false;
    }
  }
  //printf("OK\n");
  return true;
}

int main(){
  int _T; cin>>_T; // 1-100
  rep(_t,_T){
    cin >> N;
    int best = 99;

    m.assign(15, vector<bool>(15, false));
    //rep(i,15) rep(j,15) m[i][j] = false;

    rep(i, N-1) {
      int xi, yi; cin >> xi >> yi;
      --xi; --yi;
      m[xi][yi] = m[yi][xi] = true;
    }
    //cout << m << endl;

    int P = 1 << N;
    for (int p=0; p<P; ++p) {
      //printf("p=%d\n", p);
      rep(i,N) { pt[i] = true; vs[i] = false; }
      int pc=0;
      for (int i=0,m=1; m<=P; ++i,m<<=1) {
        //printf("m=%d, i=%d\n", m,i);
        if (p&m) { pt[i] = false; ++pc; }
      }
      rep(rt,N){
        if (ok(rt)) {
          //int bc = __builtin_popcount(p);
          if (pc < best) best = pc;
        }
      }
    }

 answer:
    cout << "Case #" << (1+_t) << ": " << best << endl;
  }
  return 0;
}
