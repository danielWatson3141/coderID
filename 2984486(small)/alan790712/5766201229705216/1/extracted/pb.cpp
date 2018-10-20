#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int T, N;
int ans;
int isgo[1005], child[1005], minDel[1005], total[1005];
vector<int> edge[1005], temp;

void Dfs(int now, int par)
{

    int i, nxt, t;

    child[now]=0;
    total[now]=0;
    for(i=0;i<(int)edge[now].size();i++){
        nxt=edge[now][i];
        if(!isgo[nxt]){
            child[now]++;
            isgo[nxt]=1;
            Dfs(nxt, now);
            total[now]+=total[nxt]+1;
        }
    }
    //printf(" now:%d\n", now);
    //printf("  child:%d\n", child[now]);
    if(child[now]==0){
        minDel[now]=0;
        //printf("  minDel:%d\n", minDel[now]);
        return;
    }
    else if(child[now]==1){
        minDel[now]=1;
        for(i=0;i<(int)edge[now].size();i++){
            nxt=edge[now][i];
            if(nxt==par) continue;
            minDel[now]=total[nxt]+1;
        }
        //printf("  minDel:%d\n", minDel[now]);
    }
    else{
        temp.clear();
        t=0;
        for(i=0;i<(int)edge[now].size();i++){
            nxt=edge[now][i];
            if(nxt==par) continue;
            t+=total[nxt]+1;
            temp.push_back(total[nxt]+1-minDel[nxt]);
        }
        sort(temp.begin(), temp.end());
        minDel[now]=t-temp[(int)temp.size()-1]-temp[(int)temp.size()-2];
        //printf("  minDel:%d\n", minDel[now]);
    }


}

void Del(int d)
{
    //printf("del:%d\n", d);
    memset(isgo, 0, sizeof(isgo));
    isgo[d]=1;
    Dfs(d, -1);
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int x, y, t, i;

    scanf("%d", &T);
    for(t=1;t<=T;t++){
        scanf("%d", &N);
        for(i=0;i<=N;i++) edge[i].clear();
        for(i=0;i<N-1;i++){
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        ans=N-1;
        for(i=1;i<=N;i++){
            Del(i);
            ans=min(ans, minDel[i]);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
