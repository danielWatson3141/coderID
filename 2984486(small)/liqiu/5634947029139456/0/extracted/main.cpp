#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <bitset>
#include <vector>
#include <set>

using namespace std;
#define pb push_back
const int maxn = 210;
int charge[maxn];
int out[maxn];
int require[maxn];
char str[maxn];
int n, L;
const int inf = 1e8;
vector<int> edge[maxn];
int match[maxn];
bool use[maxn];
//DO NOT FORGET TO INIT ALL PARAMETERS BEFORE RUNNING MAX-MATCH
void init(){
    memset(match, -1, sizeof(match));
    for(int i = 0; i < maxn; ++i)
        edge[i].clear();
}

bool dfs(int s)
{
    int i;
    for(i=0;i<edge[s].size();i++){
        int x=edge[s][i];
        if(!use[x] ){
            use[x]=true;
            int tmp=match[x];
            match[x]=s;
            if(tmp==-1 || dfs(tmp))
                return true;
            match[x]=tmp;
        }
    }
    return 0;
}
int Match()
{
    int res=0;
    int i;
    for(i=0;  i < n; i++){
        memset(use,0,sizeof(use));
        if(dfs(i))
            res++;
    }
    return res;
}


bool legal(int s ){
//    cout<<"legal"<<endl;
    for(int i = 0; i < n; ++i) out[i] = charge[i];
    bitset<21> b = s;
    for(int i = 0; i < L; ++i){
        if( b[i] ){
            for(int j = 0; j < n; ++j){
                if( out[j] &(1<<i) ) out[j] -= (1<<i);
                else out[j] += (1<<i);
            }
        }
    }
    init();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if( require[i] == out[j])
                edge[i].pb( j );
    return Match() == n;
}

int main(){
//    freopen("in.txt", "r", stdin );
    freopen("Ain.txt", "r", stdin );
    freopen("Aout.txt", "w", stdout );
    int tcase; int tno = 0;
    cin>>tcase;
    while(tcase--){
        cin>>n>>L;
        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            int sum = 0;
            for(int j = 0; j < L; ++j){
                sum <<= 1;
                if( str[j] == '1' ) sum++;
            }
            charge[i] = sum;
        }
        //get require
         for(int i = 0; i < n; ++i){
            scanf("%s", str);
            int sum = 0;
            for(int j = 0; j < L; ++j){
                sum <<= 1;
                if( str[j] == '1' ) sum++;
            }
            require[i] = sum;
        }
        int res = inf;
        for(int s = 0; s < (1<<L); ++s){
            bitset<21> b = s;
            if( legal(s) )
                res = min(res, (int) b.count() );
        }
        printf("Case #%d: ", ++tno);
        if( res == inf ) printf("NOT POSSIBLE\n");
        else printf("%d\n", res);
    }
    return 0;
}
