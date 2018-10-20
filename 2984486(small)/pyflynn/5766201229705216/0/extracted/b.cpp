#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct Edge {
    int u, v;
    int next;
} Edge;

int T;
int N;

int top[1001];
Edge edg[2010];
int edg_cnt;
int visited[1010];
int child[1010];
int gain[1010];

void add_edg(int u, int v)
{
    edg[edg_cnt].u = u;
    edg[edg_cnt].v = v;
    edg[edg_cnt].next = top[u];
    top[u] = edg_cnt;
    edg_cnt += 1;
}

void find(int node)
{
    //printf("visited %d\n", node+1);

    visited[node] = 1;
    child[node] = 1;
    gain[node] = 0;

    int is_leaf = 1;
    int i = top[node];
    int direct_child = 0;
    int max_a = -1, max_b = -1, cut_sum = 0;
    int pa, pb;

    while(i != -1) {
        //edg[i]
        //
        int ch = edg[i].v;
        if (visited[ch] == 1)
        {
            i = edg[i].next;
            continue;
        }
        //printf("    child %d (%d)\n", ch+1, visited[ch]);
        find(ch);
        direct_child += 1;
        child[node] += child[ch];

        int g = gain[ch];

        if (max_a == -1)
        {
            max_a = g;
            pa = ch;
        }
        else if (max_b == -1)
        {
            max_b = g;
            pb = ch;
        }
        else if (g > max_a || g > max_b)
        {
            int mi = min(max_a, min(max_b, g));
            int mx = max(max_a, max(max_b, g));
            int keep = g + max_a + max_b - mi - mx;
            max_a = mx;
            max_b = keep;
        }

        i = edg[i].next;
    }

    if (direct_child <= 1)
    {
        gain[node] = 1;
    }
    else {
        gain[node] = max_a + max_b + 1;
    }
}

int main()
{
    int i, j, k;

    scanf("%d", &T);
    for (i = 0; i < T; ++i)
    {
        scanf("%d", &N);

        memset(top, 0xff, sizeof(top));

        edg_cnt = 0;
        for (j = 0; j < N - 1; ++j)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            u -= 1;
            v -= 1;
            add_edg(u, v);
            add_edg(v, u);
        }

        int ans = -1;
        for (j = 0; j < N; ++j)
        {
            memset(visited, 0, sizeof(visited));
            //printf("try %d\n", j+1);
            find(j);
            //printf("get gain %d\n", gain[j]);
            if (ans == -1 || N - gain[j] < ans)
            {
                ans = N - gain[j];
            }
            //if (ans == 0)
            //{
                //break;
            //}

            //printf("child value\n");
            //for (k = 0; k < N; ++k)
            //{
                //printf("%d %d\n", k+1, child[k]);
            //}

            //printf("gain value\n");
            //for (k = 0; k < N; ++k)
            //{
                //printf("%d %d\n", k+1, gain[k]);
            //}
        }
        printf("Case #%d: %d\n", i+1, ans);
    }

    return 0;
}
