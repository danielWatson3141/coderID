#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int T; int N;
vector<int> v[2000];
bool visit[2000]; int mn;
int size[2000]; int fix[2000];

void DFS(int O, int id)
{
    visit[O] = true; size[O] = 1;

    for(int vi = 0, vn = v[O].size(); vi < vn; vi++)
        if( !visit[ v[O][vi] ] )
        {
            DFS( v[O][vi], 0); size[O] += size[ v[O][vi] ] ;
        }

    fix[O] = size[O]-1;

    int mx1 = 0, mx2 = 0;

    visit[O] = false;

    if( id == 1 && v[O].size() < 2 ) return;
    if( id == 0 && v[O].size() < 3 ) return;

    for(int vi = 0, vn = v[O].size(); vi < vn; vi++)
        if( !visit[ v[O][vi] ] )
        {
            int t = v[O][vi];
            int p = size[t]-fix[t];
            if( p > mx1 ) mx2 = mx1, mx1 = p;
            else if( p > mx2 ) mx2 = p;
        }

    fix[O] -= mx1+mx2;
}

int main()
{

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &T);

    for(int Ti = 0; Ti < T; Ti++)
    {
        scanf("%d", &N);

        for(int Ni = 1; Ni <= N; Ni++) v[Ni].clear();

        for(int Ni = 1; Ni < N; Ni++)
        {
            int a, b; scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        mn = N-1;

        for(int Ni = 1; Ni <= N; Ni++)
        {
            if( v[Ni].size() < 2 ) continue;
            memset(visit, false, sizeof(visit));
            DFS(Ni, 1);
            mn = min(mn, fix[Ni]);
        }

        printf("Case #%d: %d\n", Ti+1, mn);
    }
}
