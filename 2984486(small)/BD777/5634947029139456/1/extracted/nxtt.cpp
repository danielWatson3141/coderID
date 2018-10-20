#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn = 10086;
const ll mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const double PI = atan(1.0) * 4.0;

map<string,int > mp;
char a[160][50],b[160][50],c[160][50];
bool vis[50];
int n,l;

int cmp(int i,int j)
{
    int num = 0;
    int x;
    for(x=0;x<l;x++)
        if(a[i][x] != b[j][x]) vis[x] = true,num++;
    return num;
}

void makeC()
{
    memcpy(c,a,sizeof(c));
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            if(vis[j]){
                c[i][j] = (c[i][j] == '1') ? '0' : '1';
            }
        }
        mp[string(c[i])] ++;
    }
}

bool jud()
{
    int i;
    for(i=0;i<n;i++)
    {

        if(mp[string(b[i])] > 0) mp[string(b[i])] --;
        else return false;
    }
    return true;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.txt","w+",stdout);
    int T;
    int kase = 0;
    scanf("%d",&T);
    while(T--)
    {
        kase ++;
        scanf("%d%d",&n,&l);
        int i,j;
        for(i=0;i<n;i++) scanf("%s",a[i]);
        for(i=0;i<n;i++) scanf("%s",b[i]);
        int ans = inf;
        for(i=0;i<n;i++)
        {
            mp.clear();
            memset(vis,false,sizeof(vis));
            int num = cmp(0,i);
            makeC();
            if(jud()) ans = min(ans, num);
        }
        printf("Case #%d: ",kase);
        if(ans == inf)
        {
            printf("NOT POSSIBLE\n");
        }
        else printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
