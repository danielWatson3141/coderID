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
#define MX 151
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
string s[MX],rq[MX],ns[MX];
bool chng[50];
void flip(int j,int k)
{
    cnt=0;
    for(int i=0;i<l;i++)
    {
        if(s[j][i]!=rq[k][i])
        {
            cnt++;
            chng[i]=1;
        }
    }
}
char swp(char c)
{
    if(c=='0') return '1';
    else return '0';
}
void assign(void)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(chng[j])
            ns[i][j]=swp(s[i][j]);
            else
            ns[i][j]=s[i][j];
        }
    }
}

bool match()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(ns[i][j]!=rq[i][j])
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t=0;
    inp(t);
    for(int i =1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        inp(n);
        inp(l);
        for(int j=0;j<n;j++)
        {
            cin>>s[j];
            ns[j]=s[j];
        }
        for(int j=0;j<n;j++)
        {
            cin>>rq[j];
        }
        sort(rq,rq+n);
        int mini = 50;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                for(int p=0;p<l;p++)
                chng[p]=0;
                
                flip(j,k);
                if(cnt<mini)
                {
                    assign();
                    sort(ns,ns+n);
                    if(match())
                    mini = cnt;
                }
            }
        }
        if(mini!=50)
        cout<<mini<<endl;
        else
        cout<<"NOT POSSIBLE\n";
    }
    return 0;
}