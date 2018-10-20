#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))
using namespace std;
FILE* fin;
FILE* fout;
int nTESTS;

int n;
int adj[1005][1005];
int best;
void read()
{
     fscanf(fin,"%d",&n);

     FOR(i,n)
     FOR(j,n)
     adj[i][j] = 0;
     int x,y;
     FOR(i,n-1)
     {
         fscanf(fin,"%d %d",&x,&y);
         x--;
         y--;
         adj[x][y] = 1;
         adj[y][x] = 1;
     }

}

int visit(int node,int prev)
{
    int b1 = -1;
    int b2 = -1;

    FOR(i,n)
    {

        if (adj[node][i])
        if (i!=prev)
        {
            int res = visit(i,node);
            if ((b1 < res))
            {
                b2 = b1;
                b1 = res;
            }
            else
                if ((b2 < res))
                    b2 = res;
        }

    }
    if (b2 == -1)
        return 1;
    else
        return b1+b2+1;
}

void solve()
{
    best = 0;
    FOR(i,n)
    best = max(visit(i,-1),best);
}

void write()
{
    fprintf(fout,"%d",n-best);
}



int main()
{
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    fscanf(fin,"%d",&nTESTS);

    FOR(crtTest,nTESTS)
    {
        read();
        solve();
        fprintf(fout,"Case #%d: ",crtTest+1);
        write();
        fprintf(fout,"\n");
    }
    fclose(fout);

    return 0;
}
