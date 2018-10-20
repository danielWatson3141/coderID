#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<long long int> TVector;

void ReadVector(TVector* result, int n, int l)
{
    result->resize(n);
    for (int i = 0; i < n; ++i)
    {
        long long int num = 0;
        for (int j = 0; j < l; ++j)
        {
            char ch;
            scanf("%c", &ch);
            while ( ch != '0' && ch != '1' )
            {
                scanf("%c", &ch);
            }
            num = 2*num + ch - '0';
        }
        (*result)[i] = num;
    }
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; ++t)
    {
        int n, l;
        scanf("%d %d", &n, &l);
        TVector a;
        ReadVector(&a, n, l);
        TVector b;
        ReadVector(&b, n, l);
        sort(b.begin(), b.end());

        static const int MAX = 10000; 
        int result = MAX;
        for (int i = 0; i < n; ++i)
        {
            long long int hypo = a[0] ^ b[i];

            TVector aa(a.size());
            for (int j = 0; j < n; ++j)
            {
                aa[j] = a[j] ^ hypo;
            }
            sort(aa.begin(), aa.end());

            if (aa == b)
            {
                int bitcount = 0;
                while (hypo)
                {
                    if (hypo & 1)
                    {
                        ++bitcount;
                    }
                    hypo /= 2;
                }
                if (bitcount < result)
                {
                    result = bitcount;
                }
            }
        }

        printf("Case #%d: ", t + 1);
        if (result != MAX)
        {
            printf("%d", result);
        }
        else
        {
            printf("NOT POSSIBLE");
        }
        printf("\n");
    }

    return 0;
}