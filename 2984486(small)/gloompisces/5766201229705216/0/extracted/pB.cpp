#include <stdio.h>
#include <stdlib.h>

int comp(const void *x, const void *y)
{
    return (*(int*)y) - (*(int*)x);
}

int links[1005][1005];

int check (int root, int now)
{
    int childs = 0;
    int lists[1005];
    for (int i = 1; i <= links[now][0]; i++)
    {
        if (links[now][i] != root)
        {
            lists[childs] = check(now, links[now][i]);
            childs++;
        }
    }
    
    if (childs == 0 || childs == 1) return 1;
    else
    {
        qsort(lists, childs, sizeof(int), comp);
        return lists[0] + lists[1] + 1;
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    
    int N, a, b;
    int ans, now;
    
    int cases;
    scanf("%d", &cases);
    
    for(int index = 1; index <= cases; index++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            links[i][0] = 0;
        }
        for (int i = 1; i < N; i++)
        {
            scanf("%d %d", &a, &b);
            links[a][0]++;
            links[a][links[a][0]] = b;
            links[b][0]++;
            links[b][links[b][0]] = a;
        }
        
        ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int now = check(-1, i);
            if (ans < now)
            {
                ans = now;
            }
        }
        
        printf("Case #%d: %d\n", index, N - ans);
    }
    
    return 0;
}
