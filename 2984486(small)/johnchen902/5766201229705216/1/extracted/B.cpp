#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

constexpr unsigned maxn = 1000;

vector<unsigned> adjlist[maxn];

pair<unsigned, unsigned> dfs(unsigned u, unsigned v){
    vector<pair<unsigned, unsigned>> ve;
    for(unsigned i = 0; i < adjlist[u].size(); i++)
        if(adjlist[u][i] != v)
            ve.push_back(dfs(adjlist[u][i], u));
    if(ve.size() == 0)
        return {1, 0};
    if(ve.size() == 1)
        return {1, ve[0].first + ve[0].second};
    if(ve.size() == 2)
        return {1 + ve[0].first + ve[1].first, ve[0].second + ve[1].second};
    unsigned maxi = 0, sub = 0, sum1 = 0, sum2 = 0;
    for(unsigned i = 0; i < ve.size(); i++){
        sum1 += ve[i].first;
        sum2 += ve[i].second;
        if(ve[i].first > sub){
            sub = ve[i].first;
            if(sub > maxi)
                swap(sub, maxi);
        }
    }
    return {maxi + sub + 1, sum1 + sum2 - maxi - sub};
}

int solve(){
    unsigned n;
    scanf("%u", &n);
    for(unsigned i = 0; i < n; i++)
        adjlist[i].clear();
    for(unsigned i = 0; i < n - 1; i++){
        unsigned x, y;
        scanf("%u %u", &x, &y);
        x--, y--;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    unsigned mini = maxn;
    for(unsigned i = 0; i < n; i++){
//        printf("%u %u %u\n", i, dfs(i, maxn + 567).first, dfs(i, maxn + 567).second);
        mini = min(mini, dfs(i, maxn + 567).second);
    }
    return mini;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case #%d: %d\n", i, solve());
    }
}
