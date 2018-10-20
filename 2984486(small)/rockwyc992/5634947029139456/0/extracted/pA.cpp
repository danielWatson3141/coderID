/*************************************************************************
    > File Name: pA.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 西元2014年04月26日 (週六) 09時24分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T;
int n, l;
long long num[200];
long long tmp[200];
long long goal[200];
int min;

long long get_int(int len)
{
    long long ans = 0;
    char input[50];
    scanf("%s", input);
    for(int i=0 ; i<len ; i++)
    {
        ans = ans*2 + input[i] - '0';
    }
    return ans;
}

int calc(int x)
{
    int ans = 0;
    for(int i=0 ; i<l ; i++)
    {
        if((1<<i) & x)
            ans ++;
    }
    return ans;
}

int check(int x)
{
    for(int i=0 ; i<n ; i++)
    {
        tmp[i] = num[i] ^ x;
    }
    std::sort(tmp, tmp+n);
    for(int i=0 ; i<n ; i++)
        if(tmp[i] != goal[i])
            return 0;
    return 1;
}

int main()
{
    scanf("%d", &T);
    for(int t=1 ; t<=T ; t++)
    {
        min = 50;
        scanf("%d%d", &n, &l);

        for(int i=0 ; i<n ; i++)
            num[i] = tmp[i] = get_int(l);

        for(int i=0 ; i<n ; i++)
            goal[i] = get_int(l);

        std::sort(goal, goal+n);

        for(int i=0 ; i<(1<<l) ; i++)
        {
            if(check(i))
            {
                if(min > calc(i))
                    min = calc(i);
            }
        }
        if(min == 50)
            printf("Case #%d: NOT POSSIBLE\n", t);
        else
            printf("Case #%d: %d\n", t, min);
    }
	return 0;
}

