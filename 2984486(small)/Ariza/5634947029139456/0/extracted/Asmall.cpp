#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))
typedef vector<int> VI;
typedef vector<VI> VVI;

string current[150];
string targets[150];

void init(){
     for (int i=0;i<150;++i){
         current[i]=targets[i]="";
     }
}
bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
int check(string str,int n,int l){
    VVI graph;
    VI tmp,mr,mc;
    for (int i=0;i<n;++i) tmp.pb(0);
    for (int i=0;i<n;++i){
        graph.pb(tmp);
    }
    string stmp;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            stmp=current[j];
            for (int k=0;k<l;++k){
                if (str[k]=='1'){
                   if (stmp[k]=='0') stmp[k]='1';
                   else stmp[k]='0';
                }
            }
            if (targets[i]==stmp){
               graph[i][j]=1;
            }
        }
    }
    int ret=BipartiteMatching(graph,mr,mc);
    if (ret==n){
       int tmp=0;
       for (int i=0;i<l;++i) if (str[i]=='1') tmp++;
       return tmp;
    }
    return 1000000000;
}
void solve(){
     printf(" ");
     init();
     int n,l;
     scanf("%d %d",&n,&l);
     for (int i=0;i<n;++i){
         cin >> current[i];
     }
     for (int i=0;i<n;++i){
         cin >> targets[i];
     }
     string str;
     int ret=1000000000;
     for (int i=0;i<(1<<l);++i){
         str="";
         for (int j=0;j<l;++j){
             if (i & (1<<j)){
                str+='1';
             }
             else
                 str+='0';
         }
         ret=min(ret,check(str,n,l));
     }
     if (ret==1000000000) printf ("NOT POSSIBLE\n");
     else printf("%d\n",ret);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
