#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>
#include<cassert>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

const double PI = 4.0*atan(1.0);

int main() {
  int t,caseNo=1;
  cin>>t;
  while(t--){
    int N,L;
    cin>>N>>L;
    vector<string> outlet(N), need(N);
    FOR(i,N) cin>>outlet[i];
    FOR(i,N) cin>>need[i];
    set<string> S(ALL(need));
    int ans = 100000;
    FOR(b,(1<<L)) {
      int flipNum = __builtin_popcount(b);
      set<string> after;
      for(auto s : outlet) {
        string s2 = s;
        FOR(i,L) if(b & (1<<i)) {
          s2[i] = (s2[i] == '1') ? '0' : '1';
        }
        after.insert(s2);
      }
      if(S == after) ans = min(ans, flipNum);
    }

    printf("Case #%d: ", caseNo++);
    if(ans < 100000) printf("%d\n", ans);
    else puts("NOT POSSIBLE");
  }
  return 0 ;
}
