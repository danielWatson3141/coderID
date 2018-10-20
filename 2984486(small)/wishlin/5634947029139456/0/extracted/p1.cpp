#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int cas, N, L, res, fpcnt;
string ans, fit;
string vol[160];
string cop[160];
map<string, int> mymap;

void flip(int n) {
  for (int i=0; i<N; ++i)
     cop[i][n] = cop[i][n]=='1'? '0':'1';
}

int main() {
   scanf("%d",&cas);

   for (int k=1; k<=cas; ++k) {
      scanf("%d %d", &N, &L);
      mymap.clear();
      res = 1000;
      for (int i=0; i<N; ++i) cin>>vol[i];
      for (int i=0; i<N; ++i) {cin>>ans; mymap[ans]=1;}

      for (int p=0; p<N; ++p) {
         fit = vol[p]; fpcnt=0;
         for (int j=0; j<N; ++j) cop[j]=vol[j];
         for (int n=0; n<fit.size(); ++n)
            if (fit[n]!=ans[n]) {flip(n); ++fpcnt;}
         for (int j=0; j<N; ++j)
            if (mymap.find(cop[j])==mymap.end()) {fpcnt=1000; break;}
         res = res>fpcnt? fpcnt:res;
      }
      if (res<1000) printf("Case #%d: %d\n",k,res);
      else printf("Case #%d: NOT POSSIBLE\n",k);
   }
   return 0;
}
