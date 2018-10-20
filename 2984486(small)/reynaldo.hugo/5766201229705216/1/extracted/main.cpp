#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1002;
int child[MAX], memo[MAX][2] , N;
vector<int>tree[MAX];
int dfs(int x, int dad){
    int S = 0;
    for(int i = 0; i < (int)tree[x].size(); i++ ){
        int y = tree[x][i];
        if(y == dad)continue;
        S += dfs(y, x);
    }
    return child[x] = 1 + S;
}
int take(int x, int dad, int flag){
    if(memo[x][flag] != -1)return memo[x][flag];
    if(!flag)return 0;

    int ans = 1, l = tree[x].size();

    for(int i = 0; i < l ; i++){
        for(int j = 0; j < l; j++){
            int y = tree[x][i], z = tree[x][j];
            if(y==dad || z== dad || z==y)continue;
            ans = max(ans, 1 + take(y,x,1) + take(z,x,1) );
        }
    }
    return memo[x][flag] = ans;
}
int main(){
    int T, x, y;
    scanf("%d", &T);
    for(int t = 1; t<= T; t++){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
                tree[i].clear();
        }
        for(int i = 0; i < N - 1; i++){
            scanf("%d %d", &x, &y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        int ans = 0;
        for(int root = 1; root <= N; root++){
            memset(child, 0, sizeof(child));
            int ret = dfs(root, -1);
            //printf("%d -> ", root);
            //for(int i=1;i<=N;i++)printf("%d(%d) ", i, child[i]);puts("");
            memset(memo, -1, sizeof(memo) );
            ans = max(ans, max(take(root,-1,0), take(root,-1,1))  );
            //printf("%d %d %d\n\n",ans, take(root,-1,0), take(root,-1,1));
        }
        printf("Case #%d: %d\n", t, N - ans);
    }
    return 0;
}
