#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MaxN = 1100;

struct Edge {
    int to, next;
} E[MaxN*2];

int head[MaxN], eptr = 0;

void AddEdge(int u, int v)
{
    E[eptr].next = head[u];
    E[eptr].to = v;
    head[u] = eptr++;
}

int N;
int f[MaxN][2]; // 0-save, 1-del

int idx[MaxN];
//int children[MaxN];
int keys[MaxN];

bool chcmp(const int ch1, const int ch2)
{
    return keys[ch1] < keys[ch2];
}

void calc(int u, int fa)
{
    for(int e=head[u]; e!=-1; e=E[e].next)
    {
        int v = E[e].to;
        if(v != fa)
            calc(v, u);
    }
    
    // for 2 child
    f[u][0] = N;
    int nchild = 0;
    int sumdel = 0;
    for(int e=head[u]; e!=-1; e=E[e].next)
    {
        int v = E[e].to;
        if(v != fa)
        {
            sumdel += f[v][1];
            
            //children[nchild] = v;
            keys[nchild] = f[v][0] - f[v][1];
            idx[nchild] = nchild;
            nchild++;
        }
    }
    
    if(nchild >= 2)
    {
        sort(idx, idx+nchild, chcmp);
        f[u][0] = keys[idx[0]] + keys[idx[1]] + sumdel;
    }
    f[u][0] = min(f[u][0], sumdel);
    
    // for del
    f[u][1] = 1;
    for(int e=head[u]; e!=-1; e=E[e].next)
    {
        int v = E[e].to;
        if(v != fa)
            f[u][1] += f[v][1];
    }
    
    //printf("f[%d][0] = %d\n", u, f[u][0]);
    //printf("f[%d][1] = %d\n", u, f[u][1]);
}

int solve(int root)
{
    //printf("-- root = %d --\n", root);
    calc(root, -1);
    return min(f[root][0], f[root][1]);
}

int main()
{
    int T;
    cin >> T;
    
    for(int c=0; c<T; c++)
    {
        eptr = 0;
        memset(head, -1, sizeof(head));
        
        cin >> N;
        for(int i=1; i<N; i++)
        {
            int u, v;
            cin >> u >> v;
            AddEdge(u, v);
            AddEdge(v, u);
        }
        
        int result = N;
        for(int r=1; r<=N; r++)
        {
            int del = solve(r);
            if(del < result)
                result = del;
        }
        
        printf("Case #%d: %d\n", c+1, result);
    }
    
    return 0;
}
