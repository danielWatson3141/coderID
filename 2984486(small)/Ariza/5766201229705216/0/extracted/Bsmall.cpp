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

int N;
vector<int> graph[1000];
int memo[1000];
int bug;
void init(){
     for (int i=0;i<1000;++i) graph[i].clear();
}
pair<int,int> binaryroot(int x){
     vector<pair<int,int> > ans;
     pair<int,int> tmp;
     for (int i=0;i<graph[x].size();++i){
         int y=graph[x][i];
         if (!memo[y]){
            memo[y]=1;
            tmp=binaryroot(y);
            ans.pb(tmp);
         }
     }
     sort(ans.begin(),ans.end());
     if (ans.size()==1){
        ans[0].first=(ans[0].second);
        ans[0].second++;
        return ans[0];
     }
     int ctrx=0,ctry=1;
     for (int i=0;i<ans.size();++i){
         if (i<2){
            ctrx+=ans[i].first;
         }
         else{
              ctrx+=ans[i].second;
         }
         ctry+=ans[i].second;
     }
     return mp(ctrx,ctry);
}
int checkbinary(int root){
     memset(memo,0,sizeof(memo));
     memo[root]=1;
     pair<int,int> ret = binaryroot(root);
     return ret.first;
}
void solve(){
     printf(" ");
     init();
     scanf("%d",&N);
     int a,b;
     for (int i=0;i<N-1;++i){
         scanf("%d %d",&a,&b);
         graph[a-1].pb(b-1);
         graph[b-1].pb(a-1);
     }
     for (int i=0;i<N;++i){
         sort(graph[i].begin(),graph[i].end());
     }
     int ret=1000000000,tmp;
     for (int root=0;root<N;++root){
         tmp=checkbinary(root);
         ret=min(ret,tmp);
     }
     printf("%d\n",ret);
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
