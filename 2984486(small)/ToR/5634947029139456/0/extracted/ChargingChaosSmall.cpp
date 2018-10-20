#define f first
#define s second
#define INF 2000000000
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

string out[160],dev[160];
int outc[50][2],devc[50][2];

int HWI(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,n,l,i,j,k,sum,res;
    bool imp;

    scanf("%d",&T);

    BL
    {
        scanf("%d%d",&n,&l);

        for(i = 0; i < n; i++)
        {
            cin >> out[i];
        }

        for(i = 0; i < n; i++)
        {
            cin >> dev[i];
        }

        sort(dev,dev + n);

        res = INF;

        for(i = 0; i < (1 << l); i++)
        {
            for(j = 0; j < l; j++)
            {
                if(i & (1 << j))
                {
                    for(k = 0; k < n; k++)
                    {
                        (out[k][j] == '0')? out[k][j] = '1': out[k][j] = '0';
                    }
                }
            }

            sort(out,out + n);

            for(j = 0; j < n; j++)
            {
                if(out[j].compare(dev[j]) != 0)
                {
                    break;
                }
            }

            if(j == n)
            {
                res = min(res,HWI(i));
            }

            for(j = 0; j < l; j++)
            {
                if(i & (1 << j))
                {
                    for(k = 0; k < n; k++)
                    {
                        (out[k][j] == '0')? out[k][j] = '1': out[k][j] = '0';
                    }
                }
            }
        }

        if(res == INF)
        {
            printf("Case #%d: NOT POSSIBLE\n",K);
        } else {
            printf("Case #%d: %d\n",K,res);
        }
    }
}
