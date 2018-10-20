#include <cstdio>
using namespace std;

typedef long long int ll;

ll e[2][256];

int bitc(ll v)
{
    int ret = 0;
    while(v)
    {
        v &= v - 1;
        ret++;
    }
    return ret;
}

int main()
{
    int TT;
    scanf("%d", &TT);


    for(int tt = 1; tt <= TT; tt++)
    {
        printf("Case #%d: ", tt);

        int N, L;
        scanf("%d%d", &N, &L);

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < N; j++)
            {
                char buf[128];
                scanf("%s", buf);
                ll v = 0;
                for(int k = 0; k < L; k++)
                    v = v * 2 + buf[k] - '0';
                e[i][j] = v;
            }
        
        int ans = -1;
        for(int i = 0; i < N; i++)
        {
            ll m = e[0][0] ^ e[1][i];

            bool check = true;
            for(int j = 0; j < N; j++)
            {
                bool f = false;
                for(int k = 0; k < N; k++)
                    if((e[0][j] ^ m) == e[1][k])
                    {
                        f = true;
                        break;
                    }
                if(!f)
                {
                    check = false;
                    break;
                }
            }

            if(check)
                if(ans == -1 || bitc(m) < ans)
                    ans = bitc(m);
        }

        if(ans == -1)
            puts("NOT POSSIBLE");
        else
            printf("%d\n", ans);
    }
    return 0;
}
