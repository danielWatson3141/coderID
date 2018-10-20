/*
TASK: Charging Chaos
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
long long si(long long x)
{
    LL sum=0,k=1;
    while(x>0)
    {
        sum+=(k*(x%10));
        k*=2;   x/=10;
    }
    return sum;
}
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("xxx.out","w",stdout);
    int i,j,k;
	scanf("%d",&T);
	int tt=0;
    while(T--)
    {
        scanf("%d%d",&N,&M);
        vector<long long> v,v1,temp;
        long long x,y,z;
        for(i=0;i<N;i++)
        {
            scanf("%I64d",&x);
            v.pb(si(x));
        }
        for(i=0;i<N;i++)
        {
            scanf("%I64d",&x);
            v1.pb(si(x));
        }
        sort(ALL(v));
        sort(ALL(v1));
        int Mc=11111111;
        for(i=0;i<N;i++)
        {
            temp=v;
            k=0;
            for(j=0;j<M;j++)
            {
                if((v1[0]&(1LL<<j))!=(temp[i]&(1LL<<j)))
                {
                    k++;
                    for(int a=0;a<N;a++)
                    {
                        temp[a]^=(1LL<<j);
                    }
                }
            }
            sort(ALL(temp));
            bool ok=true;
            for(j=0;j<N;j++)
                if(temp[j]!=v1[j])
                {
                    ok=false;
                    break;
                }
            if(ok)
                Mc=min(Mc,k);
        }
        tt++;
        if(Mc==11111111)
            printf("Case #%d: NOT POSSIBLE\n",tt);
        else
            printf("Case #%d: %d\n",tt,Mc);
        //cout << (1LL<<40) << endl;
    }
}
