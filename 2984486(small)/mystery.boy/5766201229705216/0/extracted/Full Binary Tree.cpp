/*
TASK: Full Binary Tree
LANG: C++
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
using namespace std;
#define X first
#define Y second
#define EPS 1e-9
#define ALL(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back((x))
#define FOR(i,st,ed) for(int (i)=(st);(i)<(ed);(i)++)
typedef pair<int,int> PII;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long LL;

int N,M,T;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("xxx.out","w",stdout);
    int i,j,k;
	scanf("%d",&T);
	int tb[20];
	int a,b,c,tt=0;
    while(T--)
    {
        // bad
        scanf("%d",&N);
        memset(tb,0,sizeof tb);
        vi v[20];
        for(i=1;i<N;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].pb(b);
            v[b].pb(a);
        }
        int Mc=111;
        for(i=0;i<(1<<N);i++)
        {
            memset(tb,0,sizeof tb);
            k=0;
            for(j=0;j<N;j++)
            {
                if((1<<j)&i)
                {
                    k++;
                    tb[j+1]=-1;
                }
            }
            while(true)
            {
                bool me=false;
                for(j=1;j<=N;j++)
                {
                    if(tb[j]==0)
                    {
                        b=0;
                        for(a=0;a<v[j].size();a++)
                        {
                            if(tb[v[j][a]]==0)
                                b++;
                        }
                        if(b==2)
                        {
                            me=true;
                            tb[j]=1;
                        }
                    }
                }
                if(!me) break;
            }
            bool ok_=true;
            for(j=1;j<=N;j++)
            {
                if(tb[j]==0)
                {
                    b=0;
                    for(a=0;a<v[j].size();a++)
                    {
                        if(tb[v[j][a]]==0)
                            b++;
                    }
                    if(b!=0)
                        ok_=false;
                }
            }
            int numm=0;
            for(j=1;j<=N;j++)
            {
                if(tb[j]!=-1 && tb[j]!=3)
                {
                    numm++;
                    queue<int> Q;
                    Q.push(j);
                    while(!Q.empty())
                    {
                        a=Q.front();
                        Q.pop();
                        tb[a]=3;
                        for(b=0;b<v[a].size();b++)
                        {
                            if(tb[v[a][b]]!=3 && tb[v[a][b]]!= -1)
                            {
                                tb[v[a][b]]=3;
                                Q.push(v[a][b]);
                            }
                        }
                    }
                }
            }
            if(ok_ && numm==1)
            {
                Mc=min(Mc,k);
//                for(j=1;j<=N;j++)
//                    printf("%d ",tb[j]);
//                printf("\n");
            }
        }
        tt++;
        printf("Case #%d: %d\n",tt,Mc);
    }
}
