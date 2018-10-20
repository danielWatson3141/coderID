#include <cstdio>
#include <algorithm>
using namespace std;

unsigned long long get()
{
    char buf[200];
    scanf(" %s", buf);
    unsigned long long res=0;
    for(int i=0; buf[i]; i++)
        res=(res<<1)+buf[i]-'0';
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int N, L;
        scanf("%d%d", &N, &L);
        unsigned long long M[150], F[150];
        for(int i=0; i<N; i++)
        {
            M[i] = get();
        }
        for(int i=0; i<N; i++)
        {
            F[i] = get();
        }
        sort(F, F+N);
        int res = 999;
        for(int i=0; i<N; i++)
        {
            unsigned long long diff = M[0] ^ F[i];
            int lres = __builtin_popcountll(diff);
            if (lres >= res)
                continue;
            unsigned long long MM[150];
            for(int j=0; j<N; j++)
                MM[j]=M[j]^diff;
            sort(MM, MM+N);
            bool good=true;
            for(int j=0; j<N; j++)
                if(MM[j]!=F[j])
                    good=false;
            if(good)
                res=lres;
        }
        if(res==999)
            printf("Case #%d: NOT POSSIBLE\n", t);
        else
            printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
