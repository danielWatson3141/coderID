#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;
vector<vector<int> > G;

// int try_root(int root){
//     queue<int> q;
//     int x,y;
//     q.push(root);
//     vector<int> C(N+2);
//     vector<int> L(N+2);

//     C[0] = 1;
//     L[root] = 0;

//     int level;
//     int best = 0,t;
//     while(!q.empty()){
//         x = q.front();q.pop();

//         for(int i=G[x].size()-1;i>=0;i--){y=G[x][i];
//             if(y == x)continue;
//             level = L[x] + 1;

//             L[y] = level;
//             C[level]++;

//             if(level > 0){
//                 t = level-1;
//                 if(C[t] < (1 << t)){
//                     return t-1;
//                 }
//             }
//         }
//     }

//     if(C[level] < (1<<level)){
//         return level-1;
//     }else{
//         return level;
//     }
// }

int try_root(int x,int p){
    multiset<int> best;
    int y,tmp;
    for(int i=G[x].size()-1;i>=0;i--){
        y=G[x][i];
        if(y == p)continue;

        tmp = try_root(y,x);
        best.insert(tmp);
        
        if(best.size() == 3){
            best.erase(best.begin());
        }
        // printf("%d: %d = %d #%d\n",x,y,tmp,(int)best.size());
    }    
    // printf("%d >> %d\n",x,(int)best.size());

    if(best.size() == 0)return 1;
    if(best.size() == 1)return 1;
    if(best.size() == 2)return *best.begin() + *best.rbegin() + 1;
}

int PRE[20];

void solve(){
    scanf("%d",&N);

    G.clear();
    G.resize(N+1);
    int x,y;
    for(int i=1;i<N;i++){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = N-1,tmp,level;
    for(int i=1;i<=N;i++){
        tmp = try_root(i,-1);

        // printf("%d = %d\n",i,tmp);

        tmp = N - tmp;

        if(tmp < ans)
            ans = tmp;
    }
    printf("%d\n",ans);
}

int main(){
    PRE[0] = 1;
    for(int i=1;i<20;i++){
        PRE[i] = PRE[i-1] + (1 << i);
    }

    int NC;scanf("%d",&NC);
    for(int i=1;i<=NC;i++){
        printf("Case #%d: ",i);
        solve();
    }
}