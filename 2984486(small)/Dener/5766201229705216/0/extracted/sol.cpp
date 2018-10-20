#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;


vector< vector< int > > E;
vector< int > h;

void DFS(int x, int pred)
{
    h[x] = 0;
    int first_max = 0;
    int second_max = 0;
    int edge_count = 0;
    for (int i = 0 ; i < E[x].size(); i++) {
        if (E[x][i] != pred) {
            DFS(E[x][i], x);
            
            int to = E[x][i];
            if (h[to] >= first_max) {
                second_max = first_max;
                first_max = h[to];
            } else if (h[to] > second_max) {
                second_max = h[to];
            }
            edge_count++;
        }
    }
    
    if (edge_count < 2) {
        h[x] = 1;
    } else {
        h[x] = first_max + second_max + 1;
    }
};

void solve(int test_num)
{
    int n;
    scanf("%d", &n);
    E.clear();
    E.resize(n);
    int best_ans = 1<<30;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    
    for (int i = 0; i < n; i++) {
        h.assign(n, 0);
        DFS(i, -1);
        best_ans = min(best_ans, n - h[i]);
    }
    printf("Case #%d: %d\n", test_num + 1, best_ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
}