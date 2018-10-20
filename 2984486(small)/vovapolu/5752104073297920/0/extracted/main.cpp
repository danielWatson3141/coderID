#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 1000;

const double valgood = 106.83669479118015000000;
//const double valbad = 121.82131899995417000000;

vector <int> perm1(int n)
{
    vector <int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i;
    for (int i = 0; i < n; i++)
    {
        int p = rand() % (n - i) + i;
        swap(ans[i], ans[p]);
    }
    return ans;
}


vector <int> perm2(int n)
{
    vector <int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i;
    for (int i = 0; i < n; i++)
    {
        int p = rand() % n;
        swap(ans[i], ans[p]);
    }
    return ans;
}

void gen()
{
    FILE *f = fopen("input.txt", "w");
    fprintf(f, "%d\n", N);
    for (int i = 0; i < N; i++)
    {
        vector <int> a;
        if (i < N / 2)
            a = perm1(1000);
        else
            a = perm2(1000);
        fprintf(f, "1000\n");
        for (int i = 0; i < 1000; i++)
            fprintf(f, "%d ", a[i]);
        fprintf(f, "\n");
    }
    fclose(f);
}

int main()
{
    //gen();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    double sum = 0;
    for (int q = 0; q < t; q++)
    {
        printf("Case #%d: ", q + 1);
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        vector <char> used(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int ccnt = 0;

        double vallen = 0;

        for (int i = 0; i < n; i++)
            if (!used[i])
            {
                int len = 0;
                int now = i;
                while (!used[now])
                {
                    len++;
                    used[now] = 1;
                    now = a[now];
                }
                ccnt++;
                vallen += len * len;
                //printf("%d ", len);
            }

        vallen = sqrt(vallen);

        double val = (double)vallen / ccnt;
        /*sum += val;
        printf("%.5lf\n", val);
        if (q == N / 2 - 1 || q == N - 1)
        {
            printf("%.20lf\n", sum / (N / 2));
            sum = 0;
        }*/
        if (fabs(val - valgood) > 70)
            printf("BAD\n");
        else
            printf("GOOD\n");

    }
    return 0;
}
