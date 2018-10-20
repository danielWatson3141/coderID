#line 2 "TorusSailing.cpp"
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int N,L;

char in[256][64],out[256][64];
LL a[256],b[256];

bool mp[160][160];
LL diff[160][160];
bool flag[160][160];

int pa[160];
bool used[160];
void init()
{
    memset(pa,-1,sizeof(pa));
}
bool dfs(int x)
{
    if(used[x]) return false;
    used[x]=true;
    for(int i=0;i<N;i++)
    {
        if(mp[x][i])
        {
            if(pa[i]==-1||dfs(pa[i]))
            {
                pa[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int casT;
        scanf("%d",&casT);
        for(int cas=1;cas<=casT;cas++)
        {
            scanf("%d%d",&N,&L);
            for(int i=0;i<N;i++) scanf("%s",in[i]);
            for(int i=0;i<N;i++) scanf("%s",out[i]);

            for(int i=0;i<N;i++)
            {
                a[i]=0;
                b[i]=0;
                for(int j=0;j<L;j++)
                {
                    if(in[i][j]=='1')  a[i]|=1LL<<j;
                    if(out[i][j]=='1') b[i]|=1LL<<j;
                }
            }

            for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                diff[i][j]=a[i]^b[j];
            }
            memset(flag,0,sizeof(flag));

            int ans=10000;
            int goin=0;
            for(int ii=0;ii<N;ii++)
            for(int jj=0;jj<N;jj++)
            {
                if(!flag[ii][jj])
                {
                    goin++;
                    memset(mp,0,sizeof(mp));
                    for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                    {
                        if(diff[i][j]==diff[ii][jj]) flag[i][j]=mp[i][j]=true;
                    }
                    init();
                    int sum=0;
                    for(int k=0;k<N;k++)
                    {
                        memset(used,0,sizeof(used));
                        if(dfs(k))
                        {
                            sum++;
                        }
                        else break;
                    }
                    if(sum==N)
                    {
                        int cnt=0;
                        for(int bit=0;bit<L;bit++) if((1LL<<bit)&diff[ii][jj]) cnt++;
                        ans=min(cnt,ans);
                    }
                }
            }
            //cout<<goin<<endl;
            if(ans<1000) printf("Case #%d: %d\n",cas,ans);
            else printf("Case #%d: NOT POSSIBLE\n",cas);
        }

        return 0;
}

