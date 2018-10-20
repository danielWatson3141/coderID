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
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define pb push_back
#define clean(a,b) memset(a,b,sizeof(a))
#define oo 1<<20
#define dd double
#define ll long long
#define ull unsigned long long
#define ff float
#define EPS 10E-6
#define fr first
#define sc second
#define MAXX 100100
#define PRIME_N 1000000
#define INFI 1<<30
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define MODD 1000000007

//int rx[] = {0,-1,0,1,1,-1,-1,0,1}; //four direction x
//int ry[] = {0,1,1,1,0,0,-1,-1,-1};   //four direction y
//int rep[] = {1,1,4,4,2,1,1,4,4,2}; //repet cycle for mod
//void ullpr(){printf("range unsigned long long : %llu\n",-1U);} //for ull
//void ulpr(){printf("range unsigned long : %lu\n",-1U);} //for ull
//void upr(){printf("range unsigned : %u\n",-1U);} //for ull

namespace matching
{
    typedef int val_t;
    const int SIZE = 200;
    int v1, v2;
    vector<int> graph[SIZE];
    int mx[SIZE], my[SIZE];
    int total_matching;
    int dist[SIZE];
    int inf_dist;
    void reset()
    {
        for(int i = 0  ; i<SIZE ; i++)
            graph[i].clear();
    }
    bool bfs()
    {
        int x, y;
        queue<int> q;
        for (x = 0 ; x < v1 ; x++)
        {
            if (mx[x] == -1)
            {
                dist[x] = 0;
                q.push(x);
            }
            else
                dist[x] = -1;
        }
        bool flg = false;
        while (!q.empty())
        {
            x = q.front();
            q.pop();
            for (int i = 0 ; i < graph[x].size() ; i++)
            {
                y = graph[x][i];
                if (my[y] == -1)
                {
                    inf_dist = dist[x] + 1;
                    flg = true;
                }
                else if (dist[my[y]] == -1)
                {
                    dist[my[y]] = dist[x] + 1;
                    q.push(my[y]);
                }
            }
        }
        return flg;
    }
    bool dfs(int x)
    {
        if (x == -1) return true;
        for (int i = 0 ; i < graph[x].size() ; i++)
        {
            int y = graph[x][i];
            int tmp = (my[y] == -1) ? inf_dist : dist[my[y]];
            if (tmp == dist[x] + 1 && dfs(my[y]))
            {
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
        dist[x] = -1;
        return false;
    }
    int hopcroft()
    {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        total_matching = 0;
        while (bfs())
        {
            for (int x = 0 ; x < v1 ; x++)
                if (mx[x] == -1 && dfs(x))
                    total_matching++;
        }
        return total_matching;
    }
} // namespace matching


vector<string>vOut;
vector<string>vDev;

int bpm(int o,int d,string mask)
{
    matching::reset();
    matching::v1 = SZ(vOut);
    matching::v2 = SZ(vOut);

    for(int i = 0 ; i<SZ(vOut) ; i++)
    {
        for(int j = 0 ; j<SZ(vDev) ; j++)
        {
            if(i==o || j==d) continue;

            int ok = 1;

            for(int k = 0; k<SZ(vOut[i]) ; k++)
            {
                if(vOut[i][k]==vDev[j][k] && mask[k]=='0') continue;
                if(vOut[i][k]!=vDev[j][k] && mask[k]=='1') continue;
                ok = 0;
                break;
            }
            if(ok)
            {
                matching::graph[i].pb(j);
            }
        }
    }

    int match = matching::hopcroft();

    if(match==(SZ(vDev)-1)) return 1;
    return 0;
}

int main()
{
    freopen("inpas.txt" , "r+" , stdin);
    freopen("outas.txt" , "w+" , stdout);

    int tcase,cas=1;

    scanf(" %d" ,&tcase);
    while(tcase--)
    {
        int n,l;

        vOut.clear();
        vDev.clear();

        scanf(" %d %d" ,&n,&l);
        string str;
        for(int i = 0 ;i<n ; i++)
        {
            cin>>str;
            vOut.pb(str);
        }

        for(int i = 0; i<n ; i++)
        {
            cin>>str;
            vDev.pb(str);
        }

        int sol = -1;
        str = string(l , '0');

        for(int i = 0; i<n ; i++)
            for(int j = 0;  j<n ; j++)
        {
            string tmp(l , '0');
            int cnt = 0;
            for(int k = 0 ; k<l ; k++)
            {
                if(vOut[i][k]!=vDev[j][k])
                {
                    tmp[k] = '1';
                    cnt++;
                }
            }
            //cout<<tmp<<endl;
            int retval = bpm(i, j, tmp);
            //cout<<" ret "<< retval<<endl;
            if(retval)
            {
                if(sol==-1 || sol>cnt) sol = cnt;
            }
        }

        printf("Case #%d: ",cas++);
        if(sol!=-1)
            printf("%d\n",sol);
        else printf("NOT POSSIBLE\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
