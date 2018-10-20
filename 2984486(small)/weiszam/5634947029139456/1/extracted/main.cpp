#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

struct elem
{
    int x[45];
    bool operator < (const elem &p) const
    {
        int h = 1;
        while (x[h] == p.x[h]) h++;
        return x[h]>p.x[h];
    }
};


int hany;
int n;
int l;
elem t[155];
elem z[155];

int elemki(elem x)
{
    for (int i = 1; i<=l; i++) printf("%d", x.x[i]); printf("\n");
}

elem ad(elem a, elem b)
{
    elem re;
    for (int i = 1; i<=l; i++)
    {
        re.x[i] = (a.x[i]+b.x[i]) % 2;
    }
    return re;
}

elem kivon(elem a, elem b)
{
    elem re;
    for (int i = 1; i<=l; i++)
    {
        re.x[i] = 0;
        if (a.x[i] != b.x[i]) re.x[i] = 1;
    }
    return re;
}

bool van(set<elem> s, elem x)
{
    set<elem>::iterator it = s.lower_bound(x);
    if (it == s.end()) return false;
    elem x2 = *it;
    bool re = true;
    for (int i = 1; i<=l; i++)
    {
        if (x.x[i] != x2.x[i]) re = false;
    }
    return re;
}

int szamol(elem x)
{
    int h = 0;
    for (int i = 1; i<=l; i++) if (x.x[i] == 1) h++;
    return h;
}

int main()
{
    FILE *out = fopen("ki.txt", "w");
    scanf("%d\n", &hany);
    for (int dik = 1; dik <= hany; dik++)
    {
        scanf("%d %d\n", &n, &l);
        set<elem> s;
        for (int i = 1; i<=n; i++)
        {
            elem uj;
            for (int j = 1; j<=l; j++)
            {
                char c; scanf("%c", &c);
                if (c == '1') uj.x[j] = 1; else uj.x[j] = 0;
            }
            if (i < n) scanf(" "); else scanf("\n");
            z[i] = uj;
        }
        for (int i = 1; i<=n; i++)
        {
            elem uj;
            for (int j = 1; j<=l; j++)
            {
                char c; scanf("%c", &c);
                if (c == '1') uj.x[j] = 1; else uj.x[j] = 0;
            }
            if (i < n) scanf(" "); else scanf("\n");
            t[i] = uj;
            s.insert(uj);
        }

        //if (van(s, z[2])) printf("van\n"); else printf("nincs\n");
        //elemki(kivon(z[1], t[1]));

        int re = l+1;

        for (int i = 1; i<=n; i++)
        {
            elem d = kivon(z[i], t[1]);
            int sz = szamol(d);
            //printf("%d. %d\n", i, sz);
            if (sz < re)
            {
                bool jo = true;
                int j = 1;
                while (j <= n && jo)
                {
                    elem adott = ad(z[j], d);
                    //printf("      ell "); elemki(adott);
                    if (!van(s, adott)) jo = false;
                    j++;
                }
                if (jo) re = sz;
                //if (jo) printf("jo\n");
            }
        }

        if (re == l+1)
        {
            printf("Case #%d: NOT POSSIBLE\n", dik);
            fprintf(out, "Case #%d: NOT POSSIBLE\n", dik);
        }
        else
        {
            printf("Case #%d: %d\n", dik, re);
            fprintf(out, "Case #%d: %d\n", dik, re);
        }

    }
    return 0;
}
