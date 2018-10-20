// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 1005;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int N;
VI edges[M];

int min_cache[M];
int tree_count_cache[M];

int get_tree_count(int node, int prev) {
    int &ans = tree_count_cache[node];

    if(ans != -1) return ans;

    ans = 1;
    for(int i=0;i<SZ(edges[node]);++i) {
        int node_i = edges[node][i];

        if(node_i != prev) ans += get_tree_count(edges[node][i], node);
    }
    return ans;
}

int get_min(int node, int prev) {
    int &ans = min_cache[node];
    if(ans != -1) return ans;

    int n_count = edges[node].size();
    if(prev != -1) --n_count;

    int zero_child_cost = 0;
    for(int i=0;i<SZ(edges[node]);++i) {
        int node_i = edges[node][i];

        if(node_i != prev) zero_child_cost += get_tree_count(node_i, node);
    }

    int two_child_cost = INF;
    if(n_count >= 2) {

        for(int i=0;i<SZ(edges[node]);++i) {
            for(int j=i+1;j<SZ(edges[node]);++j) {
                int node_i = edges[node][i];
                int node_j = edges[node][j];

                if(node_i == prev || node_j == prev) continue;
                int curr_cost = get_min(node_i, node) + get_min(node_j, node);

                for(int k = 0; k<SZ(edges[node]);++k) {
                    int node_k = edges[node][k];
                    if(node_k != node_i && node_k != node_j && node_k != prev) curr_cost += get_tree_count(node_k, node);
                }
               
                two_child_cost = min(two_child_cost, curr_cost);
            }
        }
    }

    ans = min(zero_child_cost, two_child_cost);
    return ans;
}


int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        scanf("%d", &N);
        for(int i=1;i<=N;++i) edges[i].clear();

        for(int i=0;i<N-1;++i) {
            int a,b;
            scanf("%d %d",&a,&b);
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int ans = INF;
        for(int i=1;i<=N;++i) {
            SET(tree_count_cache, -1);
            SET(min_cache, -1);
            ans = min(ans,get_min(i, -1));
        }

        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

