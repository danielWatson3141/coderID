#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

int ones(LL a) {
  if(a == 0) return 0;
  return ones(a >> 1) + (a & 1);
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRII(N, L);
    printf("Case #%d: ", t);
    V(LL) device(N), outlet(N);
    REP(i, N) {
      char s[41];
      RS(s);
      REP(j, L)
        outlet[i] = (outlet[i] << 1) | (s[j] - '0');
    }
    REP(i, N) {
      char s[41];
      RS(s);
      REP(j, L)
        device[i] = (device[i] << 1) | (s[j] - '0');
    }
    int ans = INF;
    sort(ALL(device));
    REP(i, N) {
      LL mask = outlet[i] ^ device[0];
      V(LL) tmp = outlet;
      FOR(v, tmp) v ^= mask;
      sort(ALL(tmp));
      if(tmp == device)
        ans = min(ans, ones(mask));
    }
    if(ans == INF)
      puts("NOT POSSIBLE");
    else
      PI(ans);
  }
  return 0;
}
