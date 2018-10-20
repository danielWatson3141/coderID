#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 1010;
int n, top;
int num[MAXN], vis[MAXN];
struct node{
    int to;
    node *next;
}*head[MAXN], e[MAXN*2];
void add(int from, int to){
    node *p = &e[top++];
    p->to = to; p->next = head[from]; head[from] = p;
}
void dfs(int x){//printf("%d\n", x);
    vis[x] = 1;
    int ret = 0;
    int fsum = 0, ssum = 0;
    for(node *p = head[x]; p; p = p->next){
        if(vis[p->to]) continue;
        dfs(p->to);
        ret++;
        if(num[p->to] > fsum){
            ssum = fsum;
            fsum = num[p->to];
        }
        else if(num[p->to] > ssum){
            ssum = num[p->to];
        }//if(x == 2) printf("%d %d %d\n", p->to, fsum, ssum);
    }
    if(ret >= 2){
        num[x]+=(fsum+ssum);
    }//printf("%d %d %d %d\n", x, num[x], fsum, ssum);
}
int main(){
    int T, cnt = 1;
    int x, y;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        top = 0;
        memset(head, 0, sizeof(head));
        for(int i = 1; i < n; i++){
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) num[j] = 1;
        memset(vis, 0, sizeof(vis));
       // dfs(2);if(num[2] > ans) ans = num[2];
            dfs(i);//printf("%d %d\n", ans, num[i]);
            if(num[i] > ans) ans = num[i];
        }
        printf("Case #%d: %d\n", cnt++, n-ans);
    }
    return 0;
}
