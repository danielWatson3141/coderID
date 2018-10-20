
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define     Z       2003
using namespace std;
struct node{
    int cost, sz;
    node(int c,int s){
        cost = c;
        sz = s;
    }
};
bool cmp(node a, node b){
    return a.cost+ b.sz < a.sz + b.cost;
}
int tot[Z];
vector<int> v[Z];

int DFS(int at, int par){

    tot[at] = 1;
    int i,now,cst,mincost;

    vector<node> res;
    res.clear();
    for(i = 0; i < v[at].size(); i++){
        now = v[at][i];
        if(now == par) continue;
        cst = DFS(now,at);
        node k = node(cst,tot[now]);
        res.push_back(k);
        tot[at]+=tot[now];
    }

    sort(res.begin(),res.end(),cmp);
    int nchild = res.size();
    if(nchild == 0) return 0;
    if(nchild == 1) return res[0].sz;

    mincost = res[0].cost + res[1].cost;
    for(i = 2;i < nchild; i++)
            mincost += res[i].sz;

    return mincost;
}
int main(){

    int t,tc,N,i;

    freopen("B-large.in","r",stdin);
    freopen("Blargeans.out","w",stdout);

    cin >> t;
    tc = 0;
    while(tc <t){
        tc++;
        cin >> N;

        for(i = 0;i <= N; i++)
            v[i].clear();

    int xi,yi,ans,now;
        for(i = 1; i < N; i++){
            cin >> xi>> yi;
            v[xi].push_back(yi);
            v[yi].push_back(xi);
        }

        ans = N;
        for(i = 1; i <= N; i++){
            now = DFS(i, -1);
            ans = min(now,ans);
        }

        printf("Case #%d: %d\n",tc,ans);
    }

    return 0;
}

