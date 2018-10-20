#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

bool check(string src[], string tar[], int n)
{
    sort(src, src+n);
    sort(tar, tar+n);
    for (int i = 0; i < n; ++i)
        if (src[i] != tar[i])
            return false;
    return true;
}

int dfs(string src[], string tar[], int n, int l, int index)
{
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    if (index >= l)
    {
        if (check(src, tar, n))
            return 0;
        return -1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (src[i][index] == '0') cnt1++;
        if (tar[i][index] == '0') cnt2++;
    }
    int ans1 = -1;
    int ans2 = -1;
    if (cnt1 == cnt2)
    {
        ans1 = dfs(src,tar,n,l,index+1);
    }
    if(cnt1 + cnt2 == n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (src[i][index] == '0')
                src[i][index] = '1';
            else
                src[i][index] = '0';
        }
        ans2 = dfs(src,tar,n,l,index+1);
        for (int i = 0; i < n; ++i)
        {
            if (src[i][index] == '0')
                src[i][index] = '1';
            else
                src[i][index] = '0';
        }
    }
    if(ans1 == -1 && ans2 == -1)
        return -1;
    if (ans1 >= 0 && ans2 >= 0)
        return min(ans1,ans2+1);
    else
        return max(ans1, ans2+1);
}
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.in.txt", "w", stdout);
    int T,ii;
    string src[160];
    string tar[160];
    bool visited[100];
    cin>>T;
    for (ii = 1; ii <= T; ++ii)
    {
        int n,l;
        cin>>n>>l;
        for (int i = 0; i < n; ++i)
            cin>>src[i];
        for (int i = 0; i < n; ++i)
            cin>>tar[i];
        memset(visited,0,sizeof(visited));
        int ans = dfs(src,tar,n,l,0);

        if (ans == -1)
        {
            printf("Case #%d: NOT POSSIBLE\n", ii);
        }
        else
            printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}
