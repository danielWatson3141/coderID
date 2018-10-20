#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#define FOR(i,k,n) for(int i=k; i<n; i++)
#define EPS 1.0e-6
#define INF 10000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

char a[155][45], b[155][45];
int transf[45];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int T;
    int n, l, flip, minimo;
    bool possible;
    string s;

    scanf("%d", &T);
    for(int ncase=1; ncase<=T; ncase++)
    {
        scanf("%d%d", &n, &l);

        minimo = 100;
        map<string, int> mapa;
        FOR(i,0,n) scanf("%s", a[i]);
        FOR(i,0,n) {scanf("%s", b[i]); s=b[i]; mapa[s]=1;}

        FOR(i,0,n)
        {
            flip = 0;
            FOR(j,0,l)
            {
                if (a[0][j] == b[i][j]) transf[j] = 0;
                else {transf[j] = 1; flip++;}
            }

            possible = true;
            FOR(k,1,n)
            {
                char aux[45]; strcpy(aux, a[k]);
                FOR(j,0,l) if (transf[j])
                {
                    if (aux[j] == '0') aux[j] = '1';
                    else aux[j] = '0';
                }
                s = aux;
                if (mapa[s] == 0) {possible=false; break;}
            }

            if (possible) minimo = min(minimo, flip);
        }

        if (minimo == 100) printf("Case #%d: NOT POSSIBLE\n", ncase);
        else printf("Case #%d: %d\n", ncase, minimo);
    }

    return 0;
}
