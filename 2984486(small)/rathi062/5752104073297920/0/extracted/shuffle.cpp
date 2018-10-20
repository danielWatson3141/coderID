#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 10000
#define MOD 1000002013

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getcx();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
 n=n*sign;
 }*/


using namespace std;
int cnt,n,l;
int s[MX],idx[MX];
bool check;
int main()
{
    int t=0;
    inp(t);
    for(int i =1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        inp(n);
        for(int j=0;j<n;j++)
        {
            cin>>s[j];
            idx[j]=j;
        }
        int val=0;
        check=0;
        for(int j=0;j<n;j++)
        {
            val= s[j];
            for(int k=j;k<n;k++)
            {
                if(val==idx[k])
                {
                    check =1;
                    idx[k]=idx[j];
                    idx[j]=val;
                    break;
                }
            }
        }
        if(check)
        cout<<"BAD\n";
        else
        cout<<"GOOD\n";
    }
    return 0;
}