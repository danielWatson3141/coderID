/*************************************************************************
	> File Name: Charging_Chaos.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年04月26日 星期六 09时04分32秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node
{
    vector<int> data;
    int step;
};

void input(int, vector<int> &);

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        int n, l;
        scanf("%d %d", &n, &l);
        
        vector<int> init, fin;

        input(n, init);
        input(n, fin);
        
        std::sort(fin.begin(), fin.end());

        Node beg = {init, 0};
        set< vector<int> > S;
        queue<Node> Q;
        int min_step = -1;

        S.insert(init);
        Q.push(beg);

        while(!Q.empty())
        {
            Node top = Q.front();
            Q.pop();

            vector<int> a(top.data);
            std::sort(a.begin(), a.end());

            if(a == fin)
            {
                min_step = top.step;
                break;
            }

            for(int i = 0; i < l; i++)
            {
                vector<int> newV(top.data);

                for(int j = 0; j < n; j++)
                    newV[j] ^= (1 << i);

                if(!S.count(newV))
                {
                    S.insert(newV);
                    Node newNode = {newV, top.step + 1};
                    Q.push(newNode);
                }
            }
        }

        if(min_step == -1)
            printf("Case #%d: NOT POSSIBLE\n", t);
        else
            printf("Case #%d: %d\n", t, min_step);
    }
    return 0;
}

void input(int n, vector<int> &v)
{
    for(int i = 0; i < n; i++)
    {
        int base = 1, res = 0;
        char str[100] = {0}, *p = str;

        scanf("%s", str);
        while(*p)
        {
           res += ((*p) - '0') * base;
           base *= 2;
           p++;
        }
        
        v.push_back(res);
    }
}

