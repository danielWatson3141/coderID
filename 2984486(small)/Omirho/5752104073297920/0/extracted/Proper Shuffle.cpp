#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=0;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf mod

string DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("c.in","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    srand (time(NULL));
    int t;
    cin>>t;
    REP(i,t)
    {
        cout<<"Case #"<<i+1<<": ";
        int a = rand();
        //cout<<a<<endl;
        a%=2;
        if(a==1)
            cout<<"GOOD"<<endl;
        else
            cout<<"BAD"<<endl;
    }
    return 0;
}
