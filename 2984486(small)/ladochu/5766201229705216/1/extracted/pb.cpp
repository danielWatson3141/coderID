#include <cstdio>
#include <vector>
using std::vector;

int count(int parent, int self, vector<int> adj[]){
    int sum = 1;
    for(int i = 0;i < adj[self].size();++i){
        if(parent == adj[self][i]){
            continue;
        }
        sum += count(self, adj[self][i], adj);
    }
    return sum;
}

int cut(int parent, int self, vector<int> adj[]){
    int child_n = adj[self].size() - (parent ? 1 : 0);
    if(child_n < 2){
        return count(parent, self, adj) - 1;
    }
    int cost = 0;
    vector<int> keep;
    for(int i = 0;i < adj[self].size();++i){
        if(parent == adj[self][i]){
            continue;
        }
        int cut_cost = count(self, adj[self][i], adj);
        int keep_cost = cut(self, adj[self][i], adj);
        cost += cut_cost;
        keep.push_back(cut_cost - keep_cost);
        if(keep.size() > 2){
            for(int i = 0;i < keep.size();++i){
                for(int j = i + 1;j < keep.size();++j){
                    if(keep[i] < keep[j]){
                        int tmp = keep[i];
                        keep[i] = keep[j];
                        keep[j] = tmp;
                    }
                }
            }
            keep.resize(2);
        }
    }
    return cost - keep[0] - keep[1];
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1;t <= T;++t){
        int N;
        scanf("%d", &N);
        vector<int> adj[1001];
        for(int i = 1;i < N;++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int min = cut(0, 1, adj);
        for(int i = 2;i <= N;++i){
            int result = cut(0, i, adj);
            if(result < min){
                min = result;
            }
        }
        printf("Case #%d: %d\n", t, min);
    }
}
