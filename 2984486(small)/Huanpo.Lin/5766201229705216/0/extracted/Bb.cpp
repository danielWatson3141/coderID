#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 50;
int deleteFlag, N, visited, V;
bool used[MAXN];
vector <int> adja[MAXN];

bool check(int now)
{
    int children = 0;
    used[now] = true;
    visited++;
    for(int i = 0; i < adja[now].size(); i++)
    {
        int nextv = adja[now][i];
        int f = ( 1 << (nextv-1) );
        if(f & deleteFlag) continue; //deleted

        if(used[ nextv ] == false)
        {
            ++children;
            if(check( nextv ) == false) return false;
        }

//        if(children > 2) return false;
    }


    return (children == 0) || (children == 2);
}

int main()
{
    int TC;
    scanf("%d", &TC);

    for(int tc = 1; tc <= TC; tc++)
    {
        scanf("%d", &N);
        V = 0;
        for(int i = 0; i < MAXN; i++)
            adja[i].clear();

        for(int i = 1; i < N; i++)
        {
            int f , t;
            scanf("%d%d", &f, &t);
            V = max(V, f);
            V = max(V, t);
            adja[f].push_back( t );
            adja[t].push_back( f );
        } 

        int upper = (1<<V), theMin = 1000;
        deleteFlag = 0;
        while(deleteFlag < upper)
        {
            bool checked = false;
            
            int res = 0;
            for(int i = 0; i < V; i++)
                if( (1<<i) & deleteFlag)
                    ++res;
            for(int i = 1; i <= V; i++)
            {
                memset(used, 0, sizeof(used));
                visited = 0;
                if(check( i ))
                {
                    if(res + visited == V)
                    {
                        checked = true;
                        break;
                    }
                }
            }

            if(checked)
            {
                theMin = min(theMin, res );
            }
            ++deleteFlag;
        }
        printf("Case #%d: %d\n", tc, theMin);
    }

    return 0;
}
