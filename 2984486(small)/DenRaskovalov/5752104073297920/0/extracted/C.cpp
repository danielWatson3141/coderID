#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <vector>

using namespace std;

typedef vector<double> TDoubleVector;
typedef vector<TDoubleVector> TDoubleVectorVector;

int main()
{
    static const int N = 1000;
    /*
    TDoubleVectorVector p(N);
    for (int i = 0; i < N; ++i)
    {
        TDoubleVector v(N);
        v[i] = 1.0;
        TDoubleVector temp(N);
        for (int turn = 0; turn < N; ++turn)
        {
            for (int i = 0; i < N; ++i)
            {
                temp[i] = 0.0;
            }
            for (int dice = 0; dice < N; ++dice)
            {
                temp[turn] += v[dice]/N;
                if (dice != turn)
                {
                    temp[dice] += v[turn]/N;
                    temp[dice] += v[dice]*double(N - 1)/N;
                }
            }
            v.swap(temp);
        }
        p[i] = v;
        // printf("%d\n", i);
        for (int i = 0; i < N; ++i)
        {
            printf("%.3lf ", v[i]);
        }
        printf("\n");
    }
    */

    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    
    int t;
    scanf("%d\n", &t);
    for (int iT = 0; iT < t; ++iT)
    {
        int n;
        scanf("%d", &n);
        int same = 0;
        for (int i = 0; i < N; ++i)
        {
            int d;
            scanf("%d", &d);
            if (i + 1 == d || i + 2 == d)
            {
                ++same;
            }
        }
        printf("Case #%d: ", iT + 1);
        if (same > 3)
        {
            printf("BAD");
        }
        else
        {
            printf("GOOD");
        }
        printf("\n");
    }

    return 0;
}