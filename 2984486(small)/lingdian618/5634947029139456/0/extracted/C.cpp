#include <stdio.h>
#include <string.h>
#include <algorithm>
const int NN = 111111;
const int MM = 222222;
const int oo = 0x3f3f3f3f;
struct Edge{
    int u, v, r;
    Edge(){}
    Edge(int u,int v,int r):u(u),v(v),r(r){}
}edge[MM];
int node, e, S, T;
int first[NN], next[MM];
int h[NN], num[NN], cur[NN], pre[NN];
int q[NN];
void bfs()
{
    int a=0, b=0;
    memset(h, -1, sizeof(h));
    memset(num, 0, sizeof(num));
    h[T] = 0, num[0]++;
    q[b++] = T;
    while(a^b)
    {
        int u = q[a++];
        for(int i=first[u]; -1^i; i=next[i])
        {
            int v = edge[i].v;
            if(-1!=h[v])  continue;
            h[v] = h[u]+1, num[h[v]]++;
            q[b++] = v;
        }
    }
}
void init(int n)
{
    node = n;
    e = 0;
    S = 0;
    T = node-1;
    memset(first, -1, sizeof(first));
    memset(h, 0, sizeof(h));
    memset(num, 0, sizeof(num));
    num[0] = node;
    pre[S] = -1;
}
void add(int u, int v, int r)
{
    edge[e] = Edge(u,v,r);
    next[e] = first[u];
    first[u] = e++;
}
int go(int u)
{
    for(int i=cur[u]; -1^i; i=next[i])
    {
        int v = edge[i].v;
        if(edge[i].r>0 && h[u]==h[v]+1)
        {
            pre[v] = cur[u] = i;
            return v;
        }
    }
    return node;
}
int augment()
{
    int r = oo;
    for(int i=pre[T]; -1^i; i=pre[edge[i].u])
    {
        r = std::min(r, edge[i].r);
    }
    for(int i=pre[T]; -1^i; i=pre[edge[i].u])
    {
        edge[i].r -= r;
        edge[i^1].r += r;
    }
    return r;
}
int relabel(int u)
{
    int t = h[u];
    h[u] = node;
    cur[u] = first[u];
    for(int i=first[u]; -1^i; i=next[i])
    {
        int v = edge[i].v;
        if(edge[i].r>0) h[u] = std::min(h[u], h[v]+1);
    }
    num[h[u]]++;
    return --num[t];
}
int sap()
{
    int flow=0, u=S, v;
    while(h[S]<node)
    {
        while(u^T)
        {
            v = go(u);
            if(v>=node) break;
            u = v;
        }
        if(u==T)
        {
            flow += augment();
            u = S;
        }
        else
        {
            if(0==relabel(u))   break;
            if(u^S) u = edge[pre[u]].u;
        }
    }
    return flow;
}

const int N = 222;
const int L = 44;
char s1[N][L];
char s2[N][L];
int c1[L], c2[L];
int r[L];
int n;

bool solve(char sa[N][L], char sb[N][L])
{
    init(2*n+2);
    for(int i=1; i<=n; i++)
    {
        add(S, i, 1), add(i, S, 0);
    }
    for(int i=n+1; i<=2*n; i++)
    {
        add(i, T, 1), add(T, i, 0);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(0==strcmp(sa[i], sb[j]))
            {
                add(i+1, j+1+n, oo), add(j+1+n, i+1, oo);
            }
        }
    }
//    bfs();
    return (n==sap());
}
int code[L], m;
void decode(int s)
{
    for(int i=0; i<m; i++)
    {
        code[i] = s&1;
        s >>= 1;
    }
}
char s3[N][L];
void gets3()
{
    for(int i=0; i<n; i++)
    {
        memcpy(s3[i], s1[i], sizeof(s1[0]));
    }
}
int main()
{
//    freopen("A-small-attempt2.in", "r", stdin);
//    freopen("A.out", "w", stdout);

    int t, kase=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++)
        {
            scanf("%s", s1[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%s", s2[i]);
        }
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                c1[j] += s1[i][j]=='1';
                c2[j] += s2[i][j]=='1';
            }
        }
        memset(r, 0, sizeof(r));
        int yes = 1;
        int cnt = 0;
        for(int j=0; j<m; j++)
        {
            if(c1[j]!=c2[j] && c1[j]+c2[j]!=n)
            {
                yes = 0;
                break;
            }
        }
        printf("Case #%d: ", ++kase);
        if(yes==0)
        {
            printf("NOT POSSIBLE\n");
            continue;
        }
        int ans = oo;
        for(int i=0; i<(1<<m); i++)
        {
            decode(i);
            gets3();
            int t = 0;
            for(int j=0; j<m; j++)
            {
                if(code[j]==1)
                {
                    for(int i=0; i<n; i++)
                    {
                        s3[i][j] = '1'+'0'-s3[i][j];
                    }
                    t++;
                }
            }
            if(solve(s3, s2)==1)
            {
                ans = std::min(ans, t);
            }
        }
        if(ans<oo)  printf("%d\n", ans);
        else    printf("NOT POSSIBLE\n");
    }
    return 0;
}
