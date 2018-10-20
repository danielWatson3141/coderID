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
double MID = 0;
int N = 1000;
int CG = 0 , CB = 0;
void doit(int CASE){
  scanf("%d" , &N);
  vi in(N) , pos(N);
  for(int i=0;i<N;++i)
   scanf("%d" , &in[i]),
   pos[in[i]] = i;
  int type = 0;
  for(int i=0;i<N;++i)
   if(pos[i] < i) ++type;
  printf("Case #%d: " , CASE);
  if(type <= 1.037 * MID) ++CG , puts("GOOD");
  else ++CB , puts("BAD");
}
int main(){
  for(int i=1;i<N;++i)
   MID += i;
  MID /= N;
  int Q;
  scanf("%d" , &Q);
  for(int i=1;i<=Q;++i)
   doit(i);
  //cout<<CG<<' '<<CB<<endl;
  return 0;
}
