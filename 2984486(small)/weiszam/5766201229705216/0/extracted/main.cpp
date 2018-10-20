#include <iostream>
#include <cstdio>
using namespace std;

int n;
int el[1005],mut[1005],pont[1005];
bool be[1005];
int d1[1005],d2[1005];

int mely(int akt)
{
    be[akt] = true;
    int re = 1;

    int mm = pont[akt];
    while (mm>0)
    {
        if (!be[el[mm]]) re+=mely(el[mm]);
        mm = mut[mm];
    }

    be[akt] = false;
    return re;
}

int mely2(int akt)
{
    be[akt] = true;
    int re = n+1;

    int sor[1005];
    int sor2[1005];
    int sordb = 0;
    int mm = pont[akt];
    while (mm>0)
    {
        if (!be[el[mm]])
        {
            sor[++sordb] = el[mm];
            if (d1[el[mm]] == -1) d1[el[mm]] = mely(el[mm]);
            if (d2[el[mm]] == -1) d2[el[mm]] = mely2(el[mm]);
            sor2[sordb] = d1[el[mm]]-d2[el[mm]];
        }
        mm = mut[mm];
    }
    be[akt] = false;

    if (sordb == 0) return 0;
    if (sordb == 1) return d1[sor[1]];
    if (sordb == 2) return d2[sor[1]]+d2[sor[2]];

    int egyik = 1;
    int masik = 2;

    if (sor2[egyik]<sor2[masik]) { egyik = 2; masik = 1; }

    re = d1[sor[1]]+d1[sor[2]];
    for (int i = 3; i<=sordb; i++)
    {
        if (sor2[i]>=sor2[egyik])
        {
            masik = egyik;
            egyik = i;
        }
        else if (sor2[i] >= sor2[masik]) masik = i;
        re+=d1[sor[i]];
    }

    re-=sor2[egyik];
    re-=sor2[masik];


    return re;
}


int main()
{
    FILE *out = fopen("ki.txt", "w");
    int hany; scanf("%d", &hany);

    for (int i = 1; i<=hany; i++)
    {
        scanf("%d", &n);
        int re = n;
        for (int j = 1; j<=n; j++)
        {
            be[j] = false;
            pont[j] = 0;
            d1[j] = -1;
            d2[j] = -1;
        }
        for (int j = 1; j<=n-1; j++)
        {
            int b1,b2; scanf("%d%d", &b1, &b2);
            el[2*j-1] = b2;
            mut[2*j-1] = pont[b1]; pont[b1] = 2*j-1;
            el[2*j] = b1;
            mut[2*j] = pont[b2]; pont[b2] = 2*j;
        }


        //printf("%d\n", mely2(2));
        //printf("%d\n", n);

        //for (int j = 1; j<=n; j++)
        {
            //printf("%d. %d %d\n", j, d1[j], d2[j]);
        }

        for (int j = 1; j<=n; j++)
        {
            for (int l = 1; l<=n; l++)
            {
                be[l] = false;
                d1[l] = -1;
                d2[l] = -1;
            }
            int x = mely2(j);
            //printf("%d.: %d\n", j, x);
            re = min(re, x);
        }
        fprintf(out, "Case #%d: %d\n", i, re);
    }


    return 0;
}
