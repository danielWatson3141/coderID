/*************************************************************************
  > File Name: pB.cpp
  > Author: rockwyc992
  > Mail: rockwyc992@gmail.com 
  > Created Time: 西元2014年04月26日 (週六) 10時11分57秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T, n;
int from, to;
int min;

std::vector<int>tree[20];
int del(int x, int back)
{
    int ans = 1;
    for(int i=0 ; i<tree[x].size() ; i++)
    {
#define next tree[x][i]
        if(next == back)
        {
            continue;
        }
        ans += del(next, x);
#undef next
    }
    return ans;
}

int check(int x, int back)
{
    int ans = 0;
    if(back == -1)
    {
        if(tree[x].size() == 1)
            return n-1;
        if(tree[x].size() == 3)
        {
            ans = n-1;
            int tmp  = check(tree[x][0], x);
            tmp += check(tree[x][1], x);
            tmp += check(tree[x][2], x);
            for(int i=0 ; i<3 ; i++)
            {
#define next tree[x][i]
                tmp -= check(next, x);
                tmp += del(next, x);
        if (ans > tmp)
            ans = tmp;
                tmp += check(next, x);
                tmp -= del(next, x);
#undef next
    }
        }
    }
    else
    {
        if(tree[x].size() == 2)
        {
            return del(x, back) - 1;
        }
    }
    for(int i=0 ; i<tree[x].size() ; i++)
    {
#define next tree[x][i]
        if(next == back)
        {
            continue;
        }
        ans += check(next, x);
#undef next
    }
    return ans;
}

int main()
{
    scanf("%d", &T);
    for(int t=1 ; t<=T ; t++)
    {
        for(int i=0 ; i<=n ; i++)
            tree[i].clear();
        min = 20;
        scanf("%d", &n);
        for(int i=0 ; i<n-1 ; i++)
        {
            scanf("%d%d", &from, &to);
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        for(int i=1 ; i<=n ; i++)
        {
            int tmp = check(i, -1);
            if(min > tmp)
                min = tmp;
        }
        printf("Case #%d: %d\n", t, min);
    }
    return 0;
}

