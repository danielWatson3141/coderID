/// ///////////////////// ///
///                       ///
///      Tamanna_24       ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>

typedef long long ll;
typedef unsigned long long ull;

#define pi 2.0*acos(0.0)

template <class T> T _diff(T a,T b) {return (a<b?b-a:a-b);}
template <class T> T _abs(T a) {return(a<0?-a:a);}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T max3(T a, T b, T c) {return (_max(a,b)>c ? _max(a,b) : c);}
template <class T> T min3(T a, T b, T c) {return (_min(a,b)<c ? _min(a,b) : c);}
template< class T>T GCD(T a,T b) {
    a=_abs(a);b=_abs(b);T tmp;while(a%b){ tmp=a%b; a=b; b=tmp; } return b;
}
template< class T>T LCM(T a,T b) {
    a=_abs(a);b=_abs(b);return (a/GCD(a,b))*b;
}
template<class T> T toRad(T deg) { return (deg*pi)/(180.0) ;}
template<class T> T toDeg(T rad) { return (rad*180.0)/(pi) ;}

#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PN() puts("")
#define PCASE() printf("Case %d: ",kk++)
#define eps 1e-9
#define inf 2000000000
#define mod 1000000007
#define MX  1000000
using namespace std;

int l,n;
string s[155],a[155],tmp[155];

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int t,kk=1,i,j,k,res;

    S(t);
    while(t--)
    {
        S(n);S(l);

        for(i=1;i<=n;i++) {cin>>s[i]; tmp[i]=s[i];}
        for(i=1;i<=n;i++) cin>>a[i];

        res=inf;
        sort(a+1,a+n+1);

        bool f;
        j=(1<<l)-1;
        int y;
        for(i=0;i<=j;i++)
        {
            y=0;
            for(k=0;k<l;k++)
            {
                if((i&(1<<k))>0)
                {
                    y++;
                    for(int x=1;x<=n;x++)
                    {
                        if(s[x][k]=='0') tmp[x][k]='1';
                        else tmp[x][k]='0';
                    }
                }
                else for(int x=1;x<=n;x++) tmp[x][k]=s[x][k];
            }
            f=1;
            sort(tmp+1,tmp+1+n);
            for(int x=1;x<=n;x++) {if(tmp[x]!=a[x]) f=0;}

            if(f){res=min(res,y);}

        }
        if(res==inf) printf("Case #%d: NOT POSSIBLE\n",kk++);
        else printf("Case #%d: %d\n",kk++,res);
    }

    return 0;
}












