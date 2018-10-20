#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define MAXN 1111
#define INF 1111111
#define pb push_back

using namespace std;

stack<int> s;
queue<int> q;

int f[MAXN], nChild[MAXN];
int tf[MAXN];
bool trace[MAXN];
int h[MAXN];

vector<int> a[MAXN];

void bfs(int root){
    q.push(root);
    trace[root] = true;
    s.push(root);
    h[root] = 0;

    while (!q.empty()){
        int u = q.front();
        //cout << u << endl;
        q.pop();

        for (int i = 0; i < a[u].size(); i++){
            int v = a[u][i];

           // cout << v << endl;
            if (trace[v]) continue;

            trace[v] = true;
            q.push(v);
            s.push(v);
            h[v] = h[u] + 1;
        }
    }
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    for (int tt = 1; tt <= t; tt++){
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) a[i].clear();
        int res = INF;
        for (int i = 1; i <= n - 1; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            a[u].pb(v);
            a[v].pb(u);
        }

        for (int root = 1; root <= n; root++){
            //cout << "Select root = " << root << endl;
            for (int i = 1; i <= n; i++){
                trace[i] = false;
                nChild[i] = 0;
                f[i] = INF;
            }

            bfs(root);

            //cout << "Stack size == " << s.size() << endl;
            while (!s.empty()){
                int u = s.top();
                //cout << " Node " << u << endl;
                s.pop();

                if (h[u] != 0 && a[u].size() == 1){
                    f[u] = 0;
                    nChild[u] = 1;
                    continue;
                }

                int sumChild = 0;
                int nn = 0;
                for (int i = 0; i < a[u].size(); i++){
                    int v = a[u][i];
                    if (h[v] < h[u]) continue;

                    nn++;
                    tf[nn] = f[v] - nChild[v];
                    sumChild = sumChild + nChild[v];
                }
                nChild[u] = sumChild + 1;
                //cout << "  nChild = " << nChild[u] << endl;

                sort(tf + 1, tf + nn + 1);

                if (nn == 1){
                    f[u] = sumChild;
                    continue;
                }

                f[u] = sumChild + tf[1] + tf[2];
            }

            res = min(res, f[root]);
        }

        cout << "Case #" << tt << ": " << res << endl;
    }

    return 0;
}
