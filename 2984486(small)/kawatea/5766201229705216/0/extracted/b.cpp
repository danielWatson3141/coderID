#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000];
vector <int> v[1000];

int dfs(int x, int y)
{
    int i;
    
    a[x] = 1;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        a[x] += dfs(v[x][i], x);
    }
    
    return a[x];
}

int dfs2(int x, int y)
{
    int sum = 0, i;
    vector <int> w;
    
    for (i = 0; i < v[x].size(); i++) {
        int p;
        
        if (v[x][i] == y) continue;
        
        p = dfs2(v[x][i], x);
        
        sum += p;
        w.push_back(a[v[x][i]] - p);
    }
    
    sort(w.begin(), w.end());
    
    if (w.size() == 0) {
        return 0;
    } else if (w.size() == 1) {
        return a[x] - 1;
    } else {
        for (i = 0; i + 2 < w.size(); i++) sum += w[i];
        
        return sum;
    }
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 1e9, j;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) v[j].clear();
        
        for (j = 0; j < n - 1; j++) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            v[x - 1].push_back(y - 1);
            v[y - 1].push_back(x - 1);
        }
        
        for (j = 0; j < n; j++) {
            dfs(j, -1);
            
            ans = min(ans, dfs2(j, -1));
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
