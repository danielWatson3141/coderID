#define FROM_FILE
//#define TO_FILE

//-Wl,--stack,52800000
#include <bits/stdc++.h>

using namespace std;

#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define All(n) (n).begin(), (n).end()

typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;

#ifdef FROM_FILE
ifstream fin("in.txt");
#define cin fin
#endif

#ifdef TO_FILE
ofstream fout("out.txt");
#define cout fout
#endif

const int MAXN=1000 + 10;
//const int MOD=1000*1000*1000 + 7;
//const lli INF=1000000000000000000ll;


double dp[MAXN][MAXN];
double dp2[MAXN][MAXN];
double pw[MAXN];
double n;

double cdp2(int x,int y)
{
    double& ans=dp2[x][y];
    if(ans>-5)return ans;
    ans=0;
    if(x==y)
        ans+=pw[x];
    for(int i=x-1;i>=0;i--)
    {
        double t=cdp2(i,y)/n;
//        t*=pow((n-1)/n,x-i-1);
        t*=pw[x-i-1];
        ans+=t;
    }
    return ans;
}

double cdp(int x,int y)
{
    double& ans=dp[x][y];
    if(ans>-5)return ans;
    ans=pw[(int)n-x-1]/n;
    for(int i=x+1;i<n;i++)
    {
        double t=cdp2(i,y)/n;
        t*=pw[(int)n-i-1];
        ans+=t;
    }
    return ans;
}

int pp[2000];

int main()
{
	ios::sync_with_stdio(false);
    for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)dp[i][j]=dp2[i][j]=-10;
    n=1000;
    for(int i=0;i<MAXN;i++)
        pw[i]=pow((n-1)/n,i);
//    double avg=0;
//    for(int z=0;z<10000;z++){
//        for(int i=0;i<1000;i++)
//            pp[i]=i;
//        random_shuffle(pp,pp+1000);
//        double dd=0;
//        for(int i=0;i<1000;i++)
//        {
////            if(z==0)
////                cout<<i<<endl;
//            double p=cdp(i,pp[i]);
//            dd+=(1/n)-p;
//        }
//        if(dd>-(8.0/n))
//            cout<<"GOOD";
//        else
//            cout<<"BAD";
////        cout<<endl;
//        avg+=dd;
//        cout<<' '<<dd<<endl;
//    }
//    cout<<avg/10000<<endl;

    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int x;
        cin>>x;
        double dd=0;
        for(int i=0;i<x;i++)
        {
//            if(z==1)
//                cout<<i<<endl;
            int y;
            cin>>y;
            double p=cdp(i,y-1);
            dd+=(1/n)-p;
        }
        cout<<"Case #"<<z<<": ";
        if(dd>-(8.0/n))
            cout<<"GOOD";
        else
            cout<<"BAD";
        cout<<endl;
//        cout<<' '<<dd<<endl;

    }
    return 0;
}
