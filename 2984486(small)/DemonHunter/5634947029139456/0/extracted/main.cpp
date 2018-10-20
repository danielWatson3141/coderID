#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(arr) memset(arr,0,sizeof(arr))
#define MAX3(a,b,c) max(a,max(b,c))
#define MAX4(a,b,c,d) max(max(a,b),max(c,d))
#define MIN3(a,b,c) min(a,min(b,c))
#define MIN4(a,b,c,d) min(min(a,b),min(c,d))
#define MST(arr,val) memset(arr,val,sizeof(arr))
#define PI acos(-1.0)
#define oo 1000000000
#define loo 1000000000000000000LL
#define eps 1e-8

typedef long long ll;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

struct node
{
    char s[50];
    bool operator < (const node a) const
    {
        return strcmp(s,a.s) < 0;
    }
}tt;

vector<node>now,temp,fin;

int main()
{
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cs = 0,n,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&l);
        now.clear();
        fin.clear();
        REP(i,n)
        {
            scanf("%s",tt.s);
            now.PB(tt);
        }
        REP(i,n)
        {
            scanf("%s",tt.s);
            fin.PB(tt);
        }
        sort(fin.begin(),fin.end());
        int total,ans = oo;
        REP(i,(1<<l))
        {
            temp.clear();
            REP(j,n)
            {
                temp.PB(now[j]);
            }
            total = 0;
            REP(j,10)
            {
                if(i & (1<<j))
                {
                    total++;
                    REP(k,n)
                    temp[k].s[j] = (temp[k].s[j] == '0'?'1':'0');
                }
            }
            sort(temp.begin(),temp.end());
            bool flag = true;
            REP(j,n)
            if(strcmp(temp[j].s,fin[j].s))
            flag = false;
            if(flag) ans = min(ans,total);
        }
        printf("Case #%d: ",++cs);
        if(ans == oo) puts("NOT POSSIBLE");
        else printf("%d\n",ans);
    }
    return 0;
}
