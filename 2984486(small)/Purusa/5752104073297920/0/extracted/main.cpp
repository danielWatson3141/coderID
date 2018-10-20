#include <bits/stdc++.h>

using namespace std;

int N, gc, bc;

void solve()
{
    scanf("%d", &N);
    int a;
    int prob=0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &a);
        if(a)
            prob+=N-(a-i+N-1)%N;
    }
    if(prob>=514000)
        bc++, printf(" BAD\n");
    else
        gc++, printf(" GOOD\n");
}

int main()
{
    //freopen("C.in", "r", stdin);
    freopen("C-small-attempt1.in", "r", stdin);

    //freopen("bad.in", "r", stdin);
    //freopen("good.in", "r", stdin);

    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d:", i);
        solve();
    }
    fprintf(stderr, "gc %d bc %d\n", gc, bc);
    return 0;
}
