#ifdef _WIN32
#  define LL "%I64d"
#else
#  define LL "%Ld"
#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <complex>
#include <utility>
#include <cassert>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
vector< vi > fo;
pii dfs(int vr , int par = -1){
  vi wgt;
  int subtree = 1;
  int ALL = 0;
  for(int i=0;i<sz(fo[vr]);++i)
   if(fo[vr][i] != par){
    pii tmp = dfs(fo[vr][i] , vr);
    subtree += tmp.fi;
    ALL += tmp.fi;
    wgt.pb(tmp.fi - tmp.se);
                       }
  int best = subtree - 1;
  sort(all(wgt)) , reverse(all(wgt));
  if(sz(wgt) >= 2){
   ALL -= wgt[0] + wgt[1];
   relaxMin(best , ALL);
                  }
  return mp(subtree , best);
}
void doit(int CASE){
  fo.clear();
  int N;
  scanf("%d" , &N);
  fo.resize(N);
  for(int i=1;i<N;++i){
   int a , b;
   scanf("%d%d" , &a , &b);
   --a , --b;
   fo[a].pb(b) , fo[b].pb(a);
                      }
  int BEST = 1000000000;
  for(int i=0;i<N;++i)
   relaxMin(BEST , dfs(i , -1).se);
  printf("Case #%d: " , CASE);
  printf("%d\n" , BEST);
}
int main(){
  int Q;
  scanf("%d" , &Q);
  for(int i=1;i<=Q;++i)
   doit(i);
  return 0;
}
