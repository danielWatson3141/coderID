#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> OAO;
int T, N, L; int ext = 0; int crr = 0;

struct line
{
    char n[50];
}A[200], B[200];

void flip(int I)
{
    for(int Ni = 0; Ni < N; Ni++)
        A[Ni].n[I] = '1'-A[Ni].n[I]+'0';
}

bool fix[50];

bool cmp(line a, line b)
{
    for(int Oi = 0, On = OAO.size(); Oi < On; Oi++)
    {
        if( a.n[Oi] == '1' && b.n[Oi] == '0' ) return true;
        if( a.n[Oi] == '0' && b.n[Oi] == '1' ) return false;
    }

    return false;
}

int match(int I)
{
    int cnt1 = 0;

    for(int Ni = 0; Ni < N; Ni++)
    {
        if( A[Ni].n[I] == '1' ) cnt1++;
    }

    if( cnt1*2 == N ) crr++, fix[I] = true;

}

int main()
{

    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    scanf("%d", &T);

    for(int Ti = 0; Ti < T; Ti++)
    {
        ext = crr = 0;
        scanf("%d %d", &N, &L);

        for(int Ni = 0; Ni < N; Ni++)
            scanf("%s", A[Ni].n);

        for(int Ni = 0; Ni < N; Ni++)
            scanf("%s", B[Ni].n);

        printf("Case #%d: ", Ti+1);

        OAO.clear(); memset(fix, false, sizeof(fix));
        int cnt = 0;

        for(int Li = 0; Li < L; Li++)
        {
            match(Li);
        }

        for(int Li = 0; Li < L; Li++)
        {
            OAO.push_back(Li);
            sort(A, A+N, cmp);
            sort(B, B+N, cmp);

            for(int Ni = 0; Ni < N; Ni++)
                if( A[Ni].n[Li] != B[Ni].n[Li] ) goto half;

            continue;
            half:;
            if( fix[Li] ) cnt++;
            else ext++;
            flip(Li);
            sort(A, A+N, cmp);

            for(int Ni = 0; Ni < N; Ni++)
                if( A[Ni].n[Li] != B[Ni].n[Li] ){ puts("NOT POSSIBLE"); goto ed; }
        }

        printf("%d\n", min(ext+cnt, ext+crr-cnt));
        ed:;
    }
}
