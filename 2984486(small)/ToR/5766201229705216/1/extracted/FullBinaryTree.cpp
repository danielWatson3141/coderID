#define f first
#define s second
#define INF 1000000000
#define LNF 8000000000000000000
#define mp make_pair
#define ll long long int
#define BL for(int K = 1; K <= T; K++)

#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <deque>
using namespace std;

struct node
{
    vector<int> C;
    int P,S;
};

node V[1010];
int keep[1010];

void dfs(int c)
{
    //printf("dfs(%d)\n",c);

    int i;

    V[c].S = 1;

    for(i = 0; i < V[c].C.size(); i++)
    {
        if(V[c].C[i] != V[c].P)
        {
            V[V[c].C[i]].P = c;
            dfs(V[c].C[i]);
            V[c].S += V[V[c].C[i]].S;
        }
    }
}

int cal(int c)
{
    //printf("cal(%d,%d)\n",c,h);

    if(keep[c] != -1)
    {
        return keep[c];
    }

    int i,j,res = V[c].S - 1;

    if(V[c].P == 0)
    {
        if(V[c].C.size() < 2)
        {
            //printf("cal(%d) = %d\n",c,res);
            return res;
        }
    } else {
        if(V[c].C.size() < 3)
        {
            //printf("cal(%d) = %d\n",c,res);
            return res;
        }
    }

    for(i = 0; i < V[c].C.size(); i++)
    {
        for(j = i + 1; j < V[c].C.size(); j++)
        {
            if(V[c].C[i] != V[c].P && V[c].C[j] != V[c].P)
            {
                //printf("V[%d].S = %d\n",c,V[c].S);

                res = min(res,cal(V[c].C[i]) + cal(V[c].C[j]) + V[c].S - 1 - V[V[c].C[i]].S - V[V[c].C[j]].S);
            }
        }
    }

    //printf("cal(%d) = %d\n",c,res);
    keep[c] = res;
    return res;
}

int main()
{
    int T,n,i,j,k,a,b,res;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);

    BL
    {
        scanf("%d",&n);

        for(i = 1; i <= n; i++)
        {
            V[i].C.clear();
        }

        for(i = 1; i < n; i++)
        {
            scanf("%d%d",&a,&b);

            V[a].C.push_back(b);
            V[b].C.push_back(a);
        }

        int res = INF;

        for(i = 1; i <= n; i++)
        {
            //printf("root = %d\n",i);

            for(j = 1; j <= n; j++)
            {
                V[j].P = 0;
                V[j].S = 0;
            }

            for(j = 1; j <= n; j++)
            {
                keep[j] = -1;
            }

            dfs(i);

            for(j = 1; j <= 9; j++)
            {
                res = min(cal(i),res);
            }
        }

        printf("Case #%d: %d\n",K,res);
    }
}
