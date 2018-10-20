#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 1001

vector<int> edges[MAX];
int contChild[MAX];

int doCount(int n, int root = -1){
    int ans = 1;
    for (int i = 0; i < edges[n].size(); i++)
        if (edges[n][i] != root)
            ans += doCount(edges[n][i], n);
    contChild[n] = ans;
    return ans;
}

int solve(int n, int root = -1){
    vector<int> ans;
    for (int i = 0; i < edges[n].size(); i++)
        if (edges[n][i] != root){
            ans.push_back(contChild[edges[n][i]]-solve(edges[n][i], n));
        }
    sort(ans.begin(), ans.end());
    int saved = 1;
    if (ans.size() >= 2)
        saved += ans[ans.size()-1]+ans[ans.size()-2];
    return contChild[n]-saved;
}

int main(){
    int t, cases = 0;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            edges[i].clear();
        for (int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            doCount(i);
            ans = min(ans, solve(i));
        }
        cout << "Case #" << ++cases << ": " << ans << endl;
    }
    return 0;
}
