#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> edge[1005];
int kasus,N;

int dfs(int node,int parent) {
    if (edge[node].size() < 3) return 1;
    int b1 = 0,b2 = 0;
    for (int i=0;i<edge[node].size();++i) {
        if (edge[node][i] == parent) continue;            
        int temp = dfs(edge[node][i],node);
        if (temp > b1) {
            b2 = b1;
            b1 = temp;
        } else if (temp > b2) {
            b2 = temp;
        }
    }
    return b1+b2+1;
}

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&N);
        for (int i=1;i<=N;++i) edge[i].clear();
        
        for (int i=1,j,k;i<N;++i) {
            scanf("%d %d",&j,&k);
            edge[j].push_back(k);
            edge[k].push_back(j);
        }
        
        int jawab = N-1;
        for (int i=1;i<=N;++i) {
            if (edge[i].size() == 1) continue;
            int b1 = 0,b2 = 0;
            for (int j=0;j<edge[i].size();++j) {
                int temp = dfs(edge[i][j],i);
                if (temp > b1) {
                    b2 = b1;
                    b1 = temp;
                } else if (temp > b2) {
                    b2 = temp;
                }
            }
            
            if (jawab > N-(1+b1+b2)) jawab = N-(1+b1+b2);
        }
        
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
