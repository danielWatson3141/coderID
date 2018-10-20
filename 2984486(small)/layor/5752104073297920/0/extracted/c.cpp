/*
 * File Name: c.cpp
 * Create Time: 11:12:47,星期六, 26 四月 2014.
 * Author: qqspeed
 */

#include<algorithm>
#include<bitset>
#include<deque>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<limits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<vector>
#include<complex>
using namespace std;

#define FOR(i,b,e) for(__typeof(b)i=(b);i!=(e);i++)
#define FOR_EACH(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define rep(i,s,t) for(int i=s;i<t;i++)
#define INF ~0U>>2
#define L t<<1
#define	R t<<1|1
#define PI acos(-1.0)
#define clr(a) memset(a,0,sizeof(a))
typedef complex<double>Com;
typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;

inline void DATA(char *s,char *d){
    freopen(s,"r",stdin);
    freopen(d,"w",stdout);
}

inline int input(){
    int ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';c=getchar();
    }
    return isN?-ret:ret;
}

inline void output(int x){
    if(x<0){
        putchar('-');x=-x;
    }
    int len=0,data[10];
    while(x){
        data[len++]=x%10;x/=10;
    }
    if(!len)	data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}

int t,n,a[1010],b[1010];
int main() {
    //ios::sync_with_stdio(false);
    DATA("C-small-attempt4.in","c.out");
    t=input();
    rep(ca,1,t+1){
        n=input();
        rep(i,0,n) a[i]=input();
        int ans=0;
        rep(tt,0,10000){
            rep(i,0,n) b[i]=i;
            rep(i,0,n){
                int p=i+rand()%(n-i);
                if(p>=n) p=n-1;
                swap(b[p],b[i]);
            }
            int tag=0;
            rep(i,0,n){
                if(a[i]!=b[i]){
                    tag++;
                }
            }
            if(tag&1){
                ans=1;break;
            }
        }
        if(ans)
            printf("Case #%d: BAD\n",ca);
        else printf("Case #%d: GOOD\n",ca);
    }
    return 0;
}
