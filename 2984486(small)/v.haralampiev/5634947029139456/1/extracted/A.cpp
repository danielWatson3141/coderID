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
#define INF 1000000000
char buf[100];
void doit(int CASE){
  int N , L , ANS = INF;
  scanf("%d%d" , &N , &L);
  vector<string> beg , tar;
  for(int i=0;i<N;++i)
   scanf("%s" , &buf),
   beg.pb(string(buf));
  for(int i=0;i<N;++i)
   scanf("%s" , &buf),
   tar.pb(string(buf));
  sort(all(tar));
  for(int i=0;i<N;++i){
   vector<char> flip(L , 0);
   for(int j=0;j<L;++j)
    if(tar[0][j] != beg[i][j])
     flip[j] = 1;
   vector<string> nal = beg;
   for(int j=0;j<N;++j)
    for(int k=0;k<L;++k)
     if(flip[k])
      nal[j][k] = ((nal[j][k]-'0')^1) +'0';
   sort(all(nal));
   if(nal == tar) relaxMin(ANS , count(all(flip) , 1));
                      }
  printf("Case #%d: " , CASE);
  if(ANS == INF)
   puts("NOT POSSIBLE");
  else
   printf("%d\n" , ANS);
}
int main(){
  int Q;
  scanf("%d" , &Q);
  for(int i=1;i<=Q;++i)
   doit(i);
  return 0;
}
