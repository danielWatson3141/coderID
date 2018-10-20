#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

#define MULTIPLE "Bad magician!"
#define NOANS "Volunteer cheated!"

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;
const double eps = 1e-8;

int sgn(double x) {
    return fabs(x) < eps ? 0:x < -eps ? -1:1;
}

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        vector <vector<int> > g;
        int n;
        cin >> n;
        g.resize(n);
        int ans = n;
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].PB(b);
            g[b].PB(a);
        }
        for(int i = 0; i < (1 << n); i++) {
            vector<bool> deleted(n, 0);
            int temp = 0;
            for(int j = 0; j < n; j++) {
                if((1 << j) & i) {
                    deleted[j] = true;
                    temp ++;
                }
            }
            bool get = true;
            for(int j = 0; j < n; j++) {
                vector<bool>vis(n, 0);
                if(!deleted[j]) {
                    queue<int> Q;
                    Q.push(j);
                    vis[j] = true;
                    while(!Q.empty()) {
                        int cur = Q.front();
                        //cout << cur;
                        vis[cur] = true;
                        Q.pop();
                        int coutn = 0;
                        for(int k = 0; k < g[cur].size(); k++) {
                            if(!deleted[g[cur][k]] && !vis[g[cur][k]]) {
                                Q.push(g[cur][k]);
                                coutn ++;
                            }
                        }
                        if(coutn!=2 && coutn != 0) {
                            get = false;
                            break;
                        }
                    }
                }
                for(int k = 0; k < n; k++) {
                    if(!vis[k] && !deleted[k]) {
                        get = false;
                    }
                }
                //cout << " : " <<  get << " " << temp <<  endl;
                if(get) {
                    ans = min(ans, temp);
                }
                get = true;
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }
}
