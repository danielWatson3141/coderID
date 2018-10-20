/*
 *Author:       Zhaofa Fang
 *Created time: 2014-04-26-09.31 Saturday
 */
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n-1);i>=0;i--)
#define PII pair<int,int>
#define PB push_back
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)
#define eps (1e-8)

const int maxL = 12;
const int maxN = 12;
char str1[maxN][maxL];
char str2[maxN][maxL];
int N,L;
bool vist[maxL];
int ans;

bool check(){
    memset(vist,0,sizeof(vist));
    REP(i,N){
        bool OK = 0;
        REP(j,N){
            if(vist[j])continue;
            if(strcmp(str1[i],str2[j])==0){
                vist[j] = 1;
                OK = 1;
                break;
            }
        }
        if(!OK)return false;
    }
    return true;
}
void dfs(int cur,int tot){
    if(cur>=L){
        if(check())ans = min(ans,tot);
        return;
    }
    dfs(cur+1,tot);

    REP(i,N)str1[i][cur] = (str1[i][cur]-'0'?'0':'1');
    dfs(cur+1,tot+1);
    REP(i,N)str1[i][cur] = (str1[i][cur]-'0'?'0':'1');
}
int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin>>T;
    FOR(cas,1,T){
        printf("Case #%d: ",cas);
        cin>>N>>L;
        REP(i,N){
            scanf("%s",str1[i]);
        }
        REP(i,N){
            scanf("%s",str2[i]);
        }
        ans = INF;
        dfs(0,0);
        if(ans>=INF)puts("NOT POSSIBLE");
        else printf("%d\n",ans);
    }
    return 0;
}
