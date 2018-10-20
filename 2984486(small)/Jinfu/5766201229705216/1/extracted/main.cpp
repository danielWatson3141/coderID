//
//  main.cpp
//  gcj
//
//  Created by Jinfu Leng on 4/11/14.
//  Copyright (c) 2014 jinfu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int INF = 1000000;
vector<int> edges[1005];
int dp[1005][1005];
int dp2[1005][1005];

int CntRemove(int c, int last){
    if(dp2[c][last] >= 0) return dp2[c][last];
    int cnt = 1;
    for(int i = 0; i< edges[c].size(); i++){
        int node = edges[c][i];
        if(node == last) continue;
        cnt += CntRemove(node, c);
    }
    dp2[c][last] = cnt;
    return dp2[c][last];
}

int Search(int c, int last){
    if(dp[c][last] >= 0) return dp[c][last];
    int size = edges[c].size();
    if(last != c) size--;
    if(size == 0) return 0;
    if(size == 1){
        int next = edges[c][0];
        if(next == last)
            next = edges[c][1];
        return CntRemove(next, c);
    }
    int best = INF;
    //cout<<"here"<<endl;
    for(int i = 0; i < edges[c].size(); i++){
        int node = edges[c][i];
        if(node == last) continue;
        for(int j = i + 1; j < edges[c].size(); j++){
            int node2 = edges[c][j];
            if(node2 == last) continue;
            int cnt = Search(node, c) + Search(node2, c);
            for(int k = 0; k< edges[c].size(); k++){
                if(edges[c][k] != last && edges[c][k] != node && edges[c][k] != node2)
                    cnt += CntRemove(edges[c][k], c);
            }
            best = min(best, cnt);
        }
    }
    dp[c][last]=best;
    return dp[c][last];
}

void Solve(){
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        edges[i].clear();
    
    for(int i = 0; i < N - 1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int best = INF;
    for(int i = 0; i < N; i++){
        best = min(best, Search(i, i));
        //cout<<i<<" "<<Search(i, i)<<endl;
    }
    printf("%d\n",best);
}
int main(int argc, const char * argv[])
{
    freopen("/Users/jinfu/Workspace/test/input.in","r",stdin);
    freopen("/Users/jinfu/Workspace/test/output","w",stdout);
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        printf("Case #%d: ", t+1);
        Solve();
    }
    return 0;
}