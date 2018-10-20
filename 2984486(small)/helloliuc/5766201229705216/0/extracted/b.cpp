#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const double eps = 1e-6;
const int maxint = -1u>>2;

int n;
vector<int> e[1100];
bool visit[1100];
//int man_height[1100];
int wan_nodes[1100];

bool cmp(const int &a, const int &b)
{
//    if(man_height[a] != man_height[b])
//    {
//        return man_height[a] > man_height[b];
//    }

    return wan_nodes[a] > wan_nodes[b];
}

void dfs(int root)
{
//    printf("dfs:%d \n", root);
    visit[root] = true;
    vector<int> child;

    for(int i=0;i<e[root].size();i++)
    {
        if(!visit[e[root][i]])
        {
            dfs(e[root][i]);
            child.push_back(e[root][i]);
        }
    }

//    printf("%d childsize\n", child.size());
    if(child.size() == 0 || child.size() == 1)
    {
        //man_height[root] = 1;
        wan_nodes[root] = 1;
        return ;
    }

    sort(child.begin(), child.end(), cmp);

    int a = child[0], b = child[1];
    wan_nodes[root] = wan_nodes[a] + wan_nodes[b] + 1;

//    int a = child[0], b = child[1];
//    if(man_height[a] == man_height[b])
//    {
//        man_height[root] = man_height[a] + 1;
//        wan_nodes[root] = wan_nodes[a] + (1<<man_height[b]) - 1 + 1;
//    }
//    else
//    {
//        man_height[root] = man_height[b] + 1;
//        wan_nodes[root] = (1 << (man_height[b] + 1)) -1 + wan_nodes[b] + 1;
//    }
}

int doit(int root)
{
    dfs(root);
    return n - wan_nodes[root];
}

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   e[i].clear();

        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
        int ans = maxint;
        for(int root=1;root<=n;root++)
        {
            memset(visit, false, sizeof(visit));
            //memset(man_height, 0 ,sizeof(man_height));
            memset(wan_nodes, 0, sizeof(wan_nodes));
            int ret = doit(root);
            if(ret < ans)   ans = ret;

//            for(int i=1;i<=n;i++)
//            {
//                printf("root:%d i:%d wan_nodes:%d\n", root, i, wan_nodes[i]);
//            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }


    return 0;
}
