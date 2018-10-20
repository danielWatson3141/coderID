#define DeBUG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <bitset>
using namespace std ;
#define zero {0}
#define INF 0x3f3f3f3f
#define EPS 1e-6
typedef long long LL;
const double PI = acos(-1.0);
//#pragma comment(linker, "/STACK:102400000,102400000")
inline int sgn(double x)
{
    return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}
bool it[1000][1000];
bool it2[1000][1000];
int n, l;
int minn;
vector<string>des;
vector<string>now;
bool ju()
{
    for (int i = 0; i < n; i++)
    {
        if (des[i] != now[i])
            return false;
    }
    return true;
}
void dfs(int i, int t)
{
    if (i < l)
    {
        for (int j = 0; j < n; j++)
        {
            it[j][i] = !it[j][i];
        }
        dfs(i + 1, t + 1);
        for (int j = 0; j < n; j++)
        {
            it[j][i] = !it[j][i];
        }
        dfs(i + 1, t);
    }
    else
    {
        // printf("%dtime\n", t);
        now.clear();
        for (int j = 0; j < n; j++)
        {
            char ss[1000] = zero;
            for (int k = 0; k < l; k++)
            {
                // printf("%d", it[j][k]);
                if (it[j][k])
                    ss[k] = '1';
                else
                    ss[k] = '0';
            }
            // printf("\n");
            now.push_back(string(ss));
        }
        sort(now.begin(), now.end());
        if (ju())
        {
            minn = min(minn, t);
        }
        // puts("");
    }
}
int cnt=1;
int main()
{
#ifdef DeBUGs
    freopen("C:\\Users\\Sky\\Desktop\\A-small-attempt0.in", "r", stdin);
    freopen("C:\\Users\\Sky\\Desktop\\A-small-attempt0.out","w",stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char s[1000];
        minn = INF;
        scanf("%d%d", &n, &l);
        memset(it, 0, sizeof(it));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            for (int j = 0; j < l; j++)
            {
                if (s[j] == '1')
                    it[i][j] = 1;
            }
        }
        des.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            des.push_back(string(s));
        }
        sort(des.begin(), des.end());
        dfs(0, 0);
        if (minn != INF)
            printf("Case #%d: %d\n", cnt++, minn);
        else

            printf("Case #%d: NOT POSSIBLE\n", cnt++);
    }


    return 0;
}
