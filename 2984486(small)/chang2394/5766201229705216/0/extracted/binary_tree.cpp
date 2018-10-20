#include <bits/stdc++.h>
using namespace std;
const int MAX = 1123;
struct EDGE{
    int to,from;
} edge[2*MAX];

int head[MAX],childs[MAX],N,E = 0;
bool vis[MAX];
void addEdge(int a,int b){
    edge[E].to = b;
    edge[E].from = head[a];
    head[a] = E++;
}

int dfs(int st){
    vis[st] = true;
    int branch = 0;
    int mx1 = 0, mx2 = 0;

    for(int i = head[st]; i != -1; i = edge[i].from){
        int x = edge[i].to;
        if (vis[x]) continue;
        int res = dfs(x);
        ++branch;
        childs[st] += childs[x] + 1;
        if (res > mx1) mx2 = mx1, mx1 = res;
        else mx2 = max(mx2,res);
    }
    vis[st] = false;
    if (branch < 2)
        return 1;
    int ans = 1;
    ans = max(ans,mx1+mx2+1);
    return ans;
}

void solve(){
    E = 0;
    memset(head,-1,sizeof(head));
    cin >> N;

    int a,b;
    for(int i = 0; i < N-1; i++)
        cin >> a >> b, addEdge(a,b), addEdge(b,a);
    int ans = INT_MAX;
    for(int i = 1; i <= N; ++i){
        memset(childs,0,sizeof(childs));
        int res = dfs(i);
        int deleted = childs[i] + 1 - res;
        ans = min(ans,deleted);
    }
    cout << ans << endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int i = 1; i <= t; ++i)
        cout << "Case #" << i << ": ",solve();
    //
}
