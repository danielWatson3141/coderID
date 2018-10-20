/* require C++11 */
#define _CRT_SECURE_NO_WARNINGS //for MS compiler
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1001;
const int MAXE = MAXN * 8;

struct edge
{
    int u, v;
    int next;
} edges[MAXE];

int e_cnt = 0;
int first[MAXN];
int value[MAXN];
int n;
int answer = INT_MAX;
int root;
void enter(int u , int v)
{
    ++e_cnt;
	edge &e = edges[e_cnt];
	e.u = u;
	e.v = v;
	e.next = first[u];
    first[u] = e_cnt;
}

int dfs(int p , int parent)
{
    vector<int> children;
    for (int ed = first[p] ; ed ; ed = edges[ed].next)
    {
        edge &e = edges[ed];
        if (e.v != parent)
            children.push_back(e.v);
    }
    if (children.empty())
        return 0;
    else
    {
        vector<int> costs;
        for (vector<int>::iterator it = children.begin() ; it != children.end() ; ++it)
            costs.push_back(dfs( *it , p) );
        sort(costs.begin() , costs.end());
        if (children.size() == 2)
            return costs[0] + costs[1];
        else if (children.size() == 1)
            return 1 + costs[0];
        else
        {
            int return_val = 0;
            for (size_t i = 0 ; i < costs.size() - 2 ; ++i)
                return_val += costs[i] + 1;
            return return_val;
        }
    }
}
void process(int case_num)
{
    e_cnt = 0;
    answer = INT_MAX;
    cin >> n;
    memset(first, 0 , sizeof(first));
    for (int i = 1 ; i < n ; ++i)
    {
        int u ,v;
        cin >> u >> v;
        enter(u, v);
        enter(v, u);
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        root = i;
        answer = min(answer , dfs(root, 0) );
    }
    cout << "Case #" << case_num << ": " << answer << endl;
}

int main()
{
//#define FILEIO
#ifdef FILEIO
    freopen("input.txt","r" , stdin);
    //freopen("output.txt","w",stdout);
#endif // FILEIO
    int t;
    cin >> t;
    for (int case_num = 1 ; case_num <= t ; ++case_num)
        process(case_num);
    return 0;
}
