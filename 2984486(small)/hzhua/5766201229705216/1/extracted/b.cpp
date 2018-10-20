#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
int child_cnt[1010];
int edge[1010][1010];
int edge_cnt[1010];
int N;
void add_edge(int x,int y){
    edge[x][edge_cnt[x]++] = y;
    edge[y][edge_cnt[y]++] = x;
}
int count_child(int x ,int fat){
    child_cnt[x] = 1;
    for(int i = 0 ; i < edge_cnt[x]; i++){
        int y = edge[x][i];
        if(y == fat) continue;
        child_cnt[x] += count_child(y, x);
    }
    return child_cnt[x];
}
int dfs(int x, int fat){
    int e = 0;
    for(int i = 0 ; i < edge_cnt[x]; i++){
        int y = edge[x][i];
        if(y == fat) continue;
        e++;
    }
    int ret = 0;
    if(e != 0 && e!=2){
        if(e == 1){
            for(int i = 0 ; i < edge_cnt[x]; i++){
                int y = edge[x][i];
                if(y == fat) continue;
                ret += child_cnt[y];
            }
        }else{
            vector<pair<int,int> > tmp;
            for(int i = 0 ; i < edge_cnt[x]; i++){
                int y = edge[x][i];
                if(y == fat) continue;
                tmp.push_back(make_pair(child_cnt[y], y));
            }
            sort(tmp.begin(), tmp.end());
            for(int i = 0 ; i < tmp.size()-2;i++){
                ret+= tmp[i].first;
            }
            for(int i = tmp.size()-2; i<tmp.size(); i++){
                ret += dfs(tmp[i].second, x);
            }
        }
        return ret;
    }

    for(int i = 0 ; i < edge_cnt[x]; i++){
        int y = edge[x][i];
        if(y == fat) continue;
        ret += dfs(y,x);
    }
    return ret;
}
int solve(int root){
    memset(child_cnt, 0 , sizeof(child_cnt));
    count_child(root ,-1);
    int ret = dfs(root,-1);
    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int _ = 1; _ <=T; _++){
        memset(edge_cnt,0, sizeof(edge_cnt));

        scanf("%d",&N);
        for(int i = 0; i < N-1;i++){
            int x ,y;
            scanf("%d%d", &x,&y);
            add_edge(x-1,y-1);
        }
        int ans = INF;
        for(int i = 0 ; i< N;i++){
            int ta = solve(i);
            if(ta < ans){
                ans = ta;
            }
        }
        printf("Case #%d: %d\n",_,ans);
    }
}
