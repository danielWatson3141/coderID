
//#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>



#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cerr<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl;
#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define fs           first
#define sc           second
#define pb          push_back
#define ll          long long
#define MP          make_pair
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define ERR         (1e-7)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))



//#define debug(args...)          {dbg,args; cerr<<endl;}
//#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
#define debug(a...)          {cerr<<" #--> ";dbg,a; cerr<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;


const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}
typedef pair<int,int> pii;

//struct T
//{
//    int a,b,c;
//    T(int ai=0,int bi=0,int ci=0)
//    {
//        a = ai;
//        b = bi;
//        c = ci;
//    }
//
//};
//
//bool com(T a,T b)
//{
//    if()    return ;
//    return ;
//}


//typedef double type;
//struct P{
//    type x,y,z;
//    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
//    void scan(){cin>>x>>y>>z;}
//    void scan1(){scanf("%lf%lf%lf",&x,&y,&z);}
//};


//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}

//struct pq{int n,w;
//    pq(int nn=0,int ww=0):n(nn),w(ww){}
//    bool operator<(const pq &b) const{return w<b.w;}
//};

const char z='0',o='1';
const int W = 155;
VS it,sw,tmp;
int nro[W];

int flag()
{
    int n,l,i,j;
    char ar[W];
    string st;

    scanf("%d%d",&n,&l);
    sw.clear();
    it.clear();

    rii(n)
    {
        scanf("%s",ar);
        st = ar;
        sw.pb(st);
    }
    rii(n)
    {
        scanf("%s",ar);
        st = ar;
        it.pb(st);
    }
    sort(all(it));

    int val=2*l;


    for(int msk=0;msk<p2(l);msk++)
    {
        tmp.clear();

        rii(n)  tmp.pb(sw[i]);

        for(i=0;i<l;i++)
        {
            if(EX(msk,i))
            {
                for(j=0;j<n;j++)
                {
                    if(tmp[j][i]==o)
                        tmp[j][i]=z;
                    else tmp[j][i]=o;
                }
            }
        }

        sort(all(tmp));

        int c=0;
        for(i=0;i<n;i++)
            if(tmp[i]==it[i])
                c++;
                else break;
        if(c==n)
        {
            val =min(val,popcount(msk));
        }
    }


    return val>l?-1:val;
}



int main()
{
//    freopen("in.in","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.in","w",stdout);

    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;

    int i,j,k,tks=1,ks=1;


    scanf("%d",&tks);

    while(tks--)
    {
        k = flag();
        if(k>-1)    printf("Case #%d: %d\n",ks++,k);
        else printf("Case #%d: NOT POSSIBLE\n",ks++);
    }




    return 0;
}



